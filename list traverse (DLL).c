#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node*next;
    struct Node*prev;
    
};
  struct Node *head = NULL;

void insert_at_beginning(int data){
    struct Node*new_node;
    new_node = (struct Node*)malloc(sizeof (struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = head;
    
    if(head != NULL){
        head->prev = new_node;
    }
    head = new_node;
}
void traverse1(){
    struct Node*curr;
    curr = head;
    
    while (curr != NULL){
        printf("%d",curr->data);
        curr = curr->next;
        
    }
  
}    
void traverse2(){
    struct Node*curr;
    curr = head;
    
    while (curr->next != NULL){
       printf("%d",curr->data);
        curr = curr->next;
        
    }
}
int main (){
    insert_at_beginning(3);
    insert_at_beginning(2);
    insert_at_beginning(4);
    insert_at_beginning(7);
    
    traverse1();
    traverse2();
    
    return 0;
}
