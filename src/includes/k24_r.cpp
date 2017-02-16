//
// Created by Karl Kegel on 15.02.17.
//

#include "../header/k24_r.h"

bool generate(unsigned char *data){

    color_handler c_h;
    c_h.init();

    std::array<unsigned char, 3> color;

    int seed = 0;

    //4x4 base pattern:

    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){

            int r = std::rand() % 20;
            if( r < 2){
                color = c_h.random_color(seed, BLACK);
            }else if( r < 10){
                color = c_h.random_color(seed, WHITE);
            }else if( r < 12){
                color = c_h.random_color(seed, GREY);
            }else {
                color = c_h.random_color(seed, COLOR);
            }

            fill_rect(data, PHW / 4 * x, PHW / 4, PHW / 4 * y, PHW / 4, color[0], color[1], color[2]);
        }
    }

    //split pattern /4:



    return true;
}