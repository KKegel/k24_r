//
// Created by Karl Kegel on 14.02.17.
//

#include "../header/bmp_edit.h"

bool fill_rect(unsigned char *bmp_start, int start_x, int w_x, int start_y, int w_y, unsigned char r, unsigned char g, unsigned char b){

    unsigned char *ac_p = bmp_start + (start_y * PHW * 3 + start_x * 3);

    int y = 0;
    int x = 0;

    while (y < w_y){

        while (x < w_x){

            *(ac_p) = r;
            *(++ac_p) = g;
            *(++ac_p) = b;
            ac_p++;

            x++;
        }

        ac_p += (PHW * 3 - (start_x * 3 + w_x * 3) + start_x * 3);
        x = 0;
        y++;
    }

    return true;
}

std::array<unsigned char, 3> get_color(unsigned char *bmp_start, int x, int y){

    unsigned char *ac_p = bmp_start + (y * PHW * 3 + x * 3);
    std::array<unsigned char, 3> color;

    color[0] = *ac_p;
    ac_p++;
    color[1] = *ac_p;
    ac_p++;
    color[2] = *ac_p;

    return color;
}

bool is_inner_pixel(int x, int y){

    if(x == 0 || y == 0){
        return false;
    } else if(x-PHW == -1 || y-PHW == -1){
        return false;
    }

    return true;
}

bool is_bottom_stroke(int x, int y){

    if(y == 0){
        return true;
    }

    return false;
}

bool is_right_stroke(int x, int y){

    if(x-PHW == -1){
        return true;
    }

    return false;
}

bool is_left_stroke(int x, int y){

    if(x == 0){
        return true;
    }

    return false;
}

bool is_top_stroke(int x, int y){

    if(y-PHW == -1){
        return true;
    }

    return false;
}