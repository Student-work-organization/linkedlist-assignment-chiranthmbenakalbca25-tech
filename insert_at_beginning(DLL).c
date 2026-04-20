#include <stdio.h>
#include <stdlib.h>

// Node structure for DLL
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Head pointer
struct Node *head = NULL;

// Insert at beginning (DLL)
void insert_at_beginning(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;

    // If list is not empty
    if (head != NULL) {
        head->prev = new_node;
    }

    head = new_node;
}

// Display list
void traverse() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    insert_at_beginning(30);
    insert_at_beginning(20);
    insert_at_beginning(10);

    printf("Doubly Linked List:\n");
    traverse();

    return 0;
}