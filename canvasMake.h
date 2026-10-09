// Kat Jean, Homework 3, No help

#ifndef CANVAS_MAKE_H
#define CANVAS_MAKE_H

char pickChar(char *charList, int size);

char genRandomChar(double chance, char chosenChar);

char **createCanvas(int width, int height);

void printCanvas(int width, int height, char **canvas);

void freeCanvas(char **canvas, int wisth, int height);


#endif 