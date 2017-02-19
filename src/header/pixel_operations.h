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

#endif //K24_R_PIXEL_OPERATIONS_H
