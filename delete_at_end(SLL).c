#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Head pointer
struct Node *head = NULL;

// Insert at beginning (for testing)
void insert_at_beginning(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// Delete last node
void delete_end_node() {
    struct Node *temp = head;
    struct Node *prev = NULL;

    // Case 1: Empty list
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Case 2: Only one node
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    // Traverse to last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    // Delete last node
    prev->next = NULL;
    free(temp);
}

// Traverse (display)
void traverse() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main() {
    insert_at_beginning(30);
    insert_at_beginning(20);
    insert_at_beginning(10);

    printf("Original List:\n");
    traverse();

    delete_end_node();

    printf("After deleting last node:\n");
    traverse();

    return 0;
}