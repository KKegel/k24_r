//
// Created by Karl Kegel on 19.02.17.
//

#ifndef K24_R_VALUES_H
#define K24_R_VALUES_H

//#include <profile.h>
#include <vector>
#include <iostream>

class values {

public:

    const int PHW = 8192;

    int SCATTERING = 10;

    const int BLACK = 0;
    const int WHITE = 1;
    const int GREY = 2;
    const int COLOR = 3;

    const int YELLOW = 10;
    const int VIOLETT = 11;
    const int ORANGE = 12;
    const int BLUE = 13;
    const int RED = 14;
    const int GREEN = 15;

    const int V_YELLOW = 3;
    const int V_VIOLETT = 9;
    const int V_ORANGE = 4;
    const int V_BLUE = 8;
    const int V_RED = 6;
    const int V_GREEN = 6;

    //b, g, r

    const unsigned char O_RED[3] = {0x00, 0x00, 255};
    const unsigned char U_RED[3] = {0x70, 0x70, 0xff};
    const unsigned char D_RED[3] = {0x00, 0x00, 0xa0};

    const unsigned char O_GREEN[3] = {0x00, 255, 0x00};
    const unsigned char U_GREEN[3] = {0xa0, 0xff, 0x70};
    const unsigned char D_GREEN[3] = {0x00, 0xa0, 0x00};

    const unsigned char O_BLUE[3] = {255, 0x00, 0x00};
    const unsigned char U_BLUE[3] = {0xff, 0xa0, 0x80};
    const unsigned char D_BLUE[3] = {0xa0, 0x00, 0x00};

    const unsigned char O_ORANGE[3] = {0x00, 175, 255};
    const unsigned char U_ORANGE[3] = {0x01, 0xa0, 0xff};
    const unsigned char D_ORANGE[3] = {0x00, 0x50, 0xc0};

    const unsigned char O_VIOLETT[3] = {0x55, 0x00, 0x55};
    const unsigned char U_VIOLETT[3] = {0xa0, 0x01, 0xa0};
    const unsigned char D_VIOLETT[3] = {0x40, 0x00, 0x20};

    const unsigned char O_YELLOW[3] = {0x00, 255, 255};
    const unsigned char U_YELLOW[3] = {0x01, 0xff, 0xff};
    const unsigned char D_YELLOW[3] = {0x00, 0xc0, 0xc0};

    const int MAX = 1001;
    const int MIN = 1002;

};


#endif //K24_R_VALUES_H
