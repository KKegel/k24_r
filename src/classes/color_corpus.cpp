//
// Created by Karl Kegel on 15.02.17.
//

#include "header/color_corpus.h"

bool color_corpus::init_stack() {

    return true;
}

bool color_corpus::add_to_stack(unsigned char r, unsigned char g, unsigned char b){

    bool found = false;

    for(int i = 0; i < color_stack.size(); i++){

        for(int k = 0; k < 4; k++){

            if(k == 0 && color_stack[i][k] != r){
                break;
            }
            if(k == 1 && color_stack[i][k] != g){
                break;
            }
            if(k == 2 && color_stack[i][k] != b){
                break;
            }

            likelihood[i] = likelihood[i] + 1;
            found = true;
        }

        if(found){
            found = true;
            break;
        }
    }

    if(!found){

        std::array<unsigned char, 3> color;

        color[0] = r;
        color[1] = g;
        color[2] = b;

        color_stack.push_back(color);
        likelihood.push_back(1);

    }

    return true;
}

std::array<unsigned char,  3> color_corpus::random_stack_color(){

    int i = std::rand() % color_stack.size();

    return color_stack[i];
}