#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "list.h"
#include "files.h"
#include "enter.h"
#include "search.h"
#include "sort.h"

// For adaptive clear screen
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

BookItem *readItem(BookItem *book) {
    book->nameBook = readString("Name: ");
    book->nameAuthor = readString("Author: ");

    book->year = readInt("Year: ");
    book->piecesAvailable = readInt("Pieces: ");

    book->price = readDouble("Price: ");
    book->readerRating = readDouble("Rating: ");

    return book;
}

void showAdd(List *list) {
    BookItem *bookItem = malloc(sizeof(BookItem));

    system(CLEAR);

    readItem(bookItem);

    add(bookItem, list);
    puts("Was added to library");
    printf("Anything to continue: ");
    getch();
}

void showEdit(List *list) {
    int id = 0;

    system(CLEAR);

    id = readInt("ID: ");

    BookItem *bookItem = get(id, list);

    if (bookItem == NULL) {
        puts("There is no such id");
        printf("Anything to continue: ");
        getch();
    } else {
        readItem(bookItem);

        puts("Item wad edited");
        printf("Anything to continue: ");
        getch();
    }
}

void showDelete(List *list) {
    int id = 0;

    system(CLEAR);
    id = readInt("ID: ");
    BookItem *bookItem = get(id, list);

    if (bookItem == NULL) {
        puts("There is no such id");
        printf("Anything to continue: ");
        getch();
    } else {
        delete(id, list);
        puts("Item wad deleted");
        printf("Anything to continue: ");
        getch();
    }
}

void showList(List *list) {
    system(CLEAR);
    display(list);
    printf("Anything to continue: ");
    getch();
}

void showSearchMenu(List *list) {
    int id = 0;
    system(CLEAR);
    puts("0. ID");
    puts("1. Name");
    puts("2. Author");
    puts("3. Year");
    puts("4. Pieces");
    puts("5. Price");
    puts("6. Rating");
    id = readInt("Field: ");

    if (id == 0) {
        id = readInt("Id: ");
        puts("");
        getSearchListById(list, id);
    } else if (id == 1) {
        char *name = readString("Name: ");
        puts("");
        getSearchListByName(list, name);
    } else if (id == 2) {
        char *author = readString("Author: ");
        puts("");
        getSearchListByAuthor(list, author);
    } else if (id == 3) {
        int year = readInt("Year: ");
        puts("");
        getSearchListByYear(list, year);
    } else if (id == 4) {
        int pieces = readInt("Pieces of items: ");
        puts("");
        getSearchListByPieces(list, pieces);
    } else if (id == 5) {
        double price = readInt("Price: ");
        puts("");
        getSearchListByPrice(list, price);
    } else if (id == 6) {
        double rating = readDouble("Rating: ");
        puts("");
        getSearchListByRating(list, rating);
    }
    printf("Anything to continue: ");
    getch();
}

void showSortMenu(List *list) {
    int id = 0;
    system(CLEAR);
    puts("0. ID");
    puts("1. Name");
    puts("2. Author");
    puts("3. Year");
    puts("4. Pieces");
    puts("5. Price");
    puts("6. Rating");
    id = readInt("Field: ");

    if (id == 0) {
        sortById(list);
    } else if (id == 1) {
        sortByName(list);
    } else if (id == 2) {
        sortByAuthor(list);
    } else if (id == 3) {
        sortByYear(list);
    } else if (id == 4) {
        sortByPieces(list);
    } else if (id == 5) {
        sortByPrice(list);
    } else if (id == 6) {
        sortByRating(list);
    }
    puts("List was sorted");
    printf("Anything to continue: ");
    getch();
}

void showMenu(List *list) {
    int menu = 0;
    while (menu != 6) {
        system(CLEAR);
        puts("0. Add new note");
        puts("1. Edit note");
        puts("2. Delete note");
        puts("3. Print list");
        puts("4. Search");
        puts("5. Sort");
        puts("6. Exit");
        menu = readInt("Menu: ");

        if (menu == 0) {
            showAdd(list);
        } else if (menu == 1) {
            showEdit(list);
        } else if (menu == 2) {
            showDelete(list);
        } else if (menu == 3) {
            showList(list);
        } else if (menu == 4) {
            showSearchMenu(list);
        } else if (menu == 5) {
            showSortMenu(list);
        }
    }
}