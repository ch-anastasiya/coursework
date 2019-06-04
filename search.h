#ifndef COURSEWORK_SEARCH_H
#define COURSEWORK_SEARCH_H

#include "list.h"

void getSearchListById(List *list, int id);

void getSearchListByName(List *list, char *nameBook);

void getSearchListByAuthor(List *list, char *authorName);

void getSearchListByYear(List *list, int year);

void getSearchListByPieces(List *list, int piecesAvailable);

void getSearchListByPrice(List *list, double price);

void getSearchListByRating(List *list, double readerRating);

#endif //COURSEWORK_SEARCH_H
