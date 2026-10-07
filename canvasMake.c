#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "canvasMake.h"

    char validChars[] = {'*','@','#','&','+','$'};
    int charListSize = sizeof(validChars) / sizeof(validChars[0]);

    // picks and returns a random character from the provided list
    char pickChar(char *charList, int size){
        return charList[rand() % size];
    }

    // returns a space 80% of the time, and a random char the other 20%
    char genRandomChar(double chance, char *charList, int size){
        if (((double)rand() / RAND_MAX) < chance){
            return pickChar(charList, size);
        }
        return ' ';
    }

    // creates a 2d array (canvas) and fills it with random characters
    char **createCanvas(int width, int height){
        char **canvas = malloc(height * sizeof(char*));
            for (int i = 0; i < height; i++){
                canvas[i] = malloc(width * sizeof(char));
                for (int j = 0; j < width; j++){
                    canvas[i][j] = genRandomChar(0.20, validChars, charListSize);
                }
            }
            return canvas;
    }

    // prints the 2d array 
    char printCanvas(int width, int height, char **canvas){
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                putchar(canvas[i][j]);
            }
            putchar('\n');
        }
    }
 // need to free canvas