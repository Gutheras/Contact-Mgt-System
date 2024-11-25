#include <stdio.h>
#include <string.h>
#include "contact.h"
#include "file_handler.h"

void add_contact(Contact *contact) {
    append_to_file(contact);
    printf("Contact added successfully.\n");
}

void search_contact(const char *query) {
    FILE *file = fopen("contacts.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Contact contact;
    int found = 0;
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", contact.name, contact.phone, contact.email) != EOF) {
        if (strstr(contact.name, query) != NULL || strstr(contact.phone, query) != NULL) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n\n", contact.name, contact.phone, contact.email);
            found = 1;
        }
    }

    if (!found) {
        printf("No contacts found matching the query.\n");
    }

    fclose(file);
}

void edit_contact(const char *name) {
    FILE *file = fopen("contacts.csv", "r");
    FILE *temp = fopen("temp.csv", "w");
    if (file == NULL || temp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Contact contact;
    int found = 0;
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", contact.name, contact.phone, contact.email) != EOF) {
        if (strcmp(contact.name, name) == 0) {
            printf("Enter new phone number: ");
            scanf("%s", contact.phone);
            printf("Enter new email: ");
            scanf("%s", contact.email);
            found = 1;
        }
        fprintf(temp, "%s,%s,%s\n", contact.name, contact.phone, contact.email);
    }

    fclose(file);
    fclose(temp);

    remove("contacts.csv");
    rename("temp.csv", "contacts.csv");

    if (found) {
        printf("Contact updated successfully.\n");
    } else {
        printf("Contact not found.\n");
    }
}

void delete_contact(const char *name) {
    FILE *file = fopen("contacts.csv", "r");
    FILE *temp = fopen("temp.csv", "w");
    if (file == NULL || temp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Contact contact;
    int found = 0;
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", contact.name, contact.phone, contact.email) != EOF) {
        if (strcmp(contact.name, name) != 0) {
            fprintf(temp, "%s,%s,%s\n", contact.name, contact.phone, contact.email);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    remove("contacts.csv");
    rename("temp.csv", "contacts.csv");

    if (found) {
        printf("Contact deleted successfully.\n");
    } else {
        printf("Contact not found.\n");
    }
}

void list_contacts() {
    FILE *file = fopen("contacts.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    Contact contact;
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", contact.name, contact.phone, contact.email) != EOF) {
        printf("Name: %s\nPhone: %s\nEmail: %s\n\n", contact.name, contact.phone, contact.email);
    }

    fclose(file);
}