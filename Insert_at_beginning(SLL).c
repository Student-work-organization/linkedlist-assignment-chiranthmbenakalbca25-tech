#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};


struct Node *head = NULL;


void insert_at_beginning(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->next = head;

    head = new_node;
}