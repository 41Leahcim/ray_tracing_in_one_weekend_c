#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int main(){
    // Start measuring time
    clock_t start = clock();

    // Image properties
    const int IMAGE_WIDTH = 4096;
    const int IMAGE_HEIGHT = 4096;

    // Rendering
    printf("P3\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);

    for(int y = IMAGE_HEIGHT - 1;y >= 0;y--){
        for(int x = 0;x < IMAGE_WIDTH;x++){
            double red_double = (double)x / (IMAGE_WIDTH - 1);
            double green_double = (double)y / (IMAGE_HEIGHT - 1);
            double blue_double = 0.25;
            int red_int = (int)(255.999 * red_double);
            int green_int = (int)(255.999 * green_double);
            int blue_int = (int)(255.999 * blue_double);
            printf("%d %d %d\n", red_int, green_int, blue_int);
        }
    }

    // Print time
    fprintf(stderr, "%lf\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}
