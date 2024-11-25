#include <stdio.h>
#include "file_handler.h"

void append_to_file(const Contact *contact) {
    FILE *file = fopen("contacts.csv", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s,%s,%s\n", contact->name, contact->phone, contact->email);
    fclose(file);
}

