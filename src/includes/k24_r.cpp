//
// Created by Karl Kegel on 15.02.17.
//

#include "../header/k24_r.h"

bool generate(unsigned char *data){

    color_handler c_h;
    c_h.init();

    std::array<unsigned char, 3> color;

    int seed = 0;

    //4x4 base pattern:

    for(int y = 0; y < 4; y++){
        for(int x = 0; x < 4; x++){

            int r = std::rand() % 20;
            if( r < 2){
                color = c_h.random_color(seed, BLACK);
            }else if( r < 10){
                color = c_h.random_color(seed, WHITE);
            }else if( r < 12){
                color = c_h.random_color(seed, GREY);
            }else {
                color = c_h.random_color(seed, COLOR);
            }

            fill_rect(data, PHW / 4 * x, PHW / 4, PHW / 4 * y, PHW / 4, color[0], color[1], color[2]);
            c_h.add_to_stack(color[0], color[1], color[2]);
        }
    }

    //split pattern:

    int resolution = 8;

    while (PHW % (resolution * 2) == 0){

        redouble_resolution(data, resolution, &c_h);
        resolution *= 2;
    }

    return true;
}

bool set_max_resolution(){

}

bool redouble_resolution(unsigned char *data, int resolution, color_handler *c_h){

    int square_corner_diff = PHW / resolution;
    int new_sqare_diff = PHW / (resolution * 2);
    std::array<unsigned char, 3> color;

    std::cout << "calculationg resolution " << (resolution*2) << std::endl;

    int y = 0;

    while(y < PHW){

        for(int x = 0; x < PHW; x += (square_corner_diff - 1)){

           //std::cout << y << "," << x << std::endl;

            int f = 0;
            int r = std::rand() % 100;

            if(is_inner_pixel(x,y)){

                if(y % 2 == 0) { //inner bottom

                    while (f < 2) {

                        if (f == 0) { //right corner

                            if (r < 50) {
                                color = get_color(data, x, y);
                            } else if (r < 65) {
                                color = get_color(data, x + 1, y);
                            } else if (r < 80) {
                                color = get_color(data, x, y - 1);
                            } else if (r < 100 - SCATTERING){
                                color = get_color(data, x + 1, y - 1);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2]);
                            x++;
                            c_h -> add_to_stack(color[0], color[1], color[2]);

                        } else { //left corner

                            r = std::rand() % 100;

                            if (r < 50) {
                                color = get_color(data, x, y);
                            } else if (r < 65) {
                                color = get_color(data, x - 1, y);
                            } else if (r < 80) {
                                color = get_color(data, x, y - 1);
                            } else if (r < 100 - SCATTERING){
                                color = get_color(data, x - 1, y - 1);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2]);
                        }
                        f++;
                    }

                }else{ //inner top

                    while (f < 2) {

                        if (f == 0) { //right corner

                            if (r < 50) {
                                color = get_color(data, x, y);
                            } else if (r < 65) {
                                color = get_color(data, x + 1, y);
                            } else if (r < 80) {
                                color = get_color(data, x, y + 1);
                            } else if (r < 100 - SCATTERING){
                                color = get_color(data, x + 1, y + 1);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2]);
                            x++;
                            c_h -> add_to_stack(color[0], color[1], color[2]);

                        } else { //left corner

                            r = std::rand() % 100;

                            if (r < 50) {
                                color = get_color(data, x, y);
                            } else if (r < 65) {
                                color = get_color(data, x - 1, y);
                            } else if (r < 80) {
                                color = get_color(data, x, y + 1);
                            } else if (r < 100 - SCATTERING){
                                color = get_color(data, x - 1, y + 1);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2]);
                        }
                        f++;
                    }

                }

            }else if(is_bottom_stroke(x,y) && is_left_stroke(x,y)){ //bottom left corner

                if(r < SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2]);
                }

            }else if(is_bottom_stroke(x,y) && is_right_stroke(x,y)){ //bottom right corner

                if(r < SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2]);
                }

            }else if(is_top_stroke(x,y) && is_left_stroke(x,y)){ //top left corner

                if(r < SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x, new_sqare_diff, y - new_sqare_diff +1 , new_sqare_diff, color[0], color[1], color[2]);
                }

            }else if(is_top_stroke(x,y) && is_right_stroke(x,y)){ //top right corner

                if(r < SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2]);
                }

            }else if(is_bottom_stroke(x,y)){

                while(f < 2){

                    if(f == 0){ //right

                        if(r < 60){
                            color = get_color(data, x, y);
                        }if(r < 100 - SCATTERING){
                            color = get_color(data, x+1, y);
                        } else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2]);
                        x++;
                        c_h -> add_to_stack(color[0], color[1], color[2]);

                    }else{ //left

                        r = std::rand() % 100;

                        if(r < 60){
                            color = get_color(data, x, y);
                        }if(r < 100 - SCATTERING){
                            color = get_color(data, x-1, y);
                        } else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2]);

                    }
                    f++;
                }

            }else if(is_top_stroke(x,y)){

                while(f < 2){

                    if(f == 0){ //right

                        if(r < 60){
                            color = get_color(data, x, y);
                        }if(r < 100 - SCATTERING){
                            color = get_color(data, x+1, y);
                        }else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2]);
                        x++;
                        c_h -> add_to_stack(color[0], color[1], color[2]);

                    }else{ //left

                        r = std::rand() % 100;

                        if(r < 60){
                            color = get_color(data, x, y);
                        }if(r < 100 - SCATTERING){
                            color = get_color(data, x-1, y);
                        }else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2]);

                    }
                    f++;
                }

            }else if(is_left_stroke(x,y)){

                if(y % 2 == 0) { //square bottom

                    if (r < 60) {
                        color = get_color(data, x, y);
                    }
                    if (r < 100 - SCATTERING) {
                        color = get_color(data, x, y + 1);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x, new_sqare_diff, y , new_sqare_diff, color[0], color[1], color[2]);

                }else{ //square top

                    if (r < 60) {
                        color = get_color(data, x, y);
                    }
                    if (r < 100 - SCATTERING) {
                        color = get_color(data, x, y - 1);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x, new_sqare_diff, y - new_sqare_diff + 1 , new_sqare_diff, color[0], color[1], color[2]);

                }

            }else if(is_right_stroke(x,y)){

                if(y % 2 == 0) { //square bottom

                    if (r < 60) {
                        color = get_color(data, x, y);
                    }
                    if (r < 100 - SCATTERING) {
                        color = get_color(data, x, y + 1);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y , new_sqare_diff, color[0], color[1], color[2]);

                }else{ //square top

                    if (r < 60) {
                        color = get_color(data, x, y);
                    }
                    if (r < 100 - SCATTERING) {
                        color = get_color(data, x, y - 1);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1 , new_sqare_diff, color[0], color[1], color[2]);

                }

            }

            c_h -> add_to_stack(color[0], color[1], color[2]);

        }

        //std::cout << "reached line end " << y << std::endl;

        if(y % 2 == 0) {
            y += (square_corner_diff - 1);
        }else{
            y++;
        }

    }

    return true;
}
















