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


  