#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 15
#define MAX_HASHTABLE_SIZE 10

typedef struct person {
    char name[MAX_NAME_LENGTH];
    int age;
    struct person *next;
} person;

person *hash_table[MAX_HASHTABLE_SIZE];

int hash(char *name) {
    unsigned int hash = 0;
    while(*name) {
        hash = hash * 17 + (unsigned char)(*name);
        name++;
    }
    return hash % MAX_HASHTABLE_SIZE;
}

void init_hash_table(void) {
    for (int i = 0; i < MAX_HASHTABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

bool insert(person *person) {
    int index = hash(person->name);
    person->next = hash_table[index];
    hash_table[index] = person;
    return true;
}

int main() {
    init_hash_table();
    printf("Antoine has hash: %d\n", hash("Antoine"));
    printf("Vivienne has hash: %d\n", hash("Vivienne"));
    printf("Daniel has hash: %d\n", hash("Daniel"));
    printf("Tarik has hash: %d\n", hash("Tarik"));
    printf("Isabelle has hash: %d\n", hash("Isabelle"));
    printf("Bernd has hash: %d\n", hash("Bernd"));
    printf("Nina has hash: %d\n", hash("Nina"));
    printf("Brigitte has hash: %d\n", hash("Brigitte"));

    person antoine = {.age = 45, .name="Antoine"};
    insert(&antoine);
    person vivienne = {.age = 45, .name="Vivienne"};
    insert(&vivienne);
    person daniel = {.age = 45, .name="Daniel"};
    insert(&daniel);
    person tarik = {.age = 45, .name="Tarik"};
    insert(&tarik);
    person isabelle = {.age = 45, .name="Isabelle"};
    insert(&isabelle);
    person bernd = {.age = 45, .name="Bernd"};
    insert(&bernd);
    person nina = {.age = 45, .name="Nina"};
    insert(&nina);
    person brigitte = {.age = 45, .name="Brigitte"};
    insert(&brigitte);
    
    for (int i = 0; i < MAX_HASHTABLE_SIZE; i++) {
        if (hash_table[i] != NULL) {
            person *tmp = hash_table[i];
            while (tmp != NULL) {
                printf("%s\n", tmp->name);
                tmp = tmp->next;
            }
            printf("NULL\n");
        } else {
            printf("NULL\n");
        }
        
    }
    return 1;
}