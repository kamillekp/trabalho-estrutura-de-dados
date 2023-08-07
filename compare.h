#include <stdio.h>
#include <stdlib.h>

// CRIANDO STRUCTS
typedef struct avlNode AVLNode;
struct avlNode {
    int key;
    int height;
    AVLNode *leftKid;
    AVLNode *rightKid;
};

typedef struct dllNode DLLNode;
struct SLLNode {
    int key;
    DLLNode *left;
    DLLNode *right;
};

// PROTÓTIPOS PARA A ÁRVORE AVL

// PROTÓTIPOS PARA A LISTA DUPLAMENTE ENCADEADA
void insertDLL(struct DLinkedList **head, int value);



