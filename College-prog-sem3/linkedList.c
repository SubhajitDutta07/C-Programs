# include<stdio.h>
# include<stdlib.h>



typedef struct node {
    int data;
    struct node *next;
}node;

void insert_end();
void deallocate();
void insert_at_beginning();
void insert_after();

void main(){
    // node *root = malloc(sizeof(node)); 
    // if(root == NULL){
    //     exit(2);
    // }

    node *root = NULL ;

    insert_end(&root, 13);
    insert_end(&root,87);
    insert_end(&root,56);
    insert_at_beginning(&root,10);
    insert_end(&root, 45);
    insert_at_beginning(&root, -2);
    insert_after(&root,6,3);
    insert_after(&root,15,5);

    node *curr = root;
    // while(curr != NULL){        // while loop for traversal 
    //     printf("%d \n", curr->data);
    //     curr = curr->next;
    // }

    for (curr = root;curr != NULL; curr = curr->next)  // for loop for traversal 
    {
        printf("%d \n", curr->data);
    }
      
    deallocate(&root);
    return;
}

void insert_end(node **root,int x){
    node *newNode = malloc(sizeof(node));
    if(newNode == NULL ){
        exit(1);
    }    
    newNode->next= NULL;
    newNode->data = x;

    if(*root == NULL){   //checking if the root is pointing towards null because if it is then we canot dereference it in the for loop below and the program will crash
        *root = newNode;
        return ;
    }

    node *curr = *root;
    while(curr->next != NULL){
        curr = curr->next ; 
    }
    curr->next = newNode;
}

void deallocate(node **root){  // freeing the linkesLIst as a whole
    node *curr = *root;
    while(curr != NULL){
        node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *root = NULL ;
}

void insert_at_beginning(node **root, int x){
    node *newNode = malloc(sizeof(node));
    newNode->data = x;
    newNode-> next = *root;
    if(newNode == NULL){
        return ; 
    }
    if(*root == NULL){
        *root = newNode; 
        return;
    }
    *root = newNode;

}

void insert_after(node **root,int x,int pos){
    node *newNode = malloc(sizeof(node));
    if(newNode == NULL){
        return ; 
    }
    newNode->data = x;
    if(*root == NULL){
        *root = newNode;
        return ; 
    }
    node *curr = *root;
    int c=0;
   while(c<(pos-2)){
    c++;
    curr = curr->next;
   }

   newNode->next = curr->next ;
   curr->next = newNode;

}