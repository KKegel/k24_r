//
// Created by Karl Kegel on 15.02.17.
//

#ifndef K24_R_COLOR_HANDLER_H
#define K24_R_COLOR_HANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <array>
#include <time.h>

#include "color_corpus.h"
#include "values.h"
#include "../../header/bmp_edit.h"

class color_handler {

public:

    bool init(values *val);

    std::array<unsigned char, 3> random_color(int seed, int type);
    std::array<unsigned char,  3> random_stack_color();

    bool add_to_stack(unsigned char r, unsigned char g, unsigned char b);
    bool clear_stack();
    bool index(unsigned char *data);

    static bool compare_colors(std::array<unsigned char, 3> c1, std::array<unsigned char, 3> c2);
    static std::array<unsigned char, 3> mix_colors(std::array<unsigned char, 3> c1, std::array<unsigned char, 3> c2,
                                                   int amount_c1, int amount_c2);

    std::vector<std::array<unsigned char, 6>> get_colors_by_likelihood(int down, int top);

    int brightness_average(unsigned char *data);
    int max_bright_pix_average(unsigned char *data);
    bool scale_color(unsigned char *data, int x, int y, int fac_r, int fac_g, int fac_b);

private:

    color_corpus cc;
    values *v;

};


#endif //K24_R_COLOR_HANDLER_H
