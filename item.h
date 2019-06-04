#ifndef COURSEWORK_ITEM_H
#define COURSEWORK_ITEM_H

typedef struct {
    int id;
    char *nameBook;
    char *nameAuthor;
    int year;
    int piecesAvailable;
    double price;
    double readerRating;
    struct BookItem *next;
} BookItem;

#endif //COURSEWORK_ITEM_H
