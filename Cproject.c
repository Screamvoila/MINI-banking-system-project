#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Structure to hold contact details
struct Contact {
    char name[50];
    char phone[15];
    char email[50];
    char address[100];
};

// Global array and counter
struct Contact contacts[MAX];
int count = 0;

// Function to add a contact
void addContact() {
    if (count >= MAX) {
        printf("\nContact limit reached!\n");
        return;
    }

    printf("\nEnter Name: ");
    fflush(stdin);
    gets(contacts[count].name);

    printf("Enter Phone Number: ");
    gets(contacts[count].phone);

    printf("Enter Email: ");
    gets(contacts[count].email);

    printf("Enter Address: ");
    gets(contacts[count].address);

    count++;
    printf("\nContact added successfully!\n");
}

// Function to display all contacts
void listContacts() {
    int i;
    if (count == 0) {
        printf("\nNo contacts available.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (i = 0; i < count; i++) {
        printf("\nContact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("Email: %s\n", contacts[i].email);
        printf("Address: %s\n", contacts[i].address);
    }
}

// Function to search for a contact by name
void searchContact() {
    char name[50];
    int i, found = 0;

    if (count == 0) {
        printf("\nNo contacts to search.\n");
        return;
    }

    printf("\nEnter name to search: ");
    fflush(stdin);
    gets(name);

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nContact Found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            printf("Address: %s\n", contacts[i].address);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nContact not found!\n");
}

// Function to delete a contact by name
void deleteContact() {
    char name[50];
    int i, j, found = 0;

    if (count == 0) {
        printf("\nNo contacts to delete.\n");
        return;
    }

    printf("\nEnter name to delete: ");
    fflush(stdin);
    gets(name);

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            for (j = i; j < count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            count--;
            found = 1;
            printf("\nContact deleted successfully!\n");
            break;
        }
    }

    if (!found)
        printf("\nContact not found!\n");
}

// Main menu
void main() {
    int choice;
    clrscr();

    while (1) {
        printf("\n===== Simple Address Book =====\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                printf("\nExiting program. Goodbye!\n");
                getch();
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }

        printf("\nPress any key to continue...");
        getch();
        clrscr();
    }
}
