//
// Created by Karl Kegel on 15.02.17.
//

#include "header/color_handler.h"

bool color_handler::init(values *val){

    cc.init_stack();
    v = val;

    return true;
}

bool color_handler::clear_stack() {

    cc.clear_stack();

    return true;
}

bool color_handler::index(unsigned char *data){

    std::array<unsigned char, 3> color;

    std::cout << "y: " << 0 << " of " << (v->PHW - 1) << std::flush;

    for(int y = 0; y < v->PHW; y++){

        std::cout << "\ry: " << y << " of " << (v->PHW - 1) << std::flush;

        for(int x = 0; x < v->PHW; x++){

            color = get_color(data, x, y, *v);
            cc.add_to_stack(color[0], color[1], color[2]);

        }
    }

    std::cout << " ... finished" << std::endl;

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

int color_handler::brightness_average(unsigned char *data){

    int b_a = 0;
    std::array<std::array<int, 3>, 8192> line_vals;

    for (int y = 0; y < v->PHW; y++){

        line_vals[y][0] = 0;
        line_vals[y][1] = 0;
        line_vals[y][2] = 0;

        for(int x = 0; x < (v->PHW*3); x += 3){

            line_vals[y][0] += *data;
            data++;
            line_vals[y][1] += *data;
            data++;
            line_vals[y][2] += *data;
            data++;

        }

        line_vals[y][0] /= v->PHW;
        line_vals[y][1] /= v->PHW;
        line_vals[y][2] /= v->PHW;

    }

    int a_r = 0;
    int a_g = 0;
    int a_b = 0;

    for(int i = 0; i < v->PHW; i++){

        a_r += line_vals[i][0];
        a_g += line_vals[i][1];
        a_b += line_vals[i][2];

    }

    a_r /= v->PHW;
    a_g /= v->PHW;
    a_b /= v->PHW;

    b_a = (a_r + a_g + a_b) / 3;

    return b_a;
}

int color_handler::max_bright_pix_average(unsigned char *data){

    int max = 0;
    int curr;

    for(int y = 0; y < v->PHW; y++){

        for(int x = 0; x < v->PHW; x++){

            curr = *data;
            data++;
            curr += *data;
            data++;
            curr += *data;
            data++;

            curr /= 3;

            if(curr > max){

                max = curr;

                if(max == 0xff){
                    break;
                }

            }
        }

        if(max == 0xff){
            break;
        }

    }

    return max;
}

bool color_handler::scale_color(unsigned char *data, int x, int y, int fac_r, int fac_g, int fac_b){

    if((*data * (100 + fac_r)) / 100 <= 0xff) {

        if((*data * (100 + fac_r)) / 100 >= 0x00){

            *data = (*data * (100 + fac_r)) / 100;

        }else{
            *data = 0x00;
        }

    }else{
        *data = 0xff;
    }
    data++;

    if((*data * (100 + fac_g)) / 100 <= 0xff) {

        if((*data * (100 + fac_g)) / 100 >= 0x00){

            *data = (*data * (100 + fac_g)) / 100;

        }else{
            *data = 0x00;
        }

    }else{
        *data = 0xff;
    }
    data++;

    if((*data * (100 + fac_b)) / 100 <= 0xff) {

        if((*data * (100 + fac_b)) / 100 >= 0x00){

            *data = (*data * (100 + fac_b)) / 100;

        }else{
            *data = 0x00;
        }

    }else{
        *data = 0xff;
    }

    return true;
}

std::vector<std::array<unsigned char, 6>> color_handler::get_colors_by_likelihood(int down, int top) {

    return cc.colors_by_likelihood(down, top);
}









