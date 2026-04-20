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

// Delete last node
void delete_the_end_node() {
    struct DoublyNode *temp = head;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev == NULL) {
        head = NULL;
    } else {
        temp->prev->next = NULL;
    }

    free(temp);
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
    delete_the_end_node();
    display();
}