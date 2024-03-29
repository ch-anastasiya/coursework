#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "list.h"
#include "files.h"

int readInt(char *message) {
    char string[1024];
    int result = 0;
    while (result != 1) {
        int i = 0;
        result = 1;
        printf(message);
        scanf("%s", &string);
        while (string[i] != '\0') {
            if(!isdigit(string[i])) {
                result = 0;
            }
            i++;
        }
    }
    return atoi(string);
}

double readDouble(char *message) {
    char string[1024];
    int result = 0;
    while (result != 1) {
        int i = 0;
        result = 1;
        printf(message);
        scanf("%s", &string);
        while (string[i] != '\0') {
            if(!isdigit(string[i]) && string[i] != '.') {
                result = 0;
            }
            i++;
        }
    }
    return atof(string);
}

char *readString(char *message) {
    char str[1024];
    int result = 0;
    while (result != 1) {
        int i = 0;
        result = 1;
        printf(message);
        scanf("%s", str);
        while (str[i] != '\0') {
            if(str[i] == ';') {
                result = 0;
            }
            i++;
        }
    }
    return initStringField(str);
}