#include "stdlib.h"
#include "stdio.h"
#include "list.h"
#include "item.h"

List *makeList() {
    List *list = malloc(sizeof(List));
    if (!list) {
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

void add(BookItem *item, List *list) {
    BookItem *current = NULL;
    item->next = NULL;
    item->id = 0;

    if (list->head == NULL) {
        list->head = item;
    } else {
        item->id++;
        current = list->head;
        while (current->next != NULL) {
            item->id++;
            current = (BookItem *) current->next;
        }
        current->next = (struct BookItem *) item;
    }
}

BookItem *get(int id, List *list) {
    BookItem *current = list->head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = (BookItem *) current->next;
    }
    return NULL;
}

int delete(int id, List *list) {
    BookItem *current = list->head;
    BookItem *previous = current;
    while (current != NULL) {
        if (current->id == id) {
            previous->next = current->next;
            if (current == list->head)
                list->head = (BookItem *) current->next;
            free(current);
            return 1;
        }
        previous = current;
        current = (BookItem *) current->next;
    }
    return 0;
}

void display(List *list) {
    BookItem *current = list->head;
    if (current == NULL) {
        printf("List is empty\n");
        return;
    }

    while (current != NULL) {
        printf("%d. Name: %s\nAuthor: %s\nYear: %d\nPieces: %d\nPrice: %lf\nRating: %lf\n\n", current->id,
               current->nameBook, current->nameAuthor, current->year, current->piecesAvailable, current->price, current->readerRating);
        current = (BookItem *) current->next;
    }
}

void destroy(List *list) {
    BookItem *current = list->head;
    BookItem *next = current;
    while (current != NULL) {
        next = (BookItem *) current->next;
        free(current);
        current = next;
    }
    free(list);
}