#include <string.h>
#include "list.h"
#include "files.h"

void swap(BookItem *a, BookItem *b) {
    int id = a->id;
    char *name = initStringField(a->nameBook);
    char *author = initStringField(a->nameAuthor);
    int year = a->year;
    int pieces = a->piecesAvailable;
    double price = a->price;
    double rating = a->readerRating;

    a->id = b->id;
    a->nameBook = b->nameBook;
    a->nameAuthor = b->nameAuthor;
    a->year = b->year;
    a->piecesAvailable = b->piecesAvailable;
    a->price = b->price;
    a->readerRating = b->readerRating;

    b->id = id;
    b->nameBook = name;
    b->nameAuthor = author;
    b->year = year;
    b->piecesAvailable = pieces;
    b->price = price;
    b->readerRating = rating;
}

void sortById(List *list) {
    int swapped;
    BookItem *shopItem;
    BookItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (BookItem *) shopItem->next;
            if (shopItem->id > shopItemNext->id) {
                swap(shopItem, (BookItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (BookItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByName(List *list) {
    int swapped;
    BookItem *shopItem;
    BookItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (BookItem *) shopItem->next;
            if (strcmp(shopItem->nameBook, shopItemNext->nameBook) > 0) {
                swap(shopItem, (BookItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (BookItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByAuthor(List *list) {
    int swapped;
    BookItem *shopItem;
    BookItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (BookItem *) shopItem->next;
            if (strcmp(shopItem->nameAuthor, shopItemNext->nameAuthor) > 0) {
                swap(shopItem, (BookItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (BookItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByYear(List *list) {
    int swapped;
    BookItem *shopItem;
    BookItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (BookItem *) shopItem->next;
            if (shopItem->year > shopItemNext->year) {
                swap(shopItem, (BookItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (BookItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByPieces(List *list) {
    int swapped;
    BookItem *shopItem;
    BookItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (BookItem *) shopItem->next;
            if (shopItem->piecesAvailable > shopItemNext->piecesAvailable) {
                swap(shopItem, (BookItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (BookItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByPrice(List *list) {
    int swapped;
    BookItem *shopItem;
    BookItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (BookItem *) shopItem->next;
            if (shopItem->price > shopItemNext->price) {
                swap(shopItem, (BookItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (BookItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}

void sortByRating(List *list) {
    int swapped;
    BookItem *shopItem;
    BookItem *shopItemNext = NULL;

    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        shopItem = list->head;

        while (shopItem->next != NULL) {
            shopItemNext = (BookItem *) shopItem->next;
            if (shopItem->readerRating > shopItemNext->readerRating) {
                swap(shopItem, (BookItem *) shopItem->next);
                swapped = 1;
            }
            shopItem = (BookItem *) shopItem->next;
        }
        shopItem = shopItemNext;
    } while (swapped);
}