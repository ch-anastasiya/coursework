#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

int getStringSize(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i + 1;
}

char *initStringField(char *string) {
    int len = getStringSize(string);
    char *str = (char *) malloc(len * sizeof(char));

    strcpy(str, string);
    return str;
}

void readFile(FILE *file, List *list) {
    if (file != NULL) {
        char scanner[1024];
        while (fgets(scanner, 1024, file)) {
            BookItem *item = malloc(sizeof(BookItem));
            int count = 0;
            char *words = strtok(scanner, ";");
            while (words != NULL) {
                if(count == 0) {
                    item->nameBook = initStringField(words);
                }
                else if(count == 1) {
                    item->nameAuthor = initStringField(words);
                }
                else if(count == 2) {
                    item->year = atoi(words);
                }
                else if(count == 3) {
                    item->piecesAvailable = atoi(words);
                }
                else if(count == 4) {
                    item->price = atof(words);
                }
                else if(count == 5) {
                    item->readerRating = atof(words);
                }

                count++;
                words = strtok(NULL, ";,");
            }

            add(item, list);
        }
    }
}

void saveFile(FILE *file, List *list) {
    BookItem *current = list->head;
    if (current == NULL)
        return;

    while (current != NULL) {
        fprintf(file, "%s;%s;%d;%d;%lf;%lf\n", current->nameBook, current->nameAuthor, current->year, current->piecesAvailable, current->price, current->readerRating);
        current = (BookItem *) current->next;
    }
}
