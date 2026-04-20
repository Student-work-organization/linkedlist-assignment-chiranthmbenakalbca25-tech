#include <stdio.h>
#include <stdlib.h>

struct DoublyNode {
    int data;
    struct DoublyNode *prev, *next;
};

struct DoublyNode *head = NULL;

// Insert at beginning (helper)
void insert(int data) {
    struct DoublyNode *new_node = malloc(sizeof(struct DoublyNode));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL)
        head->prev = new_node;

    head = new_node;
}

// Delete first occurrence of data
void delete_node(int data) {
    struct DoublyNode *curr = head;

    while (curr != NULL && curr->data != data)
        curr = curr->next;

    if (curr == NULL) {
        printf("Data not found\n");
        return;
    }

    if (curr == head) {
        head = curr->next;
        if (head != NULL)
            head->prev = NULL;
    } else {
        curr->prev->next = curr->next;
        if (curr->next != NULL)
            curr->next->prev = curr->prev;
    }

    free(curr);
}

// Display
void display() {
    struct DoublyNode *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(3); insert(2); insert(1);

    display();
    delete_node(2);
    display();
}