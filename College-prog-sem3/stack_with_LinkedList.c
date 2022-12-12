#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}node;

void push();
void pop();
void peek();
void display();
void deallocate();

void main(){
    struct node *root = NULL; 

    push(&root,7);
    push(&root,10);
    push(&root,3);
    display(&root);
    push(&root,56);
    push(&root,89);
    peek(&root);
    display(&root);
    pop(&root);
    pop(&root);
    peek(&root);
    display(&root);

    deallocate(&root);

}

void push(node **root, int value){
    node *newNode;
    newNode = malloc(sizeof(node));
    newNode->data = value;
    if(newNode == NULL){
        exit(1);
    }
    if((*root)==NULL){
        *root = newNode;
        return ; 
    }
    newNode->next = *root;
    *root = newNode;
    return;
}

void pop(node **root){
    if((*root)==NULL){
        printf("Underflow Condition\n");
        return;
    }
    node *temp = *root;
    printf("poped data is %d \n", (*root)->data);
    *root = (*root)->next;
    free(temp);
}

void peek(node **root){
    if(*root == NULL){
        printf("no elements present in the stack \n");
        return;
    }
    node *curr = *root;
    printf("peek element is : %d \n",curr->data);
    return;
}

void display(node **root){
    if((*root)==NULL){
        printf("the stack is emepty\n");
        return;
    }
    node *curr = *root;
    while(curr!= NULL){
        printf("%d \n", curr->data);
        curr = curr->next;
    }
    return;
}

void deallocate(node **root){
    node *curr = *root;
    while(curr != NULL){
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *root = NULL;
}