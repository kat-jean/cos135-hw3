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





    /*
    int width = 10;
    int height = 8;

    char **charGrid = malloc(sizeof(*char) * width); // reserves the "first layer"
    // charGrid is an array of char pointers

    // expand one pointer to look at 'height' size array or characters
    charGrid[0] = malloc(sizeof(*char) * height); 
    */