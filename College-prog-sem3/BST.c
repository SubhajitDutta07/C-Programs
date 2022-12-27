#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}node ; 

node* create();
node* insert();
void inorder();
node* deleteNode();
node* inorderSuccessor();
node* search();


void main(){
    node *root = NULL ; 
    root = insert(root , 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 10);

    inorder(root);
    printf("\n");

    deleteNode(root, 40);
    inorder(root);
    printf("\n");

    return ; 
}

node* create(int x)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = x;
    newNode->right = newNode->left = NULL;
    return newNode;
}

void inorder(node *root){
    if((root)!= NULL){
        inorder((root)->left);
        printf("%d ", (root)->data);
        inorder((root)->right);
    }
}

node* insert(node *root, int x){
    if((root)== NULL)
        return create(x);
    if(x < (root)->data)
        (root)->left = insert((root)->left , x);
    if(x > (root)->data)
        (root)->right = insert((root)->right, x);
    return root ; 
}

node* deleteNode(node *root, int x){
    if(root == NULL){
        return root;
    }
    else if(x > root->data){
        root->right = deleteNode(root->right, x);
    }
    else if( x < root->data){
        root->left = deleteNode(root->left , x);
    }
    else {
        if(root->left == NULL){
            node *temp = root->right ; 
            free(root);
            return temp;
        }
        if(root->right == NULL){
            node *temp = root->left;
            free(root);
            return temp ; 
        }
        node *temp = inorderSuccessor(root->right);
        root->data = temp->data ;
        root->right = deleteNode(root->right , temp->data);
    }
    return root;
}


node* inorderSuccessor(node *root){
    node *curr = root ; 
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

node* search(node *root, int x){
    if(root == NULL || root->data == x){
        return root ;
    }
    if(x > root->data){
        return search(root->right , x);
    }
    if(x < root->data){
        return search(root->left, x);
    }
}