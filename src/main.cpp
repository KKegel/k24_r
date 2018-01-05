
#include <iostream>
#include <chrono>

#include "classes/header/values.h"
#include "header/bmp_edit.h"
#include "header/k24_r.h"


const unsigned char bftype[2] =     {0x42, 0x4d};               //key (fixed)
const unsigned char bfsize[4] =     {0x36, 0x00, 0x00, 0x0c};   //file size (Byte)
const unsigned char bfReserved[4] = {0x00, 0x00, 0x00, 0x00};   //reserved
const unsigned char bfOffBits[4] =  {0x36, 0x00, 0x00, 0x00};   //offset (default)
const unsigned char biSize[4] =     {0x28, 0x00, 0x00, 0x00};   //info size (default)
const unsigned char biWidth[4] =    {0x00, 0x20, 0x00, 0x00};   //image width
const unsigned char biHeight[4] =   {0x00, 0x20, 0x00, 0x00};   //image height
const unsigned char biPlanes[2] =   {0x01, 0x00};               //default
const unsigned char biBitCount[2] = {0x18, 0x00};               //color system (24rgb)
const unsigned char biCompress[4] = {0x00, 0x00, 0x00, 0x00};   //default
const unsigned char biSizeImag[4] = {0x00, 0x00, 0x00, 0x0c};   //size data block (Byte)
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

unsigned char data[8192*8192*3]; //height (y), width (x), color bytes
values v;

int main(int argn, char *argv[]) {

    for(int i = 0; i < 1; i++) {

        std::cout << "...set generator seed" << std::endl;
        std::srand(time(0));

        std::cout << "...start timer" << std::endl;
        auto start = std::chrono::high_resolution_clock::now();

        std::cout << "...init filename - " << std::flush;
        int key = 0;

        int n = 0;
        int up = std::rand() % 1234;
        while(n < up){
            key = std::rand();
            n++;
        }

        std::cout << "name id = " << std::to_string(key) << std::endl;

        int reps = generate(&data[0]);

        std::string f_name = *argv[1] + std::to_string(key) + "_" + std::to_string(reps) + ".bmp";
        //std::string f_name = "k24_rOUT-" + std::to_string(key) + "_" + std::to_string(reps) + ".bmp";
        std::cout << "writing bitmap: " << f_name << std::endl;

        std::cout << "open file stream" << std::endl;
        FILE *bmp_file = fopen(f_name.c_str(), "wb");

        std::cout << "write header ... " << std::flush;
        for (int j = 0; j < 54; j++) {
            putc(head[j], bmp_file);
        }
        std::cout << " finished" << std::endl;

        std::cout << "write data bytes ... " << std::flush;
        for (int j = 0; j < (v.PHW * v.PHW * 3); j++) {
            putc(data[j], bmp_file);
        }
        std::cout << " finished" << std::endl;

        std::cout << "close file stream" << std::endl;
        fclose(bmp_file);

        std::cout << "\nstop timer" << std::endl;

        auto elapsed = std::chrono::high_resolution_clock::now() - start;
        long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
        long double millisec = microseconds * 0.001;

        std::cout << "execution time = " << millisec << " ms" << std::endl;

    }

    std::cout << "...k24_r finished" << std::endl;

    return 0;

}
