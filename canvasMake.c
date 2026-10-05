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