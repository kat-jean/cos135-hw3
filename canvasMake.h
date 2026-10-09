// Kat Jean, Homework 3, No help

#ifndef CANVAS_MAKE_H
#define CANVAS_MAKE_H

char static pickChar(char *charList, int size);

char static genRandomChar(double chance, char chosenChar);

char static **createCanvas(int width, int height);

void static printCanvas(int width, int height, char **canvas);

void static freeCanvas(char **canvas, int wisth, int height);


#endif 