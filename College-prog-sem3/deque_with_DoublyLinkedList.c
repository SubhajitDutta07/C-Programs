#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;

void insertBeginning();
void insertEnd();
void delBeginning();
void delEnd();
void peekFront();
void peekEnd();
void displayFromBeginning();
void displayFromEnd();
void deallocate();

void main(){

    node  *head = NULL;
    node *tail = NULL;
    while(1){
        printf("1.Insert at the beginnig\n2.Insert at the end\n3.Delete from the beginning\n4.Delete from the end\n5.Peek element from the beginning\n6.Peek element from the end\n7.Display from the beginning\n8.Display from the end\n");
        int ch;
        printf("Enter your choice \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1: insertBeginning(&head,&tail);
            break;
        case 2: insertEnd(&head,&tail);
            break;
        case 3: delBeginning(&head,&tail);
            break;
        case 4: delEnd(&head,&tail);
            break;
        case 5: peekFront(&head);
            break;
        case 6: peekEnd(&head,&tail);
            break;
        case 7: displayFromBeginning(&head,&tail);
            break;
        case 8: displayFromEnd(&head,&tail);
            break;
        default: printf("WRONG CHOICE !! \n");
        }

    }
    deallocate(&head,&tail);

}

void deallocate(node **head, node **tail){
    if((*head)==NULL){
        return;
    }
    while(*head != *tail){
        *head = (*head)->next;
        free((*head)->prev);
    }
    *head = NULL;
    *tail = NULL;
    return;
}

void displayFromEnd(node **head, node **tail){
    if((*head)==NULL){
        printf("Deque is empty \n");
        return;
    }
    node *curr = *tail ;
    while(curr != *head){
        printf("%d  ", curr->data);
        curr = curr->prev;
    }
    printf("%d \n",curr->data);
    return;
}

void displayFromBeginning(node **head, node **tail){
    if((*head)==NULL){
        printf("Deque is empty \n");
        return;
    }
    node *curr = *head ;
    while(curr != *tail){
        printf("%d  ", curr->data);
        curr = curr->next;
    }
    printf("%d \n",curr->data);
    printf("\n");
    return;
}

void peekEnd(node **head, node **tail){
    if((*head)==NULL){
        printf("Deque is empty \n");
        return;
    }
    printf("End element is %d \n", (*tail)->data);
    return;
}

void peekFront(node **head){
    if((*head)==NULL){
        printf("Deque is empty \n");
        return;
    }
    printf("Front element is %d \n", (*head)->data);
    return;
}

void delEnd(node **head, node **tail){
     if((*head)==(*tail)){
        printf("Deleted element is : %d \n", (*tail)->data);
        printf("Deque is empty now\n");
        return;
    }
    if((*head)->next == NULL){
        printf("Deleted element is : %d \n", (*tail)->data);
        printf("Now the Deque is empty \n");
        free(*head);
        return;
    }
    printf("Deleted element is : %d \n", (*tail)->data);
    *tail = (*tail)->prev;
    free((*tail)->next);
    (*tail)->next = NULL;
}

void delBeginning(node **head,node **tail){
    if((*head) == (*tail)){
        printf("Deleted element is : %d \n", (*head)->data);
        printf("Deque is empty now\n");
        return;
    }
    if((*head)->next == NULL){
        printf("Deleted element is : %d \n", (*head)->data);
        printf("Now the Deque is empty \n");
        free(*head);
        return;
    }
    printf("Deleted element is : %d \n", (*head)->data);
    (*head) = (*head)->next;
    free((*head)->prev);
    (*head)->prev = NULL;
    return;
}

void insertEnd(node **head,node **tail){
    node *newNode = malloc(sizeof(node));
    if(newNode == NULL){
        exit(1);
    }
    int x;
    printf("Enter the data to be inserted : \n");
    scanf("%d", &x);
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    if((*head) == NULL){
        *head = newNode;
        *tail = newNode;
        return;
    }
    (*tail)->next = newNode;
    newNode->prev = *tail;
    (*tail) = newNode;
    return;
}

void insertBeginning(node **head,node **tail){
    node *newNode = malloc(sizeof(node));
    if(newNode == NULL){
        exit(1);
    }
    int x;
    printf("Enter the data to be inserted : \n");
    scanf("%d", &x);
    newNode->data = x;
    if((*head) == NULL){
        *head = newNode;
        *tail = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
        return;
    }
    newNode->next= (*head);
    newNode->prev = NULL;
    (*head)->prev = newNode;
    *head = newNode;
    return;
}    