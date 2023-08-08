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
AVLNode *insertAVLNode(AVLNode *root, AVLNode *newNode);
AVLNode *destroyAVL(AVLNode *root);
AVLNode *searchSmallerAVLNode(AVLNode *root);
AVLNode *searchBiggerAVLNode(AVLNode *root);
AVLNode *searchMediumAVLNode(AVLNode *root);