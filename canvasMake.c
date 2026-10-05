#include <stdio.h>
#include <stdlib.h>

    char validChars[] = {'*','@','#','&','+','$'};
    int charListSize = sizeof(validChars) / sizeof(validChars[0]);

    // picks and returns a random character from the provided list
    char pickChar(char *list, int listSize){
        return list[rand() % listSize];
    }
