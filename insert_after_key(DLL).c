#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Head pointer
struct Node *head = NULL;

// Insert at beginning (helper)
void insert_at_beginning(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL)
        head->prev = new_node;

    head = new_node;
}

// Insert after given key
void insert_after_key(int key, int data) {
    struct Node *curr = head;

    // Traverse to find key
    while (curr != NULL && curr->data != key) {
        curr = curr->next;
    }

    // Key not found
    if (curr == NULL) {
        printf("Key not found\n");
        return;
    }

    // Create new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;

    // Insert after key
    new_node->next = curr->next;
    new_node->prev = curr;

    if (curr->next != NULL) {
        curr->next->prev = new_node;
    }

    curr->next = new_node;
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

    printf("Original List:\n");
    traverse();

    insert_after_key(20, 25);

    printf("After inserting 25 after 20:\n");
    traverse();

    return 0;
}