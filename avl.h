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
AVLNode* insertAVLNode(AVLNode* node, int key, int *ok,int *cont);
AVLNode* rightRotation(AVLNode *pt);
AVLNode* leftRotation(AVLNode *pt);
AVLNode* doubleRightRotation (AVLNode* pt,int *cont);
AVLNode* doubleLeftRotation (AVLNode* pt,int *cont);
AVLNode* firstCase (AVLNode* node , int *ok,int *cont);
AVLNode* secondCase (AVLNode *node , int *ok,int *cont);
int searchSmallerAVLNode(AVLNode *root, int *cont);
int searchBiggerAVLNode(AVLNode *root, int *cont);
int height (AVLNode* node);
int is_avl(AVLNode *node);
void printAVL(AVLNode *root, int space);
void searchMostRepeatedAVLNodes(AVLNode *root, int *mostRepeated, int *repetitions, int n, int *contC);
void findDuplicates(AVLNode* root, int *mostRepeated, int* repetitions, int n, int key, int *cont, int *contC);
void listAllTerms(AVLNode* root);
int searchMediumAVLNode(AVLNode* root, int *cont);
void testMediumNode(AVLNode* node, int key, int* bigger, int* smaller, int* equal, int *cont);