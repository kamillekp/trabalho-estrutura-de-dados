#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

DLLNode* createDLLNode(int k){
    DLLNode *newNode = (DLLNode *) malloc(sizeof(DLLNode));

    newNode->key = k;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

DLLNode* insertDLLNode(DLLNode* head, int k, int *cont) {
    DLLNode *newNode = createDLLNode(k);

    DLLNode *aux = head;

    while(aux->right != NULL){
        *cont+=1;
        aux = aux->right;
    }

    aux->right = newNode;
    newNode->left = aux;

    return head;
}

DLLNode *destroyDLL(DLLNode *head){

    DLLNode *aux;

    while (head != NULL) {
        aux = head;
        head = head->right;
        free(aux);
    }

    return NULL; // Return NULL to indicate that the list is empty after destruction
};

int searchSmallerDLLNode(DLLNode *head, int *cont){
    DLLNode *aux = head;
    DLLNode *smaller = head;

    while(aux != NULL){
        //CONTA O WHILE E O IF JUNTO
        *cont+=2;
        if(aux->key < smaller->key){
            smaller = aux;
        }

        aux = aux->right;
    }

    return smaller->key;
}

int searchBiggerDLLNode(DLLNode *head, int *cont){
    DLLNode *aux = head;
    DLLNode *bigger = head;

    while(aux != NULL){
        //CONTA O WHILE E O IF JUNTO
        *cont+=2;
        if(aux->key > bigger->key){
            bigger = aux;
        }

        aux = aux->right;
    }

    return bigger->key;
}

int searchMediumDLLNode(DLLNode *head, int tam, int *cont){
    DLLNode *aux1 = head;
    DLLNode *aux2 = head;
    int bigger, smaller, equal;

    while(aux1 != NULL){
        *cont+=1;
        bigger = 0;
        smaller = 0;
        equal = 0;
        while (aux2 != NULL){
            //CONTA O WHILE E O IF JUNTO
            *cont+=2;
            if(aux2->key>aux1->key){
                bigger++;
            }
            else if(aux2->key<aux1->key){
                smaller++;
            }
            else{
                equal++;
            }
            aux2 = aux2->right;
        }

        //SE O NÚMERO TIVER EXATAMENTE NO MEIO DO CONJUNTO DE DADOS RETORNA O VALOR DELE 
        //(HÁ DUAS POSSIBILIDADES PARA CONJUNTO COM QUANTIDADE PAR DE DADOS)
        *cont+=1;
        if(abs(bigger-smaller)<equal+1){
            return aux1->key;
        }
        aux1 = aux1->right;
        aux2 = head;
    }
}

void printDLL(DLLNode *head){
    DLLNode *aux = head;

    while(aux != NULL){
        printf("%d  ", aux->key);
        aux = aux->right;
    }

    printf("\n");
}

void searchMostRepeatedDLLNodes(DLLNode *head, int *mostRepeated, int *repetitions, int n, int *contC){
    DLLNode *aux1 = head;
    DLLNode *aux2;
    int i,j,cont;
    
    *contC+=1;
    for(i=0;i<n;i++){
        mostRepeated[i] = 0;
        repetitions[i] = 0;
    }

    //PERCORRE TODOS OS TERMOS DA DLL
    while(aux1 != NULL){
        *contC+=1;

        //VERIFICA SE O TERMO JÁ ESTÁ ENTRE OS 10 MAIS REPETIDOS
        for(i=0;i<n;i++){
            //CONTA O FOR E O IF JUNTO
            *contC+=2;
            if(aux1->key == mostRepeated[i]){
                i=-1;
                //CASO JÁ ESTEJA, PASSA PRO PRÓXIMO E CHECA NOVAMENTE
                *contC+=1;
                if(aux1!=NULL){  
                    aux1 = aux1->right;
                }
            }
        }        

        //CONTA AS REPETICOES
        cont = 0;
        aux2 = head;
        while(aux2 != NULL){
            //CONTA O WHILE E O IF JUNTO
            *contC+=2;
            if(aux2->key==aux1->key){
                cont++;
            }
            aux2 = aux2->right;
        }

        //SE ESTIVER ENTRE AS 10 MAIS REPETIDAS ENCONTRA A POSIÇÃO ONDE SE ENCONTRA
        *contC+=1;
        if(cont>repetitions[n-1]){

            *contC+=1;
            //CASO SEJA O QUE MAIS SE REPETE INCLUI NA PRIMEIRA POSICAO
            if(cont>=repetitions[0]){
                for(j=n-1;j>=0;j--){
                    *contC+=1;
                    mostRepeated[j+1] = mostRepeated[j];
                    repetitions[j+1] = repetitions[j];
                }
                mostRepeated[0] = aux1->key;
                repetitions[0] = cont;        
            }

            else{
                
                for(i=n-2;i>=0;i--){

                    //CONTA O FOR E O IF JUNTO
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
                        mostRepeated[i+1] = aux1->key;
                        repetitions[i+1] = cont;
                        i=-1;
                    }
                }
                
            }
        }

        *contC+=1;
        if(aux1!=NULL){    
            aux1 = aux1->right;
        }
    }
};
