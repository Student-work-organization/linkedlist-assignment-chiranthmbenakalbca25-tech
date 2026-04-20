#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Head pointer
struct Node *head = NULL;

// Insert at beginning
void insert_at_beginning(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

// Delete from beginning
void delete_from_beginning() {
    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
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

    delete_from_beginning();

    printf("After deleting from beginning:\n");
    traverse();

    return 0;
}