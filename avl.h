#include <stdio.h>
#include <stdlib.h>

typedef struct avlNode AVLNode;
struct avlNode {
    int key;
    int height;
    AVLNode *leftKid;
    AVLNode *rightKid;
};

// PROTÓTIPOS PARA A ÁRVORE AVL
AVLNode *createAVLNode(int key);
void printAVL(AVLNode *root, int space);