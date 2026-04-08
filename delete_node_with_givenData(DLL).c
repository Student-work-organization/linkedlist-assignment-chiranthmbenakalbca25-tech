#include <stdio.h>
#include <stdlib.h>

struct DoublyNode {
    int data;
    struct DoublyNode *prev, *next;
};

struct DoublyNode *head = NULL;

void insert(int data) {
    struct DoublyNode *new_node = malloc(sizeof(struct DoublyNode));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL)
        head->prev = new_node;

    head = new_node;
}

// Insert after key
void insert_after_key(int key, int data) {
    struct DoublyNode *curr = head;

    while (curr != NULL && curr->data != key)
        curr = curr->next;

    if (curr == NULL) {
        printf("Key not found\n");
        return;
    }

    struct DoublyNode *new_node = malloc(sizeof(struct DoublyNode));
    new_node->data = data;

    new_node->next = curr->next;
    new_node->prev = curr;

    if (curr->next != NULL)
        curr->next->prev = new_node;

    curr->next = new_node;
}

void display() {
    struct DoublyNode *t = head;
    while (t != NULL) {
        printf("%d <-> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
}

int main() {
    insert(3); insert(2); insert(1);

    display();
    insert_after_key(2, 5);
    display();
}