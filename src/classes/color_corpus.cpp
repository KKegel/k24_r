//
// Created by Karl Kegel on 15.02.17.
//

#include "header/color_corpus.h"

bool color_corpus::init_stack() {

    color_stack.push_back({0xff, 0xff, 0xff});
    likelihood.push_back(1);

    return true;
}

bool color_corpus::clear_stack(){

    color_stack.clear();
    likelihood.clear();

    init_stack();

    return true;
}

bool color_corpus::add_to_stack(unsigned char r, unsigned char g, unsigned char b) {

    bool found = false;
    int f_pos = 0;

    int top = color_stack.size()-1;
    int down = 0;

    int icenter;

    unsigned char searched = r;
    int searched_idx = 0;

    while (1) {

        icenter = down + ((top - down) / 2);
        f_pos = icenter;

        if (color_stack[icenter][searched_idx] == searched) {

            if (searched_idx == 2) {

                found = true;
                break;

            } else {

                top = icenter;
                down = icenter;

                while (color_stack.size()-1 > top+1 && color_stack[top+1][searched_idx] == searched) {
                    top++;
                }
                while (down - 1 >= 0 && color_stack[down - 1][searched_idx] == searched) {
                    down--;
                }

                if (searched_idx == 0) {
                    searched = g;
                } else {
                    searched = b;
                }

                searched_idx++;

            }

        } else if (top - down <= 0){

            break;

        }else if (searched <= color_stack[icenter][searched_idx]) {

            top = icenter - 1;

        } else {
            down = icenter + 1;
        }

    }


    if(found){

        likelihood[f_pos]++;

    }else{

        std::array<unsigned char, 3> color;

        color[0] = r;
        color[1] = g;
        color[2] = b;

        color_stack.insert(color_stack.begin()+f_pos, color);
        likelihood.insert(likelihood.begin()+f_pos, 1);

    }

    return true;
}

std::array<unsigned char,  3> color_corpus::random_stack_color(){

    int i = std::rand() % color_stack.size();

    return color_stack[i];
}

std::vector<std::array<unsigned char, 6>> color_corpus::colors_by_likelihood(int down, int up){

    std::vector<std::array<unsigned char, 6>> colors;
    std::array<unsigned char, 6> col;

    int k = 0;
    int m_size = likelihood.size() - 1;

    for(int i = 0; i < likelihood.size(); i++){

        int lkhd = likelihood[i];

        if(lkhd >= down && lkhd <= up){

            col[0] = color_stack[i][0];
            col[1] = color_stack[i][1];
            col[2] = color_stack[i][2];

            k = i;

            while(k < m_size && likelihood[k] < up){
                k++;
            }

            col[3] = color_stack[k][0];
            col[4] = color_stack[k][1];
            col[5] = color_stack[k][2];

            colors.push_back(col);

        }

    }

    return colors;
}

std::vector<std::array<unsigned char, 4>> color_corpus::get_weighted_color_stack() {

    std::vector<std::array<unsigned char, 4>> stack;
    std::array<unsigned char, 4> elem;

    for(int i = 0; i < color_stack.size(); i++){

        elem[0] = color_stack[i][0];
        elem[1] = color_stack[i][1];
        elem[2] = color_stack[i][2];
        elem[3] = likelihood[i];

        stack.push_back(elem);

    }

    return stack;
}
