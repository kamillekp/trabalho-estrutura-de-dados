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

DLLNode* insertDLLNode(DLLNode* head, int key) {
    DLLNode* newNode = (DLLNode*) malloc(sizeof(DLLNode));
    newNode->key = key;

    DLLNode* currentNode = head;
    DLLNode* previousNode = NULL;

    while (currentNode != NULL && currentNode->key < key) {
        previousNode = currentNode;
        currentNode = currentNode->right;
    }

    if (currentNode == NULL) {
        previousNode->right = newNode;

        newNode->left = previousNode;
        newNode->right = NULL;
    } else {
        previousNode->right = newNode; 
        currentNode->left = newNode;

        newNode->left = previousNode;
        newNode->right = currentNode;
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

void printDLL(DLLNode *head){
    DLLNode *aux = head;

    while(aux != NULL){
        printf("%d  ", aux->key);
        aux = aux->right;
    }

    printf("\n");
}
