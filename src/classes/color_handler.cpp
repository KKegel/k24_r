//
// Created by Karl Kegel on 15.02.17.
//

#include "header/color_handler.h"

bool color_handler::init(values *val){

    cc.init_stack();
    v = val;

    return true;
}

std::array<unsigned char, 3> color_handler::random_color(int seed, int type){

    std::array<unsigned char, 3> color;

    if(type == v->COLOR) {

        color[0] = std::rand() % 256;
        color[1] = std::rand() % 256;
        color[2] = std::rand() % 256;

    }else if(type == v->GREY){

        unsigned char val = std::rand() % 256;

        color[0] = val;
        color[1] = val;
        color[2] = val;

    }else if(type == v->WHITE){

        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;

    }else if(type == v->BLACK){

        color[0] = 0x00;
        color[1] = 0x00;
        color[2] = 0x00;

    }

    return color;
}

std::array<unsigned char,  3> color_handler::random_stack_color(){

    return cc.random_stack_color();
}

bool color_handler::add_to_stack(unsigned char r, unsigned char g, unsigned char b){

    cc.add_to_stack(r, g, b);

    return true;
}

std::array<unsigned char, 3> color_handler::mix_colors(
        std::array<unsigned char, 3> c1, std::array<unsigned char, 3> c2, int amount_c1, int amount_c2) {

    std::array<unsigned char, 3> color;

    color[0] = (c1[0] * amount_c1 + c2[0] * amount_c2) / (amount_c1 + amount_c2);
    color[1] = (c1[1] * amount_c1 + c2[1] * amount_c2) / (amount_c1 + amount_c2);
    color[2] = (c1[2] * amount_c1 + c2[2] * amount_c2) / (amount_c1 + amount_c2);

    return color;
}

bool color_handler::compare_colors(std::array<unsigned char, 3> c1, std::array<unsigned char, 3> c2){

    return ((c1[0] == c2[0]) && (c1[1] == c2[1]) && (c1[2] == c2[2]));
}

