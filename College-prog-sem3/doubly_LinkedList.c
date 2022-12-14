#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node ;

void deallocate();
void insert_at_beginning();
void init ();
void insert_at_end();
void insert_at_pos_from_start();
void remove_from_beginning();
void remove_from_end();


void main(){

    node *head = NULL;
    node *tail = NULL;
    // init(&head,&tail,7);
    insert_at_beginning(&head,&tail,5);
    insert_at_beginning(&head,&tail,3);
    insert_at_beginning(&head,&tail,1);
    insert_at_end(&head,&tail,9);
    insert_at_end(&head,&tail,11);
    insert_at_pos_from_start(&head,&tail,6,4);
    insert_at_pos_from_start(&head,&tail,7,5);
    remove_from_beginning(&head);
    remove_from_end(&head,&tail);

    

    if(head == NULL || tail == NULL){       //checking this because if not then head might contain some garbage value which will give an exception and thus while deallocating and printing it will give segmentation fault
        free(head);
        free(tail);
        return;
    }
    node *curr = head;   // *curr = tail to traverse in reverse
    while(curr !=  NULL){
        printf("%d\n", curr->data);
        curr = curr->next;       // curr = curr->prev if treversing in reverse
    }

    deallocate(&head,&tail);

    return;
}

void remove_from_end(node **head,node **tail){
    if((*tail) == NULL){
        printf("LinkedList is empty\n");
    }
    if((*tail)->prev == NULL){
        printf("LinkedList is empty now, it had one element that has been removed\n");
        *tail = NULL;
        return;
    }
    *tail = (*tail)->prev;
    free((*tail)->next);
    (*tail)->next = NULL;
}

void remove_from_beginning(node **head){
    if((*head) == NULL){
        printf("LinkedList is already empty\n");
        return;
    }
    if((*head)-> next == NULL){
        *head = NULL;           //doing this because if we free the head here it may be possible that it can contain garbage value therefore giving an exception
       printf("LinkedList is empty now, it had one element that has been removed\n");
        return;
    }
    node *curr = *head;
    (*head)= (*head)->next;
    (*head)->prev = NULL;
    free(curr);
}

void insert_at_pos_from_start(node **head, node **tail, int x, int pos){
    node *newNode = malloc(sizeof(node));
     node *temp= *head , *temp2 = *tail;
    if(newNode == NULL){
        exit(1);
    }
    if(*head == NULL && *tail == NULL){
        insert_at_beginning(&temp,&temp2,x);
        return;
    }
    newNode-> data = x;
    if(pos == 1){
        if(head != NULL){
        (*head)->prev = newNode;
        }
        newNode->prev = NULL;
        newNode->next = *head ; 
        *head = newNode;
        return;
    }

    int c=0;
    node *curr = *head;
    while(c<(pos-2)){
        c++;
        curr= curr->next;
        if(curr == *tail){
            insert_at_end(&temp,&temp2,x);
            return;
        }
    }
    newNode->next = curr->next;
    newNode->prev = curr;
    curr->next->prev = newNode;
    curr->next = newNode;
    return;

}

void insert_at_end(node **head,node **tail, int x){
    node *newNode = malloc(sizeof(node));
    if(newNode == NULL){
        exit(1);
    }
    newNode->data = x;
    if(*tail == NULL && *head == NULL){
        *head = newNode;
        *tail = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        return;
    }
    (*tail)->next = newNode;
    newNode->next = NULL;
    newNode->prev = *tail;
    *tail = newNode;
    return;

}

void insert_at_beginning(node **head,node **tail, int x){
    node *newNode = malloc(sizeof(node));
    if(newNode == NULL){
        exit(1);
    }
    newNode->data = x;
    if(*head == NULL && *tail == NULL){
        newNode->next = NULL;
        newNode->prev = NULL;
        *head = newNode;
        *tail = newNode;
        return;
    }
    newNode->prev = NULL;
    newNode->next = *head;
    if(*head != NULL){
        (*head)->prev = newNode;
    }
    *head = newNode;
    return;
}

void deallocate(node **head, node **tail){
    if((*head) == NULL){
        return;
    }
    node *curr = *head;
    while(curr->next != NULL){
        curr = curr->next;
        free(curr->prev);
    }
    free(curr);
    *head = NULL;
    *tail = NULL;
}

// this furnction is very inportant beccause in the function of insering in the beginning
// we are not updating the tail therefore if we traverse from the tail,then it won't show anything
// therefore updating the tail when the LinkedList is empty is important but i have added this 
// directly to my function of inserting at the beginning.
// void init (node **head, node **tail, int x){   
//     node *newNode = malloc(sizeof(node));
//     if(newNode == NULL){
//         exit(1);
//     }
//     newNode->data = x;
//     newNode->next = NULL;
//     newNode->prev = NULL;

//     *head = newNode; 
//     *tail = newNode ;
// }