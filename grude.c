#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char phone[20];
    char email[50];
} data;

void displayMenu() {
    // Displaying menu options
    printf("Menu:\n");
    printf("1 - Add a contact\n");
    printf("2 - Show contact\n");
    printf("3 - Update a contact\n");
    printf("4 - Delete a contact\n");
    printf("5 - Find empty contact\n");
    printf("6 - Exit\n");
}

void press_enter() {
    // Clear input buffer
    setbuf(stdin, NULL);
    printf("Press Enter to continue:\n");
    while (getchar() != '\n');
}

void addContact(data contacts[], int *count) {
    // Adding a contact by taking user input
    printf("Enter a name: ");
    fgets(contacts[*count].name, 20, stdin);
    printf("Enter a phone number: ");
    fgets(contacts[*count].phone, 20, stdin);
    printf("Enter an email: ");
    fgets(contacts[*count].email, 50, stdin);
    (*count)++;
}

void showContact(data contacts[], int number) {
    // Displaying a contact's details
    printf("Name: %s", contacts[number].name);
    printf("Phone: %s", contacts[number].phone);
    printf("Email: %s", contacts[number].email);
}

void updateContact(data contacts[], int number) {
    // Updating contact details by taking user input
    getchar();
    printf("Enter a new name: ");
    fgets(contacts[number].name, 20, stdin);
    printf("Enter a new phone number: ");
    fgets(contacts[number].phone, 20, stdin);
    printf("Enter a new email: ");
    fgets(contacts[number].email, 50, stdin);
}

void deleteContact(data contacts[], int number) {
    // Deleting a contact by clearing its fields
    strcpy(contacts[number].name, "");
    strcpy(contacts[number].phone, "");
    strcpy(contacts[number].email, "");
}

void findEmptyIndex(data contacts[], int count) {
    // Finding an empty contact slot in the array
    int foundEmpty = 0;
    for (int i = 0; i < count; i++) {
        if (contacts[i].name[0] == '\0' && contacts[i].phone[0] == '\0' && contacts[i].email[0] == '\0') {
            printf("Empty contact found at index %d\n", i);
            foundEmpty = 1;
        }
    }
    if (!foundEmpty) {
        printf("No empty contacts found.\n");
    }
}

int main() {
    int choice, count = 0, number = 0;
    data contacts[100];

    do {
        system("clear");
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();
        system("clear");

        switch (choice) {
            case 1:
                addContact(contacts, &count);
                printf("Contact added successfully.\n");
                press_enter();
                break;
            case 2:
                printf("Enter the contact number to display: ");
                scanf("%d", &number);
                showContact(contacts, number);
                press_enter();
                break;
            case 3:
                printf("Enter the contact number to update: ");
                scanf("%d", &number);
                updateContact(contacts, number);
                press_enter();
                break;
            case 4:
                printf("Enter the contact number to delete: ");
                scanf("%d", &number);
                deleteContact(contacts, number);
                press_enter();
                break;
            case 5:
                findEmptyIndex(contacts, count);
                press_enter();
                break;
            case 6:
                break;
            default:
                printf("Invalid option. Try again.\n");
                continue;
        }
    } while (choice != 6);

    return 0;
}
