//
// Created by Karl Kegel on 15.02.17.
//

#include "../header/k24_r.h"

int generate(unsigned char *data){

    color_handler c_h;
    values v;
    c_h.init(&v);

    std::array<unsigned char, 3> color;

    int seed = 0;

    //4x4 base pattern:

    std::cout << "generate base pattern... " << std::flush;

    int color1 = (std::rand() % 6) + 10;
    int color2 = c_h.get_complement_color(color1);

    double rela1 = c_h.get_color_relation(color2, color1);
    double rela2 = 1 - rela1;

    int fac_1 = (int) rela1 * 12;
    int fac_2 = (int) rela2 * 12;

    int c[16];

    int cc1 = 0, cc2 = 0;

        int i = 0;

        while(i < 16){

            int k = (std::rand() % 12) - rela2;

            if(i == 6 && (cc1 < 2 || cc2 < 2)) {

                if (cc1 < 2) {
                    c[i] = color1;
                    cc1++;
                } else {
                    c[i] = color2;
                    cc2++;
                }

            }else if(i == 8 && (cc1 < 3 || cc2 < 3)){

                if(cc1 < 3){
                    c[i] = color1;
                    cc1++;
                }else{
                    c[i] = color2;
                    cc2++;
                }

            }else if(i == 10 && (cc1 < 4 || cc2 < 4)){

                if(cc1 < 4){
                    c[i] = color1;
                    cc1++;
                }else{
                    c[i] = color2;
                    cc2++;
                }

            }else if(i == 13 && (cc1 < 5 || cc2 < 5)){

                if(cc1 < 5){
                    c[i] = color1;
                    cc1++;
                }else{
                    c[i] = color2;
                    cc2++;
                }

            }else {

                if (k >= 0) {
                    c[i] = color1;
                    cc1++;
                } else {
                    c[i] = color2;
                    cc2++;
                }
            }
            i++;
        }

    std::cout << "color 1: " << color1 << std::endl;
    std::cout << "color 2: " << color2 << std::endl;
    std::cout << "relation 1: " << rela1 << std::endl;

    i = 0;

    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){

            int r = std::rand() % 20;
            if( r < 2){
                color = c_h.random_color(seed, v.BLACK);
            }else if( r < 6){
                color = c_h.random_color(seed, v.WHITE);
            }else if( r < 8){
                color = c_h.random_color(seed, v.GREY);
            }else{
                color = c_h.hue(c[i]);
                i++;
            }

            fill_rect(data, v.PHW / 4 * x, v.PHW / 4, v.PHW / 4 * y, v.PHW / 4, color[0], color[1], color[2], v);
            c_h.add_to_stack(color[0], color[1], color[2]);
        }
    }

    std::cout << "finished" << std::endl;

    //split pattern:

    int resolution = 8;

    while (v.PHW % (resolution * 2) == 0){

        redouble_resolution(data, resolution, &c_h, v); //std::cout lines are function intern.
        resolution *= 2;

        if(resolution == 32){

            //smooth

            std::cout << "scale and transform x... " << std::endl;
            smoth_x(data, &c_h, v);
            std::cout << "...finished" << std::endl;

            std::cout << "scale and transform y... " << std::endl;
            smoth_y(data, &c_h, v);
            std::cout << "...finished" << std::endl;

            v.SCATTERING = 0;
        }

    }

    //remove single pixels (make bmp more homogeneous)

    remove_single_dots(data, &c_h, v);

    //smoth again

    i = 0;
    int reps = (rand() % 50) + 20;
    std::cout << "repetitions: " << reps << std::endl;

    while (i < reps) {

        std::cout << "...start subroutine SLBR x & y lines - revision: " << i << " of " << (reps - 1) << std::endl;

        std::cout << "start transform x... " << std::endl;
        smoth_x(data, &c_h, v);
        std::cout << "...finished" << std::endl;

        std::cout << "start transform y... " << std::endl;
        smoth_y(data, &c_h, v);
        std::cout << "...finished" << std::endl;

        i++;
    }

    //manipulate brightness

    std::cout << "get brightness byte average... " << std::flush;
    int average_bright = c_h.brightness_average(data);
    std::cout << "average = " << average_bright << " ...finished" << std::endl;

    std::cout << "get max. bright color byte average... " << std::flush;
    int max_color = c_h.max_bright_pix_average(data);
    std::cout << "average = " << max_color << " ...finished" << std::endl;

    std::cout << "adjust brightness... " << std::flush;
    scale_brightness(data, 70, 70, 70, &c_h, v);
    std::cout << "finished" << std::endl;

    std::cout << "adjust color values... " << std::flush;
    clean_colors(data, 30, 25, -55, 20, &c_h, v);
    std::cout << "finished" << std::endl;

    std::cout << "clear stack" << std::endl;
    c_h.clear_stack();

    std::cout << "rebuild stack" << std::endl;
    c_h.index(data);

    std::cout << "start RCDBL subroutine... " << std::endl;
    replace_colors(data, c_h.get_colors_by_likelihood(0, (10000/reps*5)), &c_h, v);
    std::cout << "...completed" << std::endl;

    remove_single_dots(data, &c_h, v);

    //more brightness and contrast

    std::cout << "clear stack" << std::endl;
    c_h.clear_stack();

    std::cout << "rebuild stack" << std::endl;
    c_h.index(data);

    std::cout << "optimize colors - part 1..." << std::endl;
    c_h.optimize_color(data, color1);
    std::cout << "optimize colors - part 2..." << std::endl;
    c_h.optimize_color(data, color1);
    std::cout << "...finished" << std::endl;

    return reps;
}

