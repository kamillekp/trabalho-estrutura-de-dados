#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

AVLNode* createAVLNode(int key){
    AVLNode *newNode = (AVLNode *) malloc(sizeof(AVLNode));

    newNode->key = key;
    newNode->leftKid = NULL;
    newNode->rightKid = NULL;
    newNode->height = 1;

    return newNode;
}

void printAVL(AVLNode *root, int space) 
{
    if(root == NULL) 
        return;
    
    space += 10; 

    printAVL(root->rightKid, space); 

    printf("\n");
    for(int i = 10; i < space; i++) 
        printf(" ");
    printf("%d\n", root->key); 

    printAVL(root->leftKid, space); 
}
  
