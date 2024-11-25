#ifndef CONTACT_H
#define CONTACT_H

#define MAX_NAME 50
#define MAX_PHONE 15
#define MAX_EMAIL 50

typedef struct {
    char name[MAX_NAME];
    char phone[MAX_PHONE];
    char email[MAX_EMAIL];
} Contact;

void add_contact(Contact *contact);
void search_contact(const char *query);
void edit_contact(const char *name);
void delete_contact(const char *name);
void list_contacts();

#endif // CONTACT_H

