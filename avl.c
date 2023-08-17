#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

//CODIGOS DO MOODLE
AVLNode* insertAVLNode(AVLNode* node, int key, int *ok){
    
if (node == NULL) 
     {
      //printf("AAAAAAAAAAA");
     	node = (AVLNode*) malloc(sizeof(AVLNode));
        node->key = key;
        node->leftKid = NULL;
        node->rightKid = NULL;
        node->factor = 0; 
	    *ok = 1;
     }
     else if (key < node->key) 
     {
      //printf("BBBBBBBBBB");
		node->leftKid = insertAVLNode(node->leftKid,key,ok);
        if (*ok) 
        {
   		   switch (node->factor) {
               case -1:  node->factor = 0; *ok = 0; break;
               case  0:  node->factor = 1;  break;
               case  1:  node=firstCase(node,ok); break;
            }
         }
     }
	  else
     {
      //printf("CCCCCCCCCCC");
  		   node->rightKid = insertAVLNode(node->rightKid,key,ok);
            if (*ok)
            { 
               switch (node->factor) {
                  case  1:  node->factor = 0; *ok = 0; break;
                  case  0:  node->factor = -1; break;
                  case -1:  node = secondCase(node,ok); break;
               }
            }
     }
     return node;
}

AVLNode* rightRotation(AVLNode *pt){
   AVLNode* ptu;

   ptu = pt->leftKid; 
   pt->leftKid = ptu->rightKid; 
   ptu->rightKid = pt; 
   pt->factor = 0;
   pt = ptu; 
   return pt;
}

AVLNode* leftRotation(AVLNode *pt){
   AVLNode* ptu;

   ptu = pt->rightKid; 
   pt->rightKid = ptu->leftKid; 
   ptu->leftKid = pt; 
   pt->factor = 0;
   pt = ptu; 
   return pt;
} 

AVLNode* doubleRightRotation (AVLNode* pt){
   AVLNode* ptu, *ptv;

   ptu = pt->leftKid; 
   ptv = ptu->rightKid; 
   ptu->rightKid = ptv->leftKid; 
   ptv->leftKid = ptu; 
   pt->leftKid = ptv->rightKid; 
   ptv->rightKid = pt; 
   if (ptv->factor == 1)   pt->factor = -1;
      else pt->factor = 0;
   if (ptv->factor == -1)  ptu->factor = 1;
      else ptu->factor = 0;
   pt = ptv; 
   return pt;
} 

AVLNode* doubleLeftRotation (AVLNode* pt){
   AVLNode *ptu, *ptv;

   ptu = pt->rightKid; 
   ptv = ptu->leftKid; 
   ptu->leftKid = ptv->rightKid; 
   ptv->rightKid = ptu; 
   pt->rightKid = ptv->leftKid; 
   ptv->leftKid = pt; 
   if (ptv->factor == -1) pt->factor = 1;
     else pt->factor = 0;
   if (ptv->factor == 1) ptu->factor = -1;
      else ptu->factor = 0;
   pt = ptv; 
   return pt;
}

AVLNode* firstCase (AVLNode* node , int *ok)
{
   AVLNode *ptu; 

	ptu = node->leftKid;
	if (ptu->factor == 1) 
    {    
        node = rightRotation(node);
     }
    else
    {
        node = doubleRightRotation(node);
    }
	
    node->factor = 0;
	*ok = 0;
	return node;
}

AVLNode* secondCase (AVLNode *node , int *ok)
{
    AVLNode *ptu; 

	ptu = node->rightKid;
	if (ptu->factor == -1) 
    {
       node=leftRotation(node);
    }
    else
    {
       node=doubleLeftRotation(node);
    }
	node->factor = 0;
	*ok = 0;
	return node;
}


int height (AVLNode* node)
{
    int leftHeight, rightHeight;
    if (node == NULL)
      return 0;
    else
    {
       leftHeight = height (node->leftKid);
       rightHeight = height (node->rightKid);
       if (leftHeight > rightHeight)
         return (1 + leftHeight);
       else
         return (1 + rightHeight);
     }
}

int is_avl(AVLNode *node)
{
  int leftAlt, rightAlt;

  if (node!=NULL)
  {
     leftAlt = height(node->leftKid);
     rightAlt = height(node->rightKid);
     return ( (leftAlt - rightAlt <2) && (rightAlt - leftAlt <2) && (is_avl(node->leftKid)) && (is_avl(node->rightKid)) );
  }
  else
  return 1;
}

void printAVL(AVLNode *root, int space) 
{
    if(root == NULL) 
        return;
    
    space += 10; 

    printAVL(root->rightKid, space); 

    printf("\n");
    for(int i = 10; i < space; i++) 
        printf(" ");
    printf("%d\n", root->key); 

    printAVL(root->leftKid, space); 
}

int searchSmallerAVLNode(AVLNode *root){

    AVLNode *aux = root;

    while(aux->leftKid != NULL){
        aux = aux->leftKid;
    }

    return aux->key;
};

int searchBiggerAVLNode(AVLNode *root){
       AVLNode *aux = root;

    while(aux->rightKid != NULL){
        aux = aux->rightKid;
    }

    return aux->key;
};

int factor(AVLNode *node)
{
    return (height(node->leftKid) - height(node->rightKid));
}

void draw(AVLNode *node , int level)
{
   int x;

   if (node !=NULL){
      for (x=1; x<=level; x++)
      printf("=");
      printf("%d factor= %d\n", node->key, factor(node));
      if (node->leftKid != NULL) draw(node->leftKid, (level+1));
      if (node->rightKid != NULL) draw(node->rightKid, (level+1));
   }

}
  
