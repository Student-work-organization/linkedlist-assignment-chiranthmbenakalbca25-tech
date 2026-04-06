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

void traverse() {
    struct Node* curr = head;
    printf("List: ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

void delete_node(int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    struct Node* curr = head;

    while (curr->next != NULL && curr->next->data != data) {
        curr = curr->next;
    }

    if (curr->next == NULL) {
        printf("Node with data %d not found.\n", data);
        return;
    }

    struct Node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
}

int main() {
    insert_at_beginning(3);
    insert_at_beginning(2);
    insert_at_beginning(7);
    insert_at_beginning(4);

    traverse();

    delete_node(2);

    printf("After deleting ");
    traverse();

    return 0;
}