#include<stdio.h>
#include<stdlib.h>

#define l 6
int queue[l];
int front=-1,rear=-1;

void enqueue();
void dequeue();
void display();
void peek();

void main(){
    int ch,c;
    do{
        printf("1.Enqueue \n2.Dequeue \n3.Peek \n4.Display \n5.Exit \n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: enqueue();
            break;
        case 2: dequeue();
            break;
        case 3: peek();
            break;
        case 4: display();
            break;
        case 5: exit(1);
            break;
        default:
            printf("\n WRONG CHOICE !!!\n ");
            break;
        }
        printf("Enter 1 to continue and 0 to exit out of the loop\n");
        scanf("%d",&c);
    }while(c == 1);

}

void enqueue(){
    if(front == l){
        printf("Queue is full \n");
        return;
    }
    int x;
    printf("Enter the element to be inserted \n");
    scanf("%d",&x);
    if(front ==-1){
        front++;
        rear++;
        queue[front]= x;
        return;
    }
    rear++;
    queue[rear]=x;
    return;
}

void dequeue(){
    if(front==-1 || rear ==-1){
        printf("Queue is empty \n");
        return;
    }
    queue[front]=0;
    front++;
}

void peek(){
    if(front == -1 || rear == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("The peek element is: %d \n", queue[front]);
}

void display(){
    if (front == -1 || rear == -1)
    {
        printf("queue is empty \n");
        return;
    }
    for(int i = front;i<=rear;i++){
        printf("%d\n", queue[i]);
    }
    printf("\n");
}