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

// Traverse backward
void traverse_backward() {
    struct DoublyNode *temp = head;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    // Go to last node
    while (temp->next != NULL)
        temp = temp->next;

    // Traverse backward
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

int main() {
    insert(3); insert(2); insert(1);

    traverse_backward();
}