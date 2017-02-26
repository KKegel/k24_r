//
// Created by Karl Kegel on 18.02.17.
//

#ifndef K24_R_PIXEL_OPERATIONS_H
#define K24_R_PIXEL_OPERATIONS_H

#include <stdio.h>
#include <array>
#include <time.h>

#include "../classes/header/values.h"
#include "bmp_edit.h"

#include "../classes/header/color_handler.h"

bool redouble_resolution(unsigned char *data, int resolution, color_handler *c_h, values v);
bool remove_single_dots(unsigned char *data, color_handler *c_h, values v);

bool smoth_x(unsigned char *data, color_handler *c_h, values v);
bool smoth_y(unsigned char *data, color_handler *c_h, values v);

bool manipulate_brightness(unsigned char *data, int bottom_color_av, int top_color_av, int bright_plus, values v);
bool scale_brightness(unsigned char *data, int p_r, int p_g, int p_b, color_handler *c_h, values v);
bool clean_colors(unsigned char *data, int firs, int sec, int third, int tol, color_handler *c_h, values v);

bool replace_colors(unsigned char *data, std::vector<std::array<unsigned char, 6>> colors, color_handler *c_h, values v);

#endif //K24_R_PIXEL_OPERATIONS_H
