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
DLLNode *insertDLLNode(DLLNode *head, DLLNode *newNode);
DLLNode *destroyDLL(DLLNode *head);
DLLNode *searchSmallerDLLNode(DLLNode *head);
DLLNode *searchBiggerDLLNode(DLLNode *head);
DLLNode *searchMediumDLLNode(DLLNode *head);




