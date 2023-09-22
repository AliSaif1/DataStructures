#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int data;
    struct completeTree *leftChild, *rightChild;
}completeTree;

void insertElement(completeTree **root, int data, int *level);
void display(completeTree *root);

int main(){
    completeTree *root = NULL;
    int level = 0;
    insertElement(&root, 12, &level);
    insertElement(&root, 10, &level);
    insertElement(&root, 34, &level);
    insertElement(&root, 15, &level);
    insertElement(&root, 23, &level);
    insertElement(&root, 89, &level);
    insertElement(&root, 67, &level);
    insertElement(&root, 44, &level);
    insertElement(&root, 8, &level);
    display(root);
}

void insertElement(completeTree **root, int data, int *level){
    if(*root == NULL){
        *root = (completeTree*)malloc(sizeof(completeTree));
        (*root)->data = data;
        (*root)->leftChild = NULL;
        (*root)->rightChild = NULL;
        *level++;
        return;
    }
    completeTree *temp = *root;
    if(temp->leftChild == NULL)
        insertElement(&temp->leftChild, data, level);
    else if(temp->rightChild == NULL)
        insertElement(&temp->rightChild, data, level);
}
void display(completeTree *root){
    if(root != NULL){
        display(root->leftChild);
        printf("%d\t", root->data);
        display(root->rightChild);
    }
}
