#include <stdio.h>
#include <stdlib.h>

typedef struct avlNode AVLNode;
struct avlNode {
    int key;
    int factor;
    AVLNode *leftKid;
    AVLNode *rightKid;
};

// PROTÓTIPOS PARA A ÁRVORE AVL
AVLNode *insertAVLNode(AVLNode* node, int key, int *ok);
AVLNode* rightRotation(AVLNode *pt);
AVLNode* leftRotation(AVLNode *pt);
AVLNode* doubleRightRotation (AVLNode* pt);
AVLNode* doubleLeftRotation (AVLNode* pt);
AVLNode* firstCase (AVLNode* node , int *ok);
AVLNode* secondCase (AVLNode *node , int *ok);
int height (AVLNode* node);
int is_avl(AVLNode *node);
void printAVL(AVLNode *root, int space);