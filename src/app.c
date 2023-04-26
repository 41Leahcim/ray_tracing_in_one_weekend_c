#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "color.hpp"

int main(){
    // Start measuring time
    clock_t start = clock();

    // Image properties
    const int IMAGE_WIDTH = 2048;
    const int IMAGE_HEIGHT = 4096;

    // Rendering
    printf("P3\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);

    for(int y = IMAGE_HEIGHT - 1;y >= 0;y--){
        fprintf(stderr, "\rscanlines remaining: %-4d", y);
        fflush(stderr);
        for(int x = 0;x < IMAGE_WIDTH;x++){
            Color pixel_color = {{
                (double)x / (IMAGE_WIDTH - 1),
                (double)y / (IMAGE_HEIGHT - 1),
                0.25
            }};
            color_write(stdout, pixel_color);
        }
    }
    fprintf(stderr, "\nDone\n");

    // Print time
    fprintf(stderr, "%lf\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}
