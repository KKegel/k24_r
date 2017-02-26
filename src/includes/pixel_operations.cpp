//
// Created by Karl Kegel on 18.02.17.
//

#include "../header/pixel_operations.h"

bool redouble_resolution(unsigned char *data, int resolution, color_handler *c_h, values v){

    int square_corner_diff = v.PHW / resolution;
    int new_sqare_diff = v.PHW / (resolution * 2);
    int new_resolution = resolution * 2;
    std::array<unsigned char, 3> color;

    std::cout << "calculate resolution with res. factor " << new_resolution << std::endl;
    std::cout << "y: " << 0 << " of " << (v.PHW - 1) << std::flush;

    int max_ind = 64;
    int y = 0;

    while(y < v.PHW){

        std::cout << "\ry: " << y+1 << "|" << (v.PHW - 1) << std::flush;

        for(int x = 0; x < v.PHW; x += (square_corner_diff - 1)){

            int f = 0;
            int r = std::rand() % 100;

            if(is_inner_pixel(x,y,v)){

                if(y % 2 == 0) { //inner bottom

                    while (f < 2) {

                        if (f == 0) { //right corner

                            if (r < 50) {
                                color = get_color(data, x, y,v);
                            } else if (r < 65) {
                                color = get_color(data, x + 1, y,v);
                            } else if (r < 80) {
                                color = get_color(data, x, y - 1,v);
                            } else if (r < 100 - v.SCATTERING){
                                color = get_color(data, x + 1, y - 1,v);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);
                            x++;

                            if(new_resolution < max_ind) {
                                c_h->add_to_stack(color[0], color[1], color[2]);
                            }

                        } else { //left corner

                            r = std::rand() % 100;

                            if (r < 50) {
                                color = get_color(data, x, y,v);
                            } else if (r < 65) {
                                color = get_color(data, x - 1, y,v);
                            } else if (r < 80) {
                                color = get_color(data, x, y - 1,v);
                            } else if (r < 100 - v.SCATTERING){
                                color = get_color(data, x - 1, y - 1,v);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);
                        }
                        f++;
                    }

                }else{ //inner top

                    while (f < 2) {

                        if (f == 0) { //right corner

                            if (r < 50) {
                                color = get_color(data, x, y,v);
                            } else if (r < 65) {
                                color = get_color(data, x + 1, y,v);
                            } else if (r < 80) {
                                color = get_color(data, x, y + 1,v);
                            } else if (r < 100 - v.SCATTERING){
                                color = get_color(data, x + 1, y + 1,v);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2],v);
                            x++;

                            if(new_resolution < max_ind) {
                                c_h->add_to_stack(color[0], color[1], color[2]);
                            }

                        } else { //left corner

                            r = std::rand() % 100;

                            if (r < 50) {
                                color = get_color(data, x, y,v);
                            } else if (r < 65) {
                                color = get_color(data, x - 1, y,v);
                            } else if (r < 80) {
                                color = get_color(data, x, y + 1,v);
                            } else if (r < 100 - v.SCATTERING){
                                color = get_color(data, x - 1, y + 1,v);
                            }else{
                                color = c_h -> random_stack_color();
                            }

                            fill_rect(data, x, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2],v);
                        }
                        f++;
                    }

                }

            }else if(is_bottom_stroke(x,y) && is_left_stroke(x,y)){ //bottom left corner

                if(r < v.SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);
                }

            }else if(is_bottom_stroke(x,y) && is_right_stroke(x,y,v)){ //bottom right corner

                if(r < v.SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);
                }

            }else if(is_top_stroke(x,y,v) && is_left_stroke(x,y)){ //top left corner

                if(r < v.SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x, new_sqare_diff, y - new_sqare_diff +1 , new_sqare_diff, color[0], color[1], color[2],v);
                }

            }else if(is_top_stroke(x,y,v) && is_right_stroke(x,y,v)){ //top right corner

                if(r < v.SCATTERING){
                    color = c_h -> random_stack_color();
                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2],v);
                }

            }else if(is_bottom_stroke(x,y)){

                while(f < 2){

                    if(f == 0){ //right

                        if(r < 60){
                            color = get_color(data, x, y,v);
                        }if(r < 100 - v.SCATTERING){
                            color = get_color(data, x+1, y,v);
                        } else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);
                        x++;

                        if(new_resolution < max_ind) {
                            c_h->add_to_stack(color[0], color[1], color[2]);
                        }

                    }else{ //left

                        r = std::rand() % 100;

                        if(r < 60){
                            color = get_color(data, x, y,v);
                        }if(r < 100 - v.SCATTERING){
                            color = get_color(data, x-1, y,v);
                        } else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x, new_sqare_diff, y, new_sqare_diff, color[0], color[1], color[2],v);

                    }
                    f++;
                }

            }else if(is_top_stroke(x,y,v)){

                while(f < 2){

                    if(f == 0){ //right

                        if(r < 60){
                            color = get_color(data, x, y,v);
                        }if(r < 100 - v.SCATTERING){
                            color = get_color(data, x+1, y,v);
                        }else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2],v);
                        x++;

                        if(new_resolution < max_ind) {
                            c_h->add_to_stack(color[0], color[1], color[2]);
                        }

                    }else{ //left

                        r = std::rand() % 100;

                        if(r < 60){
                            color = get_color(data, x, y,v);
                        }if(r < 100 - v.SCATTERING){
                            color = get_color(data, x-1, y,v);
                        }else{
                            color = c_h -> random_stack_color();
                        }

                        fill_rect(data, x, new_sqare_diff, y - new_sqare_diff + 1, new_sqare_diff, color[0], color[1], color[2],v);

                    }
                    f++;
                }

            }else if(is_left_stroke(x,y)){

                if(y % 2 == 0) { //square bottom

                    if (r < 60) {
                        color = get_color(data, x, y,v);
                    }
                    if (r < 100 - v.SCATTERING) {
                        color = get_color(data, x, y + 1,v);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x, new_sqare_diff, y , new_sqare_diff, color[0], color[1], color[2],v);

                }else{ //square top

                    if (r < 60) {
                        color = get_color(data, x, y,v);
                    }
                    if (r < 100 - v.SCATTERING) {
                        color = get_color(data, x, y - 1,v);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x, new_sqare_diff, y - new_sqare_diff + 1 , new_sqare_diff, color[0], color[1], color[2],v);

                }

            }else if(is_right_stroke(x,y,v)){

                if(y % 2 == 0) { //square bottom

                    if (r < 60) {
                        color = get_color(data, x, y,v);
                    }
                    if (r < 100 - v.SCATTERING) {
                        color = get_color(data, x, y + 1,v);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y , new_sqare_diff, color[0], color[1], color[2],v);

                }else{ //square top

                    if (r < 60) {
                        color = get_color(data, x, y,v);
                    }
                    if (r < 100 - v.SCATTERING) {
                        color = get_color(data, x, y - 1,v);
                    } else {
                        color = c_h -> random_stack_color();
                    }

                    fill_rect(data, x - new_sqare_diff + 1, new_sqare_diff, y - new_sqare_diff + 1 , new_sqare_diff, color[0], color[1], color[2],v);

                }

            }

            if(new_resolution < max_ind) {
                c_h->add_to_stack(color[0], color[1], color[2]);
            }

        }

        //std::cout << "reached line end " << y << std::endl;

        if(y % 2 == 0) {
            y += (square_corner_diff - 1);
        }else{
            y++;
        }

    }

    std::cout << " ... finished" << std::endl;

    return true;
}

bool remove_single_dots(unsigned char *data, color_handler *c_h, values v){

    std::cout << "remove single dots" << std::endl;
    std::cout << "y: " << 0 << "|" << (v.PHW - 1) << std::flush;

    int diff = v.PHW - 1;
    bool has_second = false;

    std::array<unsigned char, 3> original_color;
    std::array<unsigned char, 3> stroke_color;

    for(int y = 1; y < diff; y++){

        std::cout << "\ry: " << y << "|" << (v.PHW - 1) << std::flush;

        for(int x = 1; x < diff; x++){

            original_color = get_color(data, x, y,v);

            for(int y_i = y - 1; y_i <= y + 1; y_i++) {

                for (int x_i = x - 1; x_i <= x + 1; x_i++) {

                    if(x_i == x && y_i == y){
                        continue;
                    }

                    stroke_color = get_color(data, x_i, y_i,v);

                    if(c_h -> compare_colors(original_color, stroke_color)){

                        has_second = true;
                        break;
                    }
                }
            }

            if(!has_second){
                fill_rect(data,x,1,y,1, stroke_color[0], stroke_color[1], stroke_color[2],v);
            }else{
                has_second = false;
            }

        }

    }

    std::cout << " ... finished" << std::endl;

    return true;
}

bool smoth_x(unsigned char *data, color_handler *c_h, values v){

    std::array<unsigned char, 3> left_color;
    std::array<unsigned char, 3> right_color;

    std::array<unsigned char, 3> n_left_color;
    std::array<unsigned char, 3> n_right_color;

    for(int y = 0; y < (v.PHW - 1); y++){

        for(int x = 1; x < (v.PHW - 1); x++){

            left_color = get_color(data, x - 1, y,v);
            right_color = get_color(data, x, y,v);

            if(! c_h->compare_colors(left_color, right_color)){

                n_left_color = c_h->mix_colors(left_color, right_color, 2, 1);
                n_right_color = c_h->mix_colors(left_color, right_color, 1, 2);

                fill_rect(data, x - 1, 1, y, 1, n_left_color[0], n_left_color[1], n_left_color[2],v);
                fill_rect(data, x, 1, y, 1, n_right_color[0], n_right_color[1], n_right_color[2],v);

            }

        }

    }

    return true;
}

bool smoth_y(unsigned char *data, color_handler *c_h, values v){

    std::array<unsigned char, 3> top_color;
    std::array<unsigned char, 3> bottom_color;

    std::array<unsigned char, 3> n_top_color;
    std::array<unsigned char, 3> n_bottom_color;

    for(int y = 1; y < (v.PHW - 1); y++){

        for(int x = 0; x < (v.PHW - 1); x++){

            bottom_color = get_color(data, x, y - 1,v);
            top_color = get_color(data, x, y,v);

            if(! c_h->compare_colors(bottom_color, top_color)){

                n_bottom_color = c_h->mix_colors(bottom_color, top_color, 2, 1);
                n_top_color = c_h->mix_colors(bottom_color, top_color, 1, 2);

                fill_rect(data, x, 1, y - 1, 1, n_bottom_color[0], n_bottom_color[1], n_bottom_color[2],v);
                fill_rect(data, x, 1, y, 1, n_top_color[0], n_top_color[1], n_top_color[2],v);

            }

        }

    }

    return true;
}

bool manipulate_brightness(unsigned char *data, int bottom_color_av, int top_color_av, int bright_plus, values v){

    bool is_max = (bright_plus == v.MAX);
    bool is_min = (bright_plus == v.MIN);

    int sum;

    if(is_max) {

        for (int y = 0; y < v.PHW; y++) {

            for (int x = 0; x < v.PHW; x++) {

                sum = *data;
                sum += *(data + 1);
                sum += *(data + 2);
                sum /= 3;

                if ((sum >= bottom_color_av) && (sum <= top_color_av)) {

                    *data = 0xff;
                    data++;
                    *data = 0xff;
                    data++;
                    *data = 0xff;
                    data++;

                }else{
                    data += 3;
                }
            }
        }

    }else if(is_min){

        for (int y = 0; y < v.PHW; y++) {

            for (int x = 0; x < v.PHW; x++) {

                sum = *data;
                sum += *(data + 1);
                sum += *(data + 2);
                sum /= 3;

                if ((sum >= bottom_color_av) && (sum <= top_color_av)) {

                    *data = 0x00;
                    data++;
                    *data = 0x00;
                    data++;
                    *data = 0x00;
                    data++;

                }else{
                    data += 3;
                }
            }
        }

    }else{

        for (int y = 0; y < v.PHW; y++) {

            for (int x = 0; x < v.PHW; x++) {

                sum = *data;
                sum += *(data + 1);
                sum += *(data + 2);
                sum /= 3;

                if ((sum >= bottom_color_av) && (sum <= top_color_av)) {

                    int i = 0;

                    while (i < 3) {

                        if (*data + bright_plus >= 0x00) {

                            if (*data + bright_plus <= 0xff) {

                                *data += bright_plus;

                            } else {
                                *data = 0xff;
                            }
                        } else {
                            *data = 0x00;
                        }

                        data++;
                        i++;
                    }

                }else{
                    data += 3;
                }
            }
        }

    }

    return true;
}

bool scale_brightness(unsigned char *data, int p_r, int p_g, int p_b, color_handler *c_h, values v){

    for(int y = 0; y < v.PHW; y++){

        for(int x = 0; x < v.PHW; x++){

            c_h -> scale_color(data, x, y, p_r, p_g, p_b);
            data += 3;

        }
    }

    return true;
}

bool clean_colors(unsigned char *data, int firs, int sec, int third, int tol, color_handler *c_h, values v){

    std::array<unsigned char, 3> col;
    int av;
    bool is_cleanable;

    for(int y = 0; y < v.PHW; y++){

        for(int x = 0; x < v.PHW; x++) {

            col = get_color(data, x, y, v);
            av = (col[0] + col[1] + col[2]) / 3;
            is_cleanable = true;

            if((col[0] - av > 0 && col[0] - av < tol) || (av - col[0] > 0 && av - col[0] < tol)){
                if((col[1] - av > 0 && col[1] - av < tol) || (av - col[1] > 0 && av - col[1] < tol)){
                    if((col[2] - av > 0 && col[2] - av < tol) || (av - col[2] > 0 && av - col[2] < tol)){

                        is_cleanable = false;

                    }
                }
            }

            if(is_cleanable){

                if(col[0] >= col [1]){

                    if(col[1] >= col[2]){ //0-1-2

                        c_h -> scale_color(data, x, y, firs, sec, third);

                    }else if(col[2] >= col[1]){ //0-2-1

                        c_h -> scale_color(data, x, y, firs, third, sec);

                    }else if(col[2] >= col[0]){ //2-0-1

                        c_h -> scale_color(data, x, y, third, firs, sec);

                    }

                }else if(col[1] >= col[0]){

                    if(col[0] >= col[2]){ //1-0-2

                        c_h -> scale_color(data, x, y, sec, firs, third);

                    }else if(col[2] >= col[0]){ //1-2-0

                        c_h -> scale_color(data, x, y, sec, third, firs);

                    }else if(col[2] >= col[1]){ //2-1-0

                        c_h -> scale_color(data, x, y, third, sec, firs);

                    }

                }

            }

        }

    }

    return  true;
}

bool replace_colors(unsigned char *data, std::vector<std::array<unsigned char, 6>> colors, color_handler *c_h, values v){

    std::array<unsigned char, 3> curr_color;
    unsigned char *odata = data;
    int s = colors.size();


    std::cout << "y: " << 0 << " of " << (v.PHW - 1) << std::flush;

    for(int y = 0;  y < v.PHW; y++){

        std::cout << "\ry: " << y << " of " << (v.PHW - 1) << std::flush;

        for(int x = 0; x < v.PHW; x++){

            curr_color = get_color(odata, x, y, v);

            unsigned char r = curr_color[0];
            unsigned char g = curr_color[1];
            unsigned char b = curr_color[2];

            bool found = false;
            int f_pos = 0;

            int top = colors.size()-1;
            int down = 0;

            int icenter;

            unsigned char searched = r;
            int searched_idx = 0;

            while (1) {

                icenter = down + ((top - down) / 2);
                f_pos = icenter;

                if (colors[icenter][searched_idx] == searched) {

                    if (searched_idx == 2) {

                        found = true;
                        break;

                    } else {

                        top = icenter;
                        down = icenter;

                        while (colors[top+1][searched_idx] == searched) {
                            top++;
                        }
                        while (colors[down - 1][searched_idx] == searched) {
                            down--;
                        }

                        if (searched_idx == 0) {
                            searched = g;
                        } else {
                            searched = b;
                        }

                        searched_idx++;

                    }

                } else if (top - down <= 0){

                    break;

                }else if (searched <= colors[icenter][searched_idx]) {

                    top = icenter - 1;

                } else {
                    down = icenter + 1;
                }

            }

            if(found){

                *data = colors[f_pos][3];
                data++;
                *data = colors[f_pos][4];
                data++;
                *data = colors[f_pos][4];
                data++;

            }else{
                data += 3;
            }

        }
    }

    std::cout << " ... finished" << std::endl;

    return true;
}








