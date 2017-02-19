//
// Created by Karl Kegel on 15.02.17.
//

#include "../header/k24_r.h"

bool generate(unsigned char *data){

    color_handler c_h;
    values v;
    c_h.init(&v);

    std::array<unsigned char, 3> color;

    int seed = 0;

    //4x4 base pattern:

    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){

            int r = std::rand() % 20;
            if( r < 2){
                color = c_h.random_color(seed, v.BLACK);
            }else if( r < 10){
                color = c_h.random_color(seed, v.WHITE);
            }else if( r < 11){
                color = c_h.random_color(seed, v.GREY);
            }else {
                color = c_h.random_color(seed, v.COLOR);
            }

            fill_rect(data, v.PHW / 4 * x, v.PHW / 4, v.PHW / 4 * y, v.PHW / 4, color[0], color[1], color[2], v);
            c_h.add_to_stack(color[0], color[1], color[2]);
        }
    }

    //split pattern:

    int resolution = 8;

    while (v.PHW % (resolution * 2) == 0){

        redouble_resolution(data, resolution, &c_h, v);
        resolution *= 2;

        /*if(resolution == 16){
            smoth_x(data, &c_h, v);
            smoth_y(data, &c_h, v);
            v.SCATTERING = 5;
        }*/

        if(resolution == 32){
            smoth_x(data, &c_h, v);
            smoth_y(data, &c_h, v);
            v.SCATTERING = 0;
        }

    }

    remove_single_dots(data, &c_h, v);

    int i = 0;

    while (i < 50) {

        std::cout << "smoth x & y lines - revision: " << i << std::endl;

        smoth_x(data, &c_h, v);
        smoth_y(data, &c_h, v);

        i++;
    }

    return true;
}
















