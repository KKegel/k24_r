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
#include "../../header/values.h"

class color_handler {

public:

    bool init();

    std::array<unsigned char, 3> random_color(int seed, int type);

private:

    color_corpus cc;

};


#endif //K24_R_COLOR_HANDLER_H
