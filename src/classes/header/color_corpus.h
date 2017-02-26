//
// Created by Karl Kegel on 15.02.17.
//

#ifndef K24_R_COLOR_CORPUS_H
#define K24_R_COLOR_CORPUS_H


#include <cstdint>
#include <vector>
#include <array>
#include <random>
#include <time.h>

class color_corpus {

public:

    bool init_stack();

    std::array<unsigned char,  3> random_stack_color();
    std::array<unsigned char,  3> weighted_stack_color();

    std::vector<std::array<unsigned char, 6>> colors_by_likelihood(int down, int up);

    bool add_to_stack(unsigned char r, unsigned char g, unsigned char b);

    bool clear_stack();

private:

    std::vector<std::array<unsigned char, 3>> color_stack; //r,g,b
    std::vector<uint32_t> likelihood;

};


#endif //K24_R_COLOR_CORPUS_H
