#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

DLLNode* createDLLNode(int k){
    DLLNode *newNode = (DLLNode *) malloc(sizeof(DLLNode));

    newNode->key = k;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

DLLNode* insertDLLNode(DLLNode* head, int k) {
    DLLNode *newNode = createDLLNode(k);

    DLLNode *aux = head;

    while(aux->right != NULL){
        aux = aux->right;
    }

    aux->right = newNode;
    newNode->left = aux;

    return head;
}

int searchSmallerDLLNode(DLLNode *head){
    DLLNode *aux = head;
    DLLNode *smaller = head;

    while(aux != NULL){
        if(aux->key < smaller->key){
            smaller = aux;
        }

        aux = aux->right;
    }

    return smaller->key;
}

int searchBiggerDLLNode(DLLNode *head){
    DLLNode *aux = head;
    DLLNode *bigger = head;

    while(aux != NULL){
        if(aux->key > bigger->key){
            bigger = aux;
        }

        aux = aux->right;
    }

    return bigger->key;
}

int mediaDLLNode(DLLNode *head, int tam){
    DLLNode *aux = head;
    int soma = 0;

    while(aux != NULL){
        soma += aux->key;
        aux = aux->right;
    }

    return soma/tam;
}

int searchMediumDLLNode(DLLNode *head, int tam){
    DLLNode *aux = head->right;
    int mediumValue = mediaDLLNode(head, tam);
    int diff2, diff1 = abs(head->key - mediumValue);
    int medium = head->key;

    while(aux != NULL){
        diff2 = abs(aux->key - mediumValue);
    
        if(diff2 < diff1){
            medium = aux->key;

            diff1 = diff2;
        }

        aux = aux->right;
    }

    return medium;
}

void printDLL(DLLNode *head){
    DLLNode *aux = head;

    while(aux != NULL){
        printf("%d  ", aux->key);
        aux = aux->right;
    }

    printf("\n");
}
