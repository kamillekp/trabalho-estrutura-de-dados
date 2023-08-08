#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

// FUNÇÃO PARA CRIAR UM NÓ DA ÁRVORE AVL

AVLNode* createAVLNode(int key){
    AVLNode *newNode = (AVLNode *) malloc(sizeof(AVLNode));

    newNode->key = key;
    newNode->leftKid = NULL;
    newNode->rightKid = NULL;
    newNode->height = 1;

    return newNode;
}

/*AVLNode* rotateRight(AVLNode *root){ // FUNÇÃO PARA ROTACIONAR A ÁRVORE PARA A DIREITA
    AVLNode *aux = root->leftKid; // AUX RECEBE O FILHO ESQUERDO DO NÓ RAIZ
    root->leftKid = aux->rightKid; // O FILHO DIREITO DO NÓ RAIZ RECEBE O FILHO ESQUERDO DO NÓ AUX
    aux->rightKid = root; // O FILHO DIREITO DO NÓ AUX RECEBE O NÓ RAIZ

    root->height = max(height(root->leftKid), height(root->rightKid)) + 1;
    aux->height = max(height(aux->leftKid), height(aux->rightKid)) + 1;

    return aux;
}*/

/*AVLNode* rotateLeft(AVLNode *root){ // FUNÇÃO PARA ROTACIONAR A ÁRVORE PARA A ESQUERDA
    AVLNode *aux = root->rightKid; // AUX RECEBE O FILHO DIREITO DO NÓ RAIZ
    root->rightKid = aux->leftKid; // O FILHO ESQUERDO DO NÓ RAIZ RECEBE O FILHO DIREITO DO NÓ AUX
    aux->leftKid = root; // O FILHO ESQUERDO DO NÓ AUX RECEBE O NÓ RAIZ

    root->height = max(height(root->leftKid), height(root->rightKid)) + 1;
    aux->height = max(height(aux->leftKid), height(aux->rightKid)) + 1;

    return aux;
}*/

/*AVLNode* insertAVLNode(AVLNode* root, AVLNode* newNode)
{
     if(!root) //SE A RAIZ FOR NULA RETORNA O NOVO NÓ
        return newNode;
    else if(newNode->key < root->key) //SE A CHAVE DO NOVO NÓ FOR MENOR QUE A CHAVE DA RAIZ DEVO INSERIR NA SUBÁRVORE ESQUERDA
        root->leftKid = insertAVLNode(root->leftKid, newNode);
    else if(newNode->key >= root->key) //SE A CHAVE DO NOVO NÓ FOR MAIOR QUE A CHAVE DA RAIZ DEVO INSERIR NA SUBÁRVORE DIREITA
        root->rightKid = insertAVLNode(root->rightKid, newNode);
    
    //BALANCEAMENTO DA ARVORE

    root->height = max(height(root->leftKid), height(root->rightKid)) + 1; //ATUALIZA A ALTURA DA RAIZ
    int balance = height(root->leftKid) - height(root->rightKid); //CALCULA O BALANCEAMENTO DA RAIZ

    if(balance >1){
        if(height(root->leftKid->leftKid) >= height(root->leftKid->rightKid)) //SE A ALTURA DA SUBÁRVORE ESQUERDA DA SUBÁRVORE ESQUERDA FOR MAIOR OU IGUAL A ALTURA DA SUBÁRVORE DIREITA DA SUBÁRVORE ESQUERDA
            return rotateRight(root); //ROTACIONA A ÁRVORE PARA A DIREITA
        else
        {
            //DUPLA ROTAÇÃO A DIREITA
            root->leftKid = rotateLeft(root->leftKid); //ROTACIONA A SUBÁRVORE ESQUERDA PARA A ESQUERDA
            return rotateRight(root); //ROTACIONA A ÁRVORE PARA A DIREITA
        }

    }
    else if(balance < -1)
    {
        if(height(root->rightKid->rightKid) >= height(root->rightKid->leftKid)) //SE A ALTURA DA SUBÁRVORE DIREITA DA SUBÁRVORE DIREITA FOR MAIOR OU IGUAL A ALTURA DA SUBÁRVORE ESQUERDA DA SUBÁRVORE DIREITA
            return rotateLeft(root); //ROTACIONA A ÁRVORE PARA A ESQUERDA
        else{
            //DUPLA ROTAÇÃO A ESQUERDA
            root->rightKid = rotateRight(root->rightKid); //ROTACIONA A SUBÁRVORE DIREITA PARA A DIREITA
            return rotateLeft(root); //ROTACIONA A ÁRVORE PARA A ESQUERDA
        }
    }
}*/

/*void printAVL(AVLNode *root, int space) // FUNÇÃO PARA IMPRIMIR A ÁRVORE AVL COM CAMINHAMENTO CENTRAL A ESQUERDAs
{
    if(root == NULL) // SE A RAIZ FOR NULA RETORNA
        return;
    
    space += 10; // INCREMENTA A DISTÂNCIA ENTRE OS NÓS

    printAVL(root->rightKid, space); // IMPRIME A SUBÁRVORE DIREITA

    printf("\n");
    for(int i = 10; i < space; i++) // IMPRIME OS ESPAÇOS
        printf(" ");
    printf("%d\n", root->key); // IMPRIME A CHAVE DO NÓ

    printAVL(root->leftKid, space); // IMPRIME A SUBÁRVORE ESQUERDA
}*/
  
