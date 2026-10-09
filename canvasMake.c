// Kat Jean, Homework 3, No help

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "canvasMake.h"

    char validChars[] = {'*','@','#','&','+','$'};
    int charListSize = sizeof(validChars) / sizeof(validChars[0]);

    // purpose: picks and returns a random character from the provided list
    // parameters: charList = array of valid characters; size = number of elements in charList
    // return value: a single randomly selected character
    static char pickChar(char *charList, int size){
        return charList[rand() % size];
    }

    // return value: returns a space 80% of the time, and a random char the other 20%
    // parameters: 
    // chance = double representing the probability of placing a char
    // chosenChar = the char selected
    // purpose: to determine whether to place the chosenChar or a space
    static char genRandomChar(double chance, char chosenChar){
        if (((double)rand() / RAND_MAX) < chance){
            return chosenChar;
        }
        return ' ';
    }

    // purpose: creates a 2d array (canvas) and fills it with random characters
    // return value: pointer to a 2d char array (char**)
    // parameters: width = columns of the canvas ; height = rows of the canvas
    char **createCanvas(int width, int height){
        char chosenChar = pickChar(validChars, charListSize);
        char **canvas = malloc(height * sizeof(char*)); // foundation of createCanvas code taken from sept30.c (done in class)
            for (int i = 0; i < height; i++){
                canvas[i] = malloc(width * sizeof(char));
                for (int j = 0; j < width; j++){
                    canvas[i][j] = genRandomChar(0.20, chosenChar);
                }
            }
            return canvas;
    }

    // purpose: iterates through the 2d canvas array and prints each char
    // parameters: width = columns of the canvas ; height = rows of the canvas ; canvas = 2d array containing canvas chars
    // return value: void
    void printCanvas(int width, int height, char **canvas){
        for (int i = 0; i < height; i++){
            for (int j = 0; j < width; j++){
                putchar(canvas[i][j]);
            }
            putchar('\n');
        }
    }
    // parameters: canvas = 2d array to be freed ; width = columns of the canvas ; height = rows of the canvas
    // purpose: frees each allocated row array, then frees main row-pointer array
    // return value: void
    void freeCanvas(char **canvas, int width, int height){
        for (int i = 0; i < height; i++){
            free(canvas[i]);
        }
        free(canvas);
    }
