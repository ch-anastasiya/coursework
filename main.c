#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "list.h"
#include "files.h"
#include "menu.h"

#define FILENAME "store.csv"

int main() {
    // Read data from file
    FILE *read = fopen(FILENAME, "r");
    List *list = makeList();
    readFile(read, list);
    fclose(read);

    showMenu(list);

    // Save data to file
    FILE *save = fopen(FILENAME, "w");
    saveFile(save, list);
    destroy(list);
    fclose(save);
    return 0;
}