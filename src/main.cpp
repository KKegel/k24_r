#include <iostream>
#include <string>

#include "header/values.h"
#include "header/bmp_edit.h"
#include "header/k24_r.h"

//const int PHW = 1024; //hex:

const unsigned char bftype[2] =     {0x42, 0x4d};               //key (fixed)
const unsigned char bfsize[4] =     {0x36, 0x00, 0x30, 0x00};   //file size (Byte)
const unsigned char bfReserved[4] = {0x00, 0x00, 0x00, 0x00};   //reserved
const unsigned char bfOffBits[4] =  {0x36, 0x00, 0x00, 0x00};   //offset (default)
const unsigned char biSize[4] =     {0x28, 0x00, 0x00, 0x00};   //info size (default)
const unsigned char biWidth[4] =    {0x00, 0x04, 0x00, 0x00};   //image width
const unsigned char biHeight[4] =   {0x00, 0x04, 0x00, 0x00};   //image height
const unsigned char biPlanes[2] =   {0x01, 0x00};               //default
const unsigned char biBitCount[2] = {0x18, 0x00};               //color system (24rgb)
const unsigned char biCompress[4] = {0x00, 0x00, 0x00, 0x00};   //default
const unsigned char biSizeImag[4] = {0x00, 0x00, 0x30, 0x00};   //size data block (Byte)
const unsigned char biXPPM[4] =     {0x00, 0x00, 0x00, 0x00};   //default
const unsigned char biYPPM[4] =     {0x00, 0x00, 0x00, 0x00};   //default
const unsigned char biClrUsed[4] =  {0x00, 0x00, 0x00, 0x00};   //default
const unsigned char biClrImpo[4] =  {0x00, 0x00, 0x00, 0x00};   //default

const unsigned char head[54] = {  bftype[0], bftype[1],
                            bfsize[0], bfsize[1], bfsize[2], bfsize[3],
                            bfReserved[0], bfReserved[1], bfReserved[2], bfReserved[3],
                            bfOffBits[0], bfOffBits[1], bfOffBits[2], bfOffBits[3],
                            biSize[0], biSize[1], biSize[2], biSize[3],
                            biWidth[0], biWidth[1], biWidth[2], biWidth[3],
                            biHeight[0], biHeight[1], biHeight[2], biHeight[3],
                            biPlanes[0], biPlanes[1],
                            biBitCount[0], biBitCount[1],
                            biCompress[0], biCompress[1], biCompress[2], biCompress[3],
                            biSizeImag[0], biSizeImag[1], biSizeImag[2], biSizeImag[3],
                            biXPPM[0], biXPPM[1], biXPPM[2], biXPPM[3],
                            biYPPM[0], biYPPM[1], biYPPM[2], biYPPM[3],
                            biClrUsed[0], biClrUsed[1], biClrUsed[2], biClrUsed[3],
                            biClrImpo[0], biClrImpo[1], biClrImpo[2], biClrImpo[3]
};

unsigned char data[PHW*PHW*3]; //height (y), width (x), color bytes

int main() {

    auto start = std::chrono::high_resolution_clock::now();

    std::srand(time(0));

    for(int i = 0; i < 50; i++) {

        generate(&data[0]);

        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        long double millisec = microseconds * 0.001;
        std::cout << millisec << " ms" << std::endl;

        std::string f_name = "/Users/karlkegel/Documents/test_bmp/k24_rOUT" +std::to_string(i) + ".bmp";

        FILE *bmp_file = fopen(f_name.c_str(), "wb");

        for (int i = 0; i < 54; i++) {
            putc(head[i], bmp_file);
        }

        for (int i = 0; i < (PHW * PHW * 3); i++) {

            putc(data[i], bmp_file);
        }

        fclose(bmp_file);
    }

    return 0;

}