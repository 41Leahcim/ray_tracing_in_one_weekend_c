#include "color.hpp"

void color_write(FILE *output, const Color pixel_color){
    fprintf(output, "%d %d %d\n",
        (int)(255.999 * pixel_color.elements[0]),
        (int)(255.999 * pixel_color.elements[1]),
        (int)(255.999 * pixel_color.elements[2]));
}
