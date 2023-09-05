#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

//CODIGOS DO MOODLE
AVLNode* insertAVLNode(AVLNode* node, int key, int *ok, int *cont){
   
*cont += 1;
if (node == NULL) 
     {
     	node = (AVLNode*) malloc(sizeof(AVLNode));
        node->key = key;
        node->leftKid = NULL;
        node->rightKid = NULL;
        node->factor = 0; 
	    *ok = 1;
     }
     else if (key <= node->key) 
     {
		node->leftKid = insertAVLNode(node->leftKid,key,ok,cont);
      //CONTA IF E SWITCH
      *cont+=2;
        if (*ok) 
        {
   		   switch (node->factor) {
               case -1:  node->factor = 0; *ok = 0; break;
               case  0:  node->factor = 1;  break;
               case  1:  node=firstCase(node,ok,cont); break;
            }
         }
     }
	  else
     {
  		   node->rightKid = insertAVLNode(node->rightKid,key,ok,cont);
         //CONTA IF E SWITCH
         *cont+=2;
            if (*ok)
            { 
               switch (node->factor) {
                  case  1:  node->factor = 0; *ok = 0; break;
                  case  0:  node->factor = -1; break;
                  case -1:  node = secondCase(node,ok,cont); break;
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

AVLNode* doubleRightRotation (AVLNode* pt,int *cont){
   AVLNode* ptu, *ptv;

   ptu = pt->leftKid; 
   ptv = ptu->rightKid; 
   ptu->rightKid = ptv->leftKid; 
   ptv->leftKid = ptu; 
   pt->leftKid = ptv->rightKid; 
   ptv->rightKid = pt; 
   *cont+=2;
   if (ptv->factor == 1)   pt->factor = -1;
      else pt->factor = 0;
   if (ptv->factor == -1)  ptu->factor = 1;
      else ptu->factor = 0;
   pt = ptv; 
   return pt;
} 

AVLNode* doubleLeftRotation (AVLNode* pt,int *cont){
   AVLNode *ptu, *ptv;

   ptu = pt->rightKid; 
   ptv = ptu->leftKid; 
   ptu->leftKid = ptv->rightKid; 
   ptv->rightKid = ptu; 
   pt->rightKid = ptv->leftKid; 
   ptv->leftKid = pt; 
   *cont+=2;
   if (ptv->factor == -1) pt->factor = 1;
     else pt->factor = 0;
   if (ptv->factor == 1) ptu->factor = -1;
      else ptu->factor = 0;
   pt = ptv; 
   return pt;
}

AVLNode* firstCase (AVLNode* node , int *ok,int *cont)
{
   AVLNode *ptu; 

	ptu = node->leftKid;
   *cont+=1;
	if (ptu->factor == 1) 
    {    
        
        node = rightRotation(node);
     }
    else
    {
        node = doubleRightRotation(node, cont);
    }
	
    node->factor = 0;
	*ok = 0;
	return node;
}

AVLNode* secondCase (AVLNode *node , int *ok,int *cont)
{
    AVLNode *ptu; 

    *cont+=1;

	ptu = node->rightKid;
	if (ptu->factor == -1) 
    {
       node=leftRotation(node);
    }
    else
    {
       node=doubleLeftRotation(node,cont);
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

int searchSmallerAVLNode(AVLNode *root, int *cont){

   AVLNode *aux = root;

   while(aux->leftKid != NULL){
      *cont+=1;
      aux = aux->leftKid;
   }

   return aux->key;
};

int searchBiggerAVLNode(AVLNode *root, int *cont){
   AVLNode *aux = root;

   while(aux->rightKid != NULL){
      *cont+=1;
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


void searchMostRepeatedAVLNodes(AVLNode* root, int *mostRepeated, int *repetitions, int n, int *contC) {

   int cont,i,j;
   int test = 0;

   *contC+=1;
    if (root != NULL) {
      test = 0;
      cont = 0;


      //BUSCA A QUANTIDADE DE DUPLICADAS
      findDuplicates(root, mostRepeated, repetitions, n, root->key, &cont, contC);
      
      //SE ESTIVER ENTRE AS 10 MAIS REPETIDAS ENCONTRA A POSIÇÃO ONDE SE ENCONTRA
      *contC+=1;
      if(cont>repetitions[n-1]){

         //CASO SEJA O QUE MAIS SE REPETE INCLUI NA PRIMEIRA POSICAO
         *contC+=1;
         if(cont>=repetitions[0]){
               for(j=n-1;j>=0;j--){
                  *contC+=1;
                  mostRepeated[j+1] = mostRepeated[j];
                    repetitions[j+1] = repetitions[j];
               }
               mostRepeated[0] = root->key;
               repetitions[0] = cont;
         }

         else{
                
            for(i=n-2;i>=0;i--){
               //CONTA FOR E IF JUNTO
               *contC+=2;
                    
               //POSICIONA O NÚMERO IMEDIATAMENTE ANTES DE UM NÚMERO COM MAIS REPETICOES QUE ELE
               if(repetitions[i]>cont){
                  for(j=n-2;j>i;j--){
                     *contC+=1;
                     //DESLOCA OS NUMEROS COM MENOS REPETICOES UMA CASA PARA TRAS NO RANKING
                        mostRepeated[j+1] = mostRepeated[j];
                        repetitions[j+1] = repetitions[j];
                     }
                     //POSICIONA O NUMERO
                     mostRepeated[i+1] = root->key;
                     repetitions[i+1] = cont;
                     i=-1;
                  }
               }                
            }
        }

      searchMostRepeatedAVLNodes(root->leftKid, mostRepeated, repetitions, n, contC);          

      searchMostRepeatedAVLNodes(root->rightKid, mostRepeated, repetitions, n, contC);

    }
}

void findDuplicates(AVLNode* root, int *mostRepeated, int* repetitions, int n, int key, int *cont, int *contC){
   
   *contC+=1;
   if(root!=NULL){
      *contC+=1;
      if(root->key == key){
         *cont = *cont+1;
      }

      findDuplicates(root->leftKid, mostRepeated, repetitions, n, key, cont, contC);
      findDuplicates(root->rightKid, mostRepeated, repetitions, n, key, cont, contC);

   }
}

int searchMediumAVLNode(AVLNode* root, int *cont){

   int bigger = 0;
   int smaller = 0;
   int equal = 0;

   *cont+=1;
   if (root != NULL) {
      bigger = 0;
      smaller = 0;
      equal = 0;
     
      testMediumNode(root, root->key, &bigger,&smaller,&equal,cont);
      
      *cont+=1;
      if(abs(bigger-smaller)<equal+1){
         return root->key;
      }

      searchMediumAVLNode(root->leftKid, cont);          

      searchMediumAVLNode(root->rightKid, cont);

   }
   return 0;
}

void testMediumNode(AVLNode* node, int key, int* bigger, int* smaller, int* equal, int *cont){

   //CONTA OS DOIS IFS
   *cont+=2;
   if(node!=NULL){
      if(node->key>key){
         bigger++;
      }
      else if(node->key<key){
         smaller++;
      }
      else{
         equal++;
      }

      testMediumNode(node->leftKid, key, bigger, smaller, equal, cont);
      testMediumNode(node->rightKid, key, bigger, smaller, equal, cont);

   }


}
  
