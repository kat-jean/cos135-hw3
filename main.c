// Kat Jean, Homework 3, No help

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "canvasMake.h"

int main(int argc, char **argv){
    // check if valid number of arguments (mostly taken from sept30.c in class code)
    if (argc != 3){
        printf("Usage: %s <width> <height>\n", argv[0]);
        return 1;
    }
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    if (width <= 0 || height <= 0){
        printf("Width and height must be positive integers.\n");
        return 1;
    }

    // set the rng
    srand(time(NULL));

    // create, print, and free the canvas
    char **canvas = createCanvas(width, height);
    printCanvas(width, height, canvas);
    freeCanvas(canvas, width, height);

    return 0;
}
