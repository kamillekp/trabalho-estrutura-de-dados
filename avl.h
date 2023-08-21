#include <stdio.h>
#include <stdlib.h>

typedef struct avlNode AVLNode;
struct avlNode {
    int key;
    int factor;
    AVLNode *leftKid;
    AVLNode *rightKid;
};

struct FrequencyData {
    int value;
    int frequency;
};

// PROTÓTIPOS PARA A ÁRVORE AVL
AVLNode *insertAVLNode(AVLNode* node, int key, int *ok);
AVLNode* rightRotation(AVLNode *pt);
AVLNode* leftRotation(AVLNode *pt);
AVLNode* doubleRightRotation (AVLNode* pt);
AVLNode* doubleLeftRotation (AVLNode* pt);
AVLNode* firstCase (AVLNode* node , int *ok);
AVLNode* secondCase (AVLNode *node , int *ok);
int searchSmallerAVLNode(AVLNode *root);
int searchBiggerAVLNode(AVLNode *root);
int height (AVLNode* node);
int is_avl(AVLNode *node);
void printAVL(AVLNode *root, int space);
//int compareFrequencyData(const void* a, const void* b);
void searchMostRepeatedAVLNodes(AVLNode *root, int *mostRepeated, int *repetitions, int n);
//void traverseAndCollect(AVLNode *root, struct FrequencyData *data, int *index);
void findDuplicates(AVLNode* root, int *mostRepeated, int* repetitions, int n, int key, int *cont);
void listAllTerms(AVLNode* root);