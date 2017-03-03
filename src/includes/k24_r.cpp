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

    std::cout << "generate base pattern... " << std::endl;

    int color1 = (std::rand() % 6) + 10;
    int color2 = c_h.get_complement_color(color1);

    double rela1 = c_h.get_color_relation(color2, color1);
    double rela2 = 1 - rela1;

    int fac_1 = (int) (rela1 * 12);
    int fac_2 = (int) (rela2 * 12);

    std::cout << "color 1: " << color1 << std::endl;
    std::cout << "color 2: " << color2 << std::endl;
    std::cout << "relation 1: " << rela1 << std::endl;

    int i = 0;

    int c_white = 0;
    int c_black = 0;

    int c_vals[16];

    i = 0;
    while(i < 16){

            int r = std::rand() % 20;

            if( r < 2){

                if(c_black <= 1) {
                    c_vals[i] = v.BLACK;
                    c_black++;
                }else{
                    i--;
                }

            }else if( r < 6){

                if(c_white <= 2) {
                    c_vals[i] = v.WHITE;
                    c_white++;
                }else{
                    i--;
                }

            }else if( r < 8){

                c_vals[i] = v.GREY;

            }else if( r < 8 + fac_1){

                c_vals[i] = color1;

            }else{

                c_vals[i] = color2;
            }

            i++;
    }

    int r_az_col1 = 0;
    int r_az_col2 = 0;

    for(int k = 0; k < 16; k++){

        if(c_vals[k] == color1){
            r_az_col1++;
        }else if(c_vals[k] == color2){
            r_az_col2++;
        }
    }

    std::cout << "amount color 1: " << r_az_col1 << std::endl;
    std::cout << "amount color 2: " << r_az_col2 << std::endl;

    int diff_col1 = r_az_col1 - fac_1;
    int diff_col2 = r_az_col2 - fac_2;

    i = 0;

    while(i > (diff_col1 + 1) || r_az_col1 == 0){
        int r = (std::rand() % 16);
        c_vals[r] = color1;
        r_az_col1++;
        i--;
    }

    i = 0;
    while(i > (diff_col2 + 1) || r_az_col2 == 0){
        int r = (std::rand() % 16);
        c_vals[r] = color2;
        r_az_col2++;
        i--;
    }

    r_az_col1 = 0;
    r_az_col2 = 0;

    for(int k = 0; k < 16; k++){

        if(c_vals[k] == color1){
            r_az_col1++;
        }else if(c_vals[k] == color2){
            r_az_col2++;
        }
    }

    diff_col1 = r_az_col1 - fac_1;
    diff_col2 = r_az_col2 - fac_2;

    int s_exec = 0;

    while(i < (diff_col1 - 1) || r_az_col1 == 0){
        int r = (std::rand() % 16);
        if(c_vals[r] == color1) {
            r_az_col1--;
            i+=2;
            c_vals[r] = color2;
        }
        s_exec++;
        if(s_exec >= 1000){
            break;
        }
    }

    s_exec = 0;
    i = 0;

    while(i < (diff_col2 + 1) || r_az_col2 == 0){
        int r = (std::rand() % 16);
        if(c_vals[r] == color2) {
            r_az_col2--;
            i+=2;
            c_vals[r] = color1;
        }
        s_exec++;
        if(s_exec >= 1000){
            break;
        }
    }

    i = 0;

    for(int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {

            if(c_vals[i] == v.BLACK){
                color = c_h.random_color(seed, v.BLACK);
            }else if(c_vals[i] == v.GREY){
                color = c_h.random_color(seed, v.WHITE);
            }else if(c_vals[i] == v.WHITE){
                color = c_h.random_color(seed, v.WHITE);
            }else if(c_vals[i] == color1){
                color = c_h.hue(color1);
            }else{
                color = c_h.hue(color2);
            }

            fill_rect(data, v.PHW / 4 * x, v.PHW / 4, v.PHW / 4 * y, v.PHW / 4, color[0], color[1], color[2], v);
            c_h.add_to_stack(color[0], color[1], color[2]);

            i++;
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
    int reps = (rand() % 35) + 35;
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
    int bright_plus = 150 - average_bright;
    scale_brightness(data, bright_plus, bright_plus, bright_plus, &c_h, v);
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

