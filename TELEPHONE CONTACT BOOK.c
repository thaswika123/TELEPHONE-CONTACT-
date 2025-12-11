#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[15];
    char email[50];
};

void addContact() {
    struct Contact c;
    FILE *fp = fopen("contacts.txt", "a"); // append mode

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter Name  : ");
    scanf(" %[^\n]", c.name);

    printf("Enter Phone : ");
    scanf(" %[^\n]", c.phone);

    printf("Enter Email : ");
    scanf(" %[^\n]", c.email);

    fprintf(fp, "%s,%s,%s\n", c.name, c.phone, c.email);

    fclose(fp);
    printf("\nContact Added Successfully!\n");
}

void viewContacts() {
    struct Contact c;
    FILE *fp = fopen("contacts.txt", "r");

    if (fp == NULL) {
        printf("\nNo contacts found!\n");
        return;
    }

    printf("\n----- Contact List -----\n");

    while (fscanf(fp, " %[^,],%[^,],%[^\n]\n", c.name, c.phone, c.email) != EOF) {
        printf("\nName  : %s\nPhone : %s\nEmail : %s\n", 
                c.name, c.phone, c.email);
        printf("------------------------\n");
    }

    fclose(fp);
}

void searchContact() {
    char searchName[50];
    struct Contact c;
    int found = 0;

    FILE *fp = fopen("contacts.txt", "r");

    if (fp == NULL) {
        printf("\nNo contacts found!\n");
        return;
    }

    printf("\nEnter name to search: ");
    scanf(" %[^\n]", searchName);

    while (fscanf(fp, " %[^,],%[^,],%[^\n]\n", c.name, c.phone, c.email) != EOF) {
        if (strcasecmp(c.name, searchName) == 0) {
            printf("\nContact Found!\n");
            printf("\nName  : %s\nPhone : %s\nEmail : %s\n", 
                    c.name, c.phone, c.email);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nContact Not Found!\n");

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n====== TELEPHONE CONTACT BOOK ======\n");
        printf("1. Add Contact\n");
        printf("2. View Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: 
                printf("\nExiting... Thank you!\n");
                exit(0);
            default:
                printf("\nInvalid Choice! Try again.\n");
        }
    }

    return 0;
}