// Kat Jean, Homework 3, No help

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "canvasMake.h"

    char validChars[] = {'*','@','#','&','+','$'};
    int charListSize = sizeof(validChars) / sizeof(validChars[0]);

    // picks and returns a random character from the provided list
    // parameters: charList = array of valid characters; size = number of elements in charList
    // return value: a single randomly selected character
    char pickChar(char *charList, int size){
        return charList[rand() % size];
    } // doesn't seem to be working right... returns all valid characters instead of only 1.

    // returns a space 80% of the time, and a random char the other 20%
    char genRandomChar(double chance, char *charList, int size){
        if (((double)rand() / RAND_MAX) < chance){
            return pickChar(charList, size);
        }
        return ' ';
    }

    // creates a 2d array (canvas) and fills it with random characters
    char **createCanvas(int width, int height){
        char chosenChar = pickChar(validChars, charListSize);
        char **canvas = malloc(height * sizeof(char*)); // foundation of createCanvas code taken from sept30.c (done in class)
            for (int i = 0; i < height; i++){
                canvas[i] = malloc(width * sizeof(char));
                for (int j = 0; j < width; j++){
                    canvas[i][j] = genRandomChar(0.20, validChars, charListSize);
                }
            }
            return canvas;
    }

    // prints the 2d array 
    void printCanvas(int width, int height, char **canvas){
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                putchar(canvas[i][j]);
            }
            putchar('\n');
        }
    }
    // need to free canvas
    void freeCanvas(char **canvas, int width, int height){
        for (int i = 0; i < height; i++){
            free(canvas[i]);
        }
        free(canvas);
    }
