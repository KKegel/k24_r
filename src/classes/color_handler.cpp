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

int color_handler::get_complement_color(int color) {

    if(color == v->BLUE){
        return v->ORANGE;
    }
    if(color == v->ORANGE){
        return v->BLUE;
    }
    if(color == v->YELLOW){
        return v->VIOLETT;
    }
    if(color == v->VIOLETT){
        return v->YELLOW;
    }
    if(color == v->RED){
        return v->GREEN;
    }

    return v->RED;
}

std::array<unsigned char, 3> color_handler::hue(int color) {

    std::array<unsigned char, 3> c;

    if(color == v->BLUE){

        c[0] = (rand() % (v->U_BLUE[0] - v->D_BLUE[0])) + v->D_BLUE[0];
        c[1] = (rand() % (v->U_BLUE[1] - v->D_BLUE[1])) + v->D_BLUE[1];
        c[2] = (rand() % (v->U_BLUE[2] - v->D_BLUE[2])) + v->D_BLUE[2];

    }else if(color == v->ORANGE){

        c[0] = (rand() % (v->U_ORANGE[0] - v->D_ORANGE[0])) + v->D_ORANGE[0];
        c[1] = (rand() % (v->U_ORANGE[1] - v->D_ORANGE[1])) + v->D_ORANGE[1];
        c[2] = (rand() % (v->U_ORANGE[2] - v->D_ORANGE[2])) + v->D_ORANGE[2];

    }else if(color == v->YELLOW){

        c[0] = (rand() % (v->U_YELLOW[0] - v->D_YELLOW[0])) + v->D_YELLOW[0];
        c[1] = (rand() % (v->U_YELLOW[1] - v->D_YELLOW[1])) + v->D_YELLOW[1];
        c[2] = (rand() % (v->U_YELLOW[2] - v->D_YELLOW[2])) + v->D_YELLOW[2];

    }else if(color == v->VIOLETT){

        c[0] = (rand() % (v->U_VIOLETT[0] - v->D_VIOLETT[0])) + v->D_VIOLETT[0];
        c[1] = (rand() % (v->U_VIOLETT[1] - v->D_VIOLETT[1])) + v->D_VIOLETT[1];
        c[2] = (rand() % (v->U_VIOLETT[2] - v->D_VIOLETT[2])) + v->D_VIOLETT[2];

    }else if(color == v->RED){

        c[0] = (rand() % (v->U_RED[0] - v->D_RED[0])) + v->D_RED[0];
        c[1] = (rand() % (v->U_RED[1] - v->D_RED[1])) + v->D_RED[1];
        c[2] = (rand() % (v->U_RED[2] - v->D_RED[2])) + v->D_RED[2];

    }else{

        c[0] = (rand() % (v->U_GREEN[0] - v->D_GREEN[0])) + v->D_GREEN[0];
        c[1] = (rand() % (v->U_GREEN[1] - v->D_GREEN[1])) + v->D_GREEN[1];
        c[2] = (rand() % (v->U_GREEN[2] - v->D_GREEN[2])) + v->D_GREEN[2];
    }

    int bright = (std::rand() % 100) - 50;

    return  scale_color(bright, bright, bright, c);
}

double color_handler::get_color_relation(int col_from, int col_to) {

    if(col_from == v->BLUE){

        if(col_to == v->BLUE){
            return (double)v->V_BLUE/(v->V_BLUE+v->V_BLUE);
        }
        if(col_to == v->ORANGE){
            return (double)v->V_ORANGE/(v->V_BLUE+v->V_ORANGE);
        }
        if(col_to == v->YELLOW){
            return (double)v->V_YELLOW/(v->V_BLUE+v->V_YELLOW);
        }
        if(col_to == v->VIOLETT){
            return (double)v->V_VIOLETT/(v->V_BLUE+v->V_VIOLETT);
        }
        if(col_to == v->RED){
            return (double)v->V_RED/(v->V_BLUE+v->V_RED);
        }
        return (double)v->V_GREEN/(v->V_BLUE+v->V_GREEN);
    }

    if(col_from == v->ORANGE){

        if(col_to == v->BLUE){
            return (double)v->V_BLUE/(v->V_ORANGE+v->V_BLUE);
        }
        if(col_to == v->ORANGE){
            return (double)v->V_ORANGE/(v->V_ORANGE+v->V_ORANGE);
        }
        if(col_to == v->YELLOW){
            return (double)v->V_YELLOW/(v->V_ORANGE+v->V_YELLOW);
        }
        if(col_to == v->VIOLETT){
            return (double)v->V_VIOLETT/(v->V_ORANGE+v->V_VIOLETT);
        }
        if(col_to == v->RED){
            return (double)v->V_RED/(v->V_ORANGE+v->V_RED);
        }
        return (double)v->V_GREEN/(v->V_ORANGE+v->V_GREEN);
    }

    if(col_from == v->YELLOW){

        if(col_to == v->BLUE){
            return (double)v->V_BLUE/(v->V_YELLOW+v->V_BLUE);
        }
        if(col_to == v->ORANGE){
            return (double)v->V_ORANGE/(v->V_YELLOW+v->V_ORANGE);
        }
        if(col_to == v->YELLOW){
            return (double)v->V_YELLOW/(v->V_YELLOW+v->V_YELLOW);
        }
        if(col_to == v->VIOLETT){
            return (double)v->V_VIOLETT/(v->V_YELLOW+v->V_VIOLETT);
        }
        if(col_to == v->RED){
            return (double)v->V_RED/(v->V_YELLOW+v->V_RED);
        }
        return (double)v->V_GREEN/(v->V_YELLOW+v->V_GREEN);
    }

    if(col_from == v->VIOLETT){

        if(col_to == v->BLUE){
            return (double)v->V_BLUE/(v->V_VIOLETT+v->V_BLUE);
        }
        if(col_to == v->ORANGE){
            return (double)v->V_ORANGE/(v->V_VIOLETT+v->V_ORANGE);
        }
        if(col_to == v->YELLOW){
            return (double)v->V_YELLOW/(v->V_VIOLETT+v->V_YELLOW);
        }
        if(col_to == v->VIOLETT){
            return (double)v->V_VIOLETT/(v->V_VIOLETT+v->V_VIOLETT);
        }
        if(col_to == v->RED){
            return (double)v->V_RED/(v->V_VIOLETT+v->V_RED);
        }
        return (double)v->V_GREEN/(v->V_VIOLETT+v->V_GREEN);
    }

    if(col_from == v->RED){

        if(col_to == v->BLUE){
            return (double)v->V_BLUE/(v->V_RED+v->V_BLUE);
        }
        if(col_to == v->ORANGE){
            return (double)v->V_ORANGE/(v->V_RED+v->V_ORANGE);
        }
        if(col_to == v->YELLOW){
            return (double)v->V_YELLOW/(v->V_RED+v->V_YELLOW);
        }
        if(col_to == v->VIOLETT){
            return (double)v->V_VIOLETT/(v->V_RED+v->V_VIOLETT);
        }
        if(col_to == v->RED){
            return (double)v->V_RED/(v->V_RED+v->V_RED);
        }
        return (double)v->V_GREEN/(v->V_RED+v->V_GREEN);
    }

    if(col_to == v->BLUE){
        return (double)v->V_BLUE/(v->V_GREEN+v->V_BLUE);
    }
    if(col_to == v->ORANGE){
        return (double)v->V_ORANGE/(v->V_GREEN+v->V_ORANGE);
    }
    if(col_to == v->YELLOW){
        return (double)v->V_YELLOW/(v->V_GREEN+v->V_YELLOW);
    }
    if(col_to == v->VIOLETT){
        return (double)v->V_VIOLETT/(v->V_GREEN+v->V_VIOLETT);
    }
    if(col_to == v->RED){
        return (double)v->V_RED/(v->V_GREEN+v->V_RED);
    }
    return (double)v->V_GREEN/(v->V_GREEN+v->V_GREEN);
}

std::array<unsigned char, 3> color_handler::scale_color(int fac_r, int fac_g, int fac_b, std::array<unsigned char, 3> color) {

    if(color[0] + fac_r <= 0xff){

        if(color[0] + fac_r >= 0x00){

            color[0] += fac_r;

        }else{
            color[0] = 0x00;
        }
    }else{
        color[0] = 0xff;
    }

    if(color[1] + fac_g <= 0xff){

        if(color[1] + fac_g >= 0x00){

            color[1] += fac_g;

        }else{
            color[1] = 0x00;
        }
    }else{
        color[1] = 0xff;
    }

    if(color[2] + fac_b <= 0xff){

        if(color[2] + fac_b >= 0x00){

            color[2] += fac_b;

        }else{
            color[2] = 0x00;
        }
    }else{
        color[2] = 0xff;
    }

    return color;
}

bool color_handler::optimize_color(unsigned char *data, int color) {

    std::cout << "set variables..." << std::endl;

    std::array<unsigned char, 3> ref_col;
    std::array<unsigned char, 3> rep_col;

    if(color == v->RED){

        ref_col = {v->O_RED[0], v->O_RED[1], v->O_RED[2]};

    }else if(color == v->GREEN){

        ref_col = {v->O_GREEN[0], v->O_GREEN[1], v->O_GREEN[2]};

    }else if(color == v->BLUE){

        ref_col = {v->O_BLUE[0], v->O_BLUE[1], v->O_BLUE[2]};

    }else if(color == v->ORANGE){

        ref_col = {v->O_ORANGE[0], v->O_ORANGE[1], v->O_ORANGE[2]};

    }else if(color == v->YELLOW){

        ref_col = {v->O_YELLOW[0], v->O_YELLOW[1], v->O_YELLOW[2]};

    }else if(color == v->VIOLETT){

        ref_col = {v->O_VIOLETT[0], v->O_VIOLETT[1], v->O_VIOLETT[2]};

    }

    int best_diff = 785;
    int diff = 0;
    int best_pos;

    std::cout << "modify stack..." << std::flush;
    std::vector<std::array<unsigned char, 4>> stack = cc.get_weighted_color_stack();
    std::cout << " finished" << std::endl;


    std::cout << "search colors..." << std::flush;
    for(int i = 0; i < stack.size(); i++){

        diff = 0;

        diff += abs(ref_col[0] - stack[i][0]);
        diff += abs(ref_col[1] - stack[i][1]);
        diff += abs(ref_col[2] - stack[i][2]);

        if(diff < best_diff){

            best_diff = diff;
            best_pos = i;
        }
    }
    std::cout << " finished" << std::endl;

    rep_col[0] = stack[best_pos][0];
    rep_col[1] = stack[best_pos][1];
    rep_col[2] = stack[best_pos][2];

    int x = 0;
    int y = 0;

    std::cout << "replace y lines..." << std::endl;
    std::cout << "y: " << 0 << " of " << (v->PHW - 1) << std::flush;
    while(y < v->PHW){

        std::cout << "\ry: " << y << " of " << (v->PHW - 1) << std::flush;

        while(x < v->PHW){

            if(compare_colors(get_color(data, x, y, *v), rep_col)){
                fill_rect(data, x, y, 1, 1, ref_col[0], ref_col[1], ref_col[2], *v);
            }

            x++;
        }

        x = 0;
        y++;
    }

    std::cout << " ...finished" << std::endl;

    return true;
}









