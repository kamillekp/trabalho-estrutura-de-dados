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

DLLNode* insertDLLNode(DLLNode *head, DLLNode *newNode){
    if(head == NULL){
        head = newNode;
    } 
    else {
        DLLNode *aux = head;

        while(aux->right != NULL){
            aux = aux->right;
        }

        aux->right = newNode;
        newNode->left = aux;
    }

    return head;
}

DLLNode* searchSmallerDLLNode(DLLNode *head){
    DLLNode *aux = head;
    DLLNode *smaller = head;

    while(aux != NULL){
        if(aux->key < smaller->key){
            smaller = aux;
        }

        aux = aux->right;
    }

    return smaller;
}

DLLNode* searchBiggerDLLNode(DLLNode *head){
    DLLNode *aux = head;
    DLLNode *bigger = head;

    while(aux != NULL){
        if(aux->key > bigger->key){
            bigger = aux;
        }

        aux = aux->right;
    }

    return bigger;
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

