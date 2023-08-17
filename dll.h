#include <stdio.h>
#include <stdlib.h>

typedef struct dllNode DLLNode;
struct dllNode {
    int key;
    DLLNode *left;
    DLLNode *right;
};

// PROTÓTIPOS PARA A LISTA DUPLAMENTE ENCADEADA
DLLNode *createDLLNode(int key);
DLLNode *insertDLLNode(DLLNode *head, int key);
DLLNode *destroyDLL(DLLNode *head);
int searchSmallerDLLNode(DLLNode *head);
int searchBiggerDLLNode(DLLNode *head);
int mediaDLLNode(DLLNode *head, int tam);
int searchMediumDLLNode(DLLNode *head, int tam);
void searchMostRepeatedDLLNodes(DLLNode *head, int *mostRepeated, int *repetitions, int n);
void printDLL(DLLNode *head);



