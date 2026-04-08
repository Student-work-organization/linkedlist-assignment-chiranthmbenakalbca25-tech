#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node *next;
};

// Head pointer
struct Node *head = NULL;

// Function to insert after a given key
void insert_after_key(int key, int data) {
    struct Node *curr = head;

    // Traverse to find the key
    while (curr != NULL && curr->data != key) {
        curr = curr->next;
    }

    // If key not found
    if (curr == NULL) {
        printf("Key not found\n");
        return;
    }

    // Create new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = data;

    // Insert after key
    new_node->next = curr->next;
    curr->next = new_node;
}

// Function to insert at beginning (for testing)
void insert_begin(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// Function to display list
void display() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    insert_begin(30);
    insert_begin(20);
    insert_begin(10);

    printf("Original list:\n");
    display();

    insert_after_key(20, 25);

    printf("After inserting 25 after 20:\n");
    display();

    return 0;
}