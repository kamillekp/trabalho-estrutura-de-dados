#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

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

DLLNode* destroyDLL(DLLNode *head){
    DLLNode *aux = head;

    while(aux != NULL){
        DLLNode *aux2 = aux->right;
        free(aux);
        aux = aux2;
    }

    return NULL;
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


