#include <stdio.h>
#include <stdlib.h>
#include "canvasMake.h"

    char validChars[] = {'*','@','#','&','+','$'};
    int charListSize = sizeof(validChars) / sizeof(validChars[0]);

    // picks and returns a random character from the provided list
    char pickChar(char *list, int listSize){
        return list[rand() % listSize];
    }

    // returns a space 80% of the time, and a random char the other 20%
    char genRandomChar(double chance, char *list, int listSize){
        if (((double)rand() / RAND_MAX) < chance){
            return pickChar(list, listSize);
        }
        return ' ';
    }