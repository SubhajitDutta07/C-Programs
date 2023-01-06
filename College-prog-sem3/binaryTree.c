#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *create();
void inorderTraversal();
void postorderTraversal();
void preorderTraversal();

void main(){
    node *root = create();
    printf("InOrder traversal is \n");
    inorderTraversal(root);
    printf("\n");
    printf("Post-order traversal is : \n");
    postorderTraversal(root);
    printf("\n");
    printf("pre-order traversal is : \n");
    preorderTraversal(root);
    printf("\n");
}

node *create(){
    node *newNode = malloc(sizeof(node));
    if(newNode == NULL){
        exit(1);
    }
    int x;
    printf("Enter the data to be inserted  or enter -1 to no new node \n");
    scanf("%d", &x);
    if(x == -1){
        return NULL;
    }
    newNode->data = x;
    printf("\nEnter the left child of %d: \n", x);
    newNode->left = create();
    printf("\n Enter the right child of %d: \n", x);
    newNode->right = create();
    return newNode;
}

void inorderTraversal(node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

void postorderTraversal(node *root){
    if(root == NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

void preorderTraversal(node *root){
    if(root == NULL){
        return;
    }
    preorderTraversal(root->left);
    printf("%d ", root->data);
    preorderTraversal(root->right);
}