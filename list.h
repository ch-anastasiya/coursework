#ifndef COURSEWORK_LIST_H
#define COURSEWORK_LIST_H

#include "item.h"

typedef struct {
    BookItem *head;
    int size;
} List;

/* Init Array */
List *makeList();

/* Create new node */
void add(BookItem *item, List *list);

/* Get node by id */
BookItem *get(int id, List *list);

/* Delete note by id */
int delete(int id, List *list);

/* Write all list */
void display(List *list);

/* Destroy List */
void destroy(List *list);

#endif //COURSEWORK_LIST_H
