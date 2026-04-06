#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void insert_at_end(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct Node* curr = head;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
    new_node->prev = curr ;
}

void display() {
    struct Node* temp = head;

    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert_at_end(10);
    insert_at_end(20);
    insert_at_end(30);
    insert_at_end(40);

    display();

    return 0;
}