#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char email[50];
    char number[50];
};

struct ContactArray {
    struct Contact *data;
    int size;
    int capacity;
};

typedef enum {
    DELETE_OK,
    DELETE_NOT_FOUND
} DeleteStatus;

void printContacts(struct ContactArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%s, %s, %s\n",
               arr->data[i].name,
               arr->data[i].email,
               arr->data[i].number);
    }
}

void addContact(struct ContactArray *arr, struct Contact newContact) {
    if(arr->size == arr->capacity) {
        int newCap = (arr->capacity == 0) ? 1 : arr->capacity * 2;
        arr->data = realloc(arr->data, newCap * sizeof(struct Contact));
        arr->capacity = newCap;
    }
    arr->data[arr->size] = newContact;
    arr->size++;
}

DeleteStatus deleteContact(struct ContactArray *arr, char *name) {
    for (int i= 0; i < arr->size; i++) {
        if (strcmp(arr->data[i].name, name) == 0) {
            arr->data[i] = arr->data[arr->size - 1];
            arr->size --;
            return DELETE_OK;
        }
    }
    return DELETE_NOT_FOUND;
}

int main() {
    struct ContactArray arr = {NULL, 0, 0};

    struct Contact c1 = {"Alice", "alice@mail.com", "12345"};
    struct Contact c2 = {"Bob", "bob@mail.com", "67890"};
    struct Contact c3 = {"Charlie", "charlie@mail.com", "54321"};

    addContact(&arr, c1);
    addContact(&arr, c2);
    addContact(&arr, c3);

    printf("All contacts:\n");
    printContacts(&arr);

    printf("\nDeleting Bob...\n");
    DeleteStatus status = deleteContact(&arr, "Bob");
    if (status == DELETE_OK) {
        printf("Deleted Bob successfully.\n");
    } else {
        printf("Couldnt find Bob.\n");
    }

    printf("\nAll contacts:\n");
    printContacts(&arr);

    free(arr.data);
    return 0;
}