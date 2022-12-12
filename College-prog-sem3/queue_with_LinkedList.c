#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node *next;
}node; 

void enqueue();
void dequeue();
void peek();
void deallocate();
void display();

void main(){
    struct node *root = NULL; 
    int ch,c;

   do{
        printf("enter your choice \n");
        printf("1. Enqueue \n2. Dequeue \n3.Peek \n4. Display \n5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:enqueue(&root);     
            break;
        case 2:dequeue(&root);
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

void enqueue(node **root){
    node *newNode = malloc(sizeof(node));
    if(newNode == NULL){
        exit(1);
    }
    int x;
    printf("Enter the data to be inserted: \n");
    scanf("%d", &x);
    newNode->next = NULL;
    newNode->data = x;
    if((*root)==NULL){
        *root=newNode;
        return;
    }
    node *curr= *root;
    while(curr->next != NULL){
        curr=curr->next;
    }
    curr->next = newNode;
}

void dequeue(node **root){
    if((*root)==NULL){
        printf("Queue is empty \n");
        return;
    }
    if(((*root)->next)==NULL){
        free(*root);
        return;
    }
    node *temp= *root;
    printf("The deleted element is %d \n", (*root)->data);
    *root = (*root)->next;
    free(temp);
}

void peek(node **root){
    if((*root)==NULL){
        printf("Queue is empty \n");
        return;
    }
    printf("Peek value is : %d\n", (*root)->data);
}

void display(node **root){
    if((*root)== NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("\n");
    for(node *curr = *root; curr!= NULL;curr = curr->next){
        printf("%d\n", curr->data);
    }
}

void deallocate(node **root){
    if((*root)==NULL){
        return;
    }
    node *curr = *root;
    while(curr!=NULL){
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *root = NULL;
}