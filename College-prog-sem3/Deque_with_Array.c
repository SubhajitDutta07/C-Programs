#include<stdio.h>
#include<stdlib.h>

#define l 5
int dequeue[l];
int front =-1;
int rear = -1;

void insertBeginning();
void insertEnd();
void delBeginning();
void delEnd();
void peekFront();
void peekEnd();
void displayFromBeginning();
void displayFromEnd();

void main(){

    while(1){
        printf("1.Insert at the beginnig\n2.Insert at the end\n3.Delete from the beginning\n4.Delete from the end\n5.Peek element from the beginning\n6.Peek element from the end\n7.Display from the beginning\n8.Display from the end\n");
        int ch;
        printf("Enter your choice \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: insertBeginning();
            break;
        case 2: insertEnd();
            break;
        case 3: delBeginning();
            break;
        case 4: delEnd();
            break;
        case 5: peekFront();
            break;
        case 6: peekEnd();
            break;
        case 7: displayFromBeginning();
            break;
        case 8: displayFromEnd();
            break;
        default: printf("WRONG CHOICE !! \n");
        }
    }
}

void insertEnd(){
    int x;
    printf("Enter the element to be inserted \n");
    scanf("%d",&x);
    if(( front == 0 && rear == l-1) || front == rear+1){
        printf("Queue is full \n");
        return;
    }
    if(front == -1 && rear ==-1){
        front++;
        rear++;
        dequeue[front]= x;
        return;
    }
    if(rear == l-1){
        rear = 0;
        dequeue[rear]= x;
        return;
    }
    rear ++;
    dequeue[rear] = x;
    return;
}


void insertBeginning(){
    int x;
    printf("Enter the element to be inserted \n");
    scanf("%d",&x);
    if(( front == 0 && rear == l-1) || front == rear+1){
        printf("Queue is full \n");
        return;
    }
    if(front == -1 && rear == -1){
        front++;
        rear++;
        dequeue[front]= x;
        return;
    }
    if(front == 0){
        front = l-1;
        dequeue[front]=x;
        return;
    }
    front -- ;
    dequeue[front]= x;
    return;
}

void delBeginning(){
    if(front == -1 && rear == -1){
        printf("Queue is empty \n");
        return; 
    }
    if(front == rear){
        printf("Deleted element is %d \n", dequeue[front]);
        front =-1;
        rear =-1;
        return ;
    }
    if(front == l-1){
        printf("Deleted Element is %d \n", dequeue[front]);
        front = 0;
        return;
    }
    printf("Deleted Element is %d \n", dequeue[front]);
    front++;
    return;
}

void delEnd(){
    if(front == -1 && rear == -1){
        printf("Queue is empty \n");
        return; 
    }
    if(front == rear){
        printf("Deleted Element is %d \n", dequeue[rear]);
        front = -1;
        rear = -1;
        return;
    }
    if(rear == 0){
        printf("Deleted Element is %d \n", dequeue[rear]);
        rear = l-1;
        return;
    }
    printf("Deleted Element is %d\n", dequeue[rear]);
    rear --;
    return;
}

void peekEnd(){
    if(front == -1 && rear == -1){
        printf("Queue is empty \n");
        return; 
    }
    printf("%d \n",dequeue[rear]);
}


void peekFront(){
    if(front == -1 && rear == -1){
        printf("Queue is empty \n");
        return; 
    }
    printf("%d \n",dequeue[front]);
}

void displayFromEnd(){
    int i=rear;
    if(front == -1 && rear == -1){
        printf("Queue is empty \n");
        return; 
    }
    while(i!= front){
        if(i < 0){
            i = l-1;
        }
        printf("%d ", dequeue[i]);
        i= (i-1)%l;
    }
    printf("%d  \n", dequeue[i]);
    return;
}

void displayFromBeginning(){
    int i;
    if(front == -1 && rear == -1){
        printf("Queue is empty \n");
        return; 
    }
    for(i=front;i!= rear;i=(i+1)%l){
        printf("%d  ", dequeue[i]);
    }
    printf("%d  ", dequeue[i]);
    printf("\n");
    return;
}