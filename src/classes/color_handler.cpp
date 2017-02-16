//
// Created by Karl Kegel on 15.02.17.
//

#include "header/color_handler.h"

bool color_handler::init(){

    cc.init_stack();

    return true;
}

std::array<unsigned char, 3> color_handler::random_color(int seed, int type){

    std::array<unsigned char, 3> color;

    if(type == COLOR) {

        color[0] = std::rand() % 256;
        color[1] = std::rand() % 256;
        color[2] = std::rand() % 256;

    }else if(type == GREY){

        unsigned char val = std::rand() % 256;

        color[0] = val;
        color[1] = val;
        color[2] = val;

    }else if(type == WHITE){

        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;

    }else if(type == BLACK){

        color[0] = 0x00;
        color[1] = 0x00;
        color[2] = 0x00;

    }

    return color;
}