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
DLLNode *insertDLLNode(DLLNode *head, int key, int *cont);
DLLNode *destroyDLL(DLLNode *head);
int searchSmallerDLLNode(DLLNode *head, int *cont);
int searchBiggerDLLNode(DLLNode *head, int *cont);
int searchMediumDLLNode(DLLNode *head, int tam, int *cont);
void searchMostRepeatedDLLNodes(DLLNode *head, int *mostRepeated, int *repetitions, int n, int *contC);
void printDLL(DLLNode *head);



