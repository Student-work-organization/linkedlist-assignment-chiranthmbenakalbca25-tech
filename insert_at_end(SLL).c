#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insert_at_beginning(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void insert_at_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct Node* curr = head;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
}

void traverse() {
    struct Node* curr = head;
    printf("List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {

    insert_at_beginning(3);
    insert_at_beginning(2);
    insert_at_beginning(1);

    traverse();

    insert_at_end(4);
    insert_at_end(5);

    printf("\nAfter insert at end:\n");
    traverse();

    return 0;
}