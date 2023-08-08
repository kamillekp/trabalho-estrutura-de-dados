#include <stdio.h>
#include <stdlib.h>
#include "compare.h"


// FUNÇÕES PARA DLL
DLLNode* createDLLNode(int key){
    DLLNode *newNode = (DLLNode *) malloc(sizeof(DLLNode));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


// FUNÇÕES PARA AVL
AVLNode* createAVLNode(int key){
    AVLNode *newNode = (AVLNode *) malloc(sizeof(AVLNode));

    newNode->key = key;
    newNode->leftKid = NULL;
    newNode->rightKid = NULL;
    newNode->height = 1;

    return newNode;
}