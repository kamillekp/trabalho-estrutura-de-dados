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


// PROTÓTIPOS PARA A LISTA DUPLAMENTE ENCADEADA
DLLNode *createDLLNode(int key);
DLLNode *insertDLLNode(DLLNode *head, DLLNode *newNode);
DLLNode *searchSmallerDLLNode(DLLNode *head);
DLLNode *searchBiggerDLLNode(DLLNode *head);
DLLNode *searchMediumDLLNode(DLLNode *head);


// PROTÓTIPOS PARA A ÁRVORE AVL
AVLNode *createAVLNode(int key);
AVLNode *insertAVLNode(AVLNode *root, AVLNode *newNode);
AVLNode *searchSmallerAVLNode(AVLNode *root);
AVLNode *searchBiggerAVLNode(AVLNode *root);
AVLNode *searchMediumAVLNode(AVLNode *root);




