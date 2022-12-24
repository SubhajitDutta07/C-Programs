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
    int ch,c;

   do{
        printf("enter your choice \n");
        printf("1. Push \n 2. Pop \n 3. Peek \n 4. Display \n 5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:push(&root);     
            break;
        case 2:pop(&root);
            break;
        case 3: peek(&root);
            break;
        case 4 : display(&root);
            break;
        case 5: exit(1);
            break;
        default: printf("WRONG CHOICE !!");
            break;
        }
        printf("Do you want to continue if yes then press 1 \n");
        printf("Do you want to continue if no then press 0 \n");
        scanf("%d", &c);
    }while(c==1);

    deallocate(&root);

}

void push(node **root){
    int value = 0;
    printf("Enter an element to be inserted \n");
    scanf("%d", &value);
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
    if((*root)->next == NULL){
        printf("poped data is %d \n", (*root)->data);
        *root = NULL;
        printf("Stack is empty now \n");
        return ;
    }
    node *temp = *root;
    printf("poped data is %d \n", (*root)->data);
    *root = (*root)->next;
    free(temp);
    return ; 
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
    printf("\n \n");
    node *curr = *root;
    while(curr!= NULL){
        printf("%d \n", curr->data);
        curr = curr->next;
    }
    return;
}

void deallocate(node **root){
    if((*root)== NULL){
        return;
    }
    node *curr = *root;
    while(curr != NULL){
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *root = NULL;
}