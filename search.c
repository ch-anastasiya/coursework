#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

void getSearchListById(List *list, int id) {
    BookItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->id == id) {
            printf("%d. Name: %s\nAuthor: %s\nYear: %d\nPieces: %d\nPrice: %lf\nRating: %lf\n\n", current->id,
                   current->nameBook, current->nameAuthor, current->year, current->piecesAvailable, current->price, current->readerRating);
            c++;
        }
        current = (BookItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByName(List *list, char *nameBook) {
    BookItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(strcmp(current->nameBook, nameBook) == 0) {
            printf("%d. Name: %s\nAuthor: %s\nYear: %d\nPieces: %d\nPrice: %lf\nRating: %lf\n\n", current->id,
                   current->nameBook, current->nameAuthor, current->year, current->piecesAvailable, current->price, current->readerRating);
            c++;
        }
        current = (BookItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByAuthor(List *list, char *nameAuthor) {
    BookItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(strcmp(current->nameAuthor, nameAuthor) == 0) {
            printf("%d. Name: %s\nAuthor: %s\nYear: %d\nPieces: %d\nPrice: %lf\nRating: %lf\n\n", current->id,
                   current->nameBook, current->nameAuthor, current->year, current->piecesAvailable, current->price, current->readerRating);
            c++;
        }
        current = (BookItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByYear(List *list, int year) {
    BookItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->year == year) {
            printf("%d. Name: %s\nAuthor: %s\nYear: %d\nPieces: %d\nPrice: %lf\nRating: %lf\n\n", current->id,
                   current->nameBook, current->nameAuthor, current->year, current->piecesAvailable, current->price, current->readerRating);
            c++;
        }
        current = (BookItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByPieces(List *list, int pieces) {
    BookItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->piecesAvailable == pieces) {
            printf("%d. Name: %s\nAuthor: %s\nYear: %d\nPieces: %d\nPrice: %lf\nRating: %lf\n\n", current->id,
                   current->nameBook, current->nameAuthor, current->year, current->piecesAvailable, current->price, current->readerRating);
            c++;
        }
        current = (BookItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByPrice(List *list, double price) {
    BookItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->price == price) {
            printf("%d. Name: %s\nAuthor: %s\nYear: %d\nPieces: %d\nPrice: %lf\nRating: %lf\n\n", current->id,
                   current->nameBook, current->nameAuthor, current->year, current->piecesAvailable, current->price, current->readerRating);
            c++;
        }
        current = (BookItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}

void getSearchListByRating(List *list, double readerRating) {
    BookItem *current = list->head;
    int c = 0;
    while (current != NULL) {
        if(current->readerRating == readerRating) {
            printf("%d. Name: %s\nAuthor: %s\nYear: %d\nPieces: %d\nPrice: %lf\nRating: %lf\n\n", current->id,
                   current->nameBook, current->nameAuthor, current->year, current->piecesAvailable, current->price, current->readerRating);
            c++;
        }
        current = (BookItem *) current->next;
    }
    if(c == 0) {
        puts("List is empty");
    }
}
