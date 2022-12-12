#include<stdio.h>
#include<stdlib.h>

#define l 5
int stack[l];
int top = -1;

void push();
void pop();
void peek();
void display();


void main(){
    int ch,c;
    do{
        printf("enter your choice \n");
        printf("1. Push \n 2. Pop \n 3. Peek \n 4. Display \n 5. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:push();     
            break;
        case 2:pop();
            break;
        case 3: peek();
            break;
        case 4 : display();
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

}

void push(){
    int x;
    printf("enter the element to be inserted \n");
    scanf("%d", &x);
    if(top == (l-1)){
        printf("overflow condition \n");
        return;
    }
    top++;
    stack[top]= x;
    return ;
}

void pop(){
    if(top == -1){
        printf("underflow condition \n");
        return;
    }
    printf("Popped element is : %d \n", stack[top]);
    stack[top]= 0;
    top --;
    return;
}

void peek(){
    if(top == -1){
        printf("stack is emepty \n");
        return;
    }
    printf("peek element is : %d \n", stack[top]);
}

void display(){
    if(top == -1){
        printf("stack is emepty \n");
        return;
    }
    printf("\n \n");
    for(int i = top; i>=0;i--){
        printf("%d  \n", stack[i]);
    }

}
