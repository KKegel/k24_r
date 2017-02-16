//
// Created by Karl Kegel on 14.02.17.
//

#ifndef K24_R_BMP_EDITOR_H
#define K24_R_BMP_EDITOR_H

#include "values.h"

#include <stdio.h>
#include <iostream>
#include <array>

bool fill_rect(unsigned char *bmp_start, int start_x, int w_x, int start_y, int w_y, unsigned char r, unsigned char g, unsigned char b);

std::array<unsigned char, 3> get_color(unsigned char *bmp_start, int x, int y);

bool is_inner_pixel(int x, int y);
bool is_bottom_stroke(int x, int y);
bool is_right_stroke(int x, int y);
bool is_left_stroke(int x, int y);
bool is_top_stroke(int x, int y);


#endif //K24_R_BMP_EDITOR_H
