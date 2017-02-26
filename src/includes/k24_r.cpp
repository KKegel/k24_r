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

    std::cout << "generate base pattern ... " << std::flush;

    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){

            int r = std::rand() % 20;
            if( r < 2){
                color = c_h.random_color(seed, v.BLACK);
            }else if( r < 7){
                color = c_h.random_color(seed, v.WHITE);
            }else if( r < 9){
                color = c_h.random_color(seed, v.GREY);
            }else {
                color = c_h.random_color(seed, v.COLOR);
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

            std::cout << "transform x ... " << std::flush;
            smoth_x(data, &c_h, v);
            std::cout << "finished" << std::endl;

            std::cout << "transform y ... " << std::flush;
            smoth_y(data, &c_h, v);
            std::cout << "finished" << std::endl;

            v.SCATTERING = 0;
        }

    }

    //remove single pixels (make bmp more homogeneous)

    remove_single_dots(data, &c_h, v);

    //smoth again

    int i = 0;
    int reps = rand() % 75;
    std::cout << "repetitions: " << reps << std::endl;

    while (i < reps) {

        std::cout << "transform x & y lines - revision: " << i << " of " << reps << std::endl;

        std::cout << "start transform x ... " << std::flush;
        smoth_x(data, &c_h, v);
        std::cout << "finished" << std::endl;

        std::cout << "start transform y ... " << std::flush;
        smoth_y(data, &c_h, v);
        std::cout << "finished" << std::endl;

        i++;
    }

    //manipulate brightness

    std::cout << "get brightness average ... " << std::flush;
    int average_bright = c_h.brightness_average(data);
    std::cout << "average = " << average_bright << " ... finished" << std::endl;

    std::cout << "get max color average ... " << std::flush;
    int max_color = c_h.max_bright_pix_average(data);
    std::cout << "average = " << max_color << " ... finished" << std::endl;

    std::cout << "transform brightness ... " << std::flush;
    scale_brightness(data, 50, 50, 50, &c_h, v);
    std::cout << "finished" << std::endl;

    std::cout << "transform colors ... " << std::flush;
    clean_colors(data, 20, 15, -35, 20, &c_h, v);
    std::cout << "finished" << std::endl;

    std::cout << "clear stack" << std::endl;
    c_h.clear_stack();

    std::cout << "rebuild stack" << std::endl;
    c_h.index(data);

    std::cout << "start rcdbl subroutine ... " << std::endl;
    replace_colors(data, c_h.get_colors_by_likelihood(0, (10000/reps*5)), &c_h, v);
    std::cout << "... completed" << std::endl;

    return reps;
}

