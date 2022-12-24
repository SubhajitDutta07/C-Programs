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
    struct node *front = NULL; 
    struct node *rear = NULL;
    int ch,c;

   while(1){
        printf("enter your choice \n");
        printf("1. Enqueue \n2. Dequeue \n3.Peek \n4. Display \n5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:enqueue(&front,&rear);     
            break;
        case 2:dequeue(&front);
            break;
        case 3: peek(&front);
            break;
        case 4 : display(&front);
            break;
        case 5: exit(1);
            break;
        default: printf("WRONG CHOICE !!");
            break;
        }
    }

    deallocate(&front, &rear);

}

void enqueue(node **front, node **rear){
    node *newNode = malloc(sizeof(node));
    if(newNode == NULL){
        exit(1);
    }
    int x;
    printf("Enter the data to be inserted: \n");
    scanf("%d", &x);
    newNode->next = NULL;
    newNode->data = x;
    if((*front)==NULL){
        *front = newNode;
        *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
}

void dequeue(node **front){
    if((*front)==NULL){
        printf("Queue is empty \n");
        return;
    }
    printf("The deleted element is %d \n", (*front)->data);
    if((*front)->next==NULL){
        free(*front);
        *front = NULL;
        return;
    }
    node *temp= *front;
    *front = (*front)->next;
    free(temp);
}

void peek(node **front){
    if((*front)==NULL){
        printf("Queue is empty \n");
        return;
    }
    printf("Peek value is : %d\n", (*front)->data);
}

void display(node **front){
    if((*front)== NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("\n");
    for(node *curr = *front; curr!= NULL;curr = curr->next){
        printf("%d\n", curr->data);
    }
}

void deallocate(node **front, node **rear){
    if((*front)==NULL){
        return;
    }
    node *curr = *front;
    while(curr!=NULL){
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *front = NULL;
    *rear = NULL;
}