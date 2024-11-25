#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"

void print_menu() {
    printf("\nContact Management System\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Edit Contact\n");
    printf("4. Delete Contact\n");
    printf("5. List All Contacts\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    Contact contact;
    char query[MAX_NAME];

    while (1) {
        print_menu();
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(contact.name, MAX_NAME, stdin);
                contact.name[strcspn(contact.name, "\n")] = 0; // Remove the newline
                printf("Enter phone number: ");
                fgets(contact.phone, MAX_PHONE, stdin);
                contact.phone[strcspn(contact.phone, "\n")] = 0;
                printf("Enter email: ");
                fgets(contact.email, MAX_EMAIL, stdin);
                contact.email[strcspn(contact.email, "\n")] = 0;
                add_contact(&contact);
                break;
            case 2:
                printf("Enter name or phone number to search: ");
                fgets(query, MAX_NAME, stdin);
                query[strcspn(query, "\n")] = 0;
                search_contact(query);
                break;
            case 3:
                printf("Enter name of contact to edit: ");
                fgets(query, MAX_NAME, stdin);
                query[strcspn(query, "\n")] = 0;
                edit_contact(query);
                break;
            case 4:
                printf("Enter name of contact to delete: ");
                fgets(query, MAX_NAME, stdin);
                query[strcspn(query, "\n")] = 0;
                delete_contact(query);
                break;
            case 5:
                list_contacts();
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

