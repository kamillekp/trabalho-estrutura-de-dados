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

DLLNode* insertDLLNode(DLLNode* head, int k) {
    DLLNode *newNode = createDLLNode(k);

    DLLNode *aux = head;

    while(aux->right != NULL){
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

int searchSmallerDLLNode(DLLNode *head){
    DLLNode *aux = head;
    DLLNode *smaller = head;

    while(aux != NULL){
        if(aux->key < smaller->key){
            smaller = aux;
        }

        aux = aux->right;
    }

    return smaller->key;
}

int searchBiggerDLLNode(DLLNode *head){
    DLLNode *aux = head;
    DLLNode *bigger = head;

    while(aux != NULL){
        if(aux->key > bigger->key){
            bigger = aux;
        }

        aux = aux->right;
    }

    return bigger->key;
}

int mediaDLLNode(DLLNode *head, int tam){
    DLLNode *aux = head;
    int soma = 0;

    while(aux != NULL){
        soma += aux->key;
        aux = aux->right;
    }

    return soma/tam;
}

int searchMediumDLLNode(DLLNode *head, int tam){
    DLLNode *aux1 = head;
    DLLNode *aux2 = head;
    int bigger, smaller, equal;

    while(aux1 != NULL){
        bigger = 0;
        smaller = 0;
        equal = 0;
        while (aux2 != NULL){
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

void searchMostRepeatedDLLNodes(DLLNode *head, int *mostRepeated, int *repetitions, int n){
    DLLNode *aux1 = head;
    DLLNode *aux2;
    int i,j,cont;
    
    for(i=0;i<n;i++){
        mostRepeated[i] = 0;
        repetitions[i] = 0;
    }

    //PERCORRE TODOS OS TERMOS DA DLL
    while(aux1 != NULL){


        //VERIFICA SE O TERMO JÁ ESTÁ ENTRE OS 10 MAIS REPETIDOS
        for(i=0;i<n;i++){
            if(aux1->key == mostRepeated[i]){
                i=-1;
                //CASO JÁ ESTEJA, PASSA PRO PRÓXIMO E CHECA NOVAMENTE
                if(aux1!=NULL){  
                    aux1 = aux1->right;
                }
            }
        }        

        //CONTA AS REPETICOES
        cont = 0;
        aux2 = head;
        while(aux2 != NULL){
            if(aux2->key==aux1->key){
                cont++;
            }
            aux2 = aux2->right;
        }

        //SE ESTIVER ENTRE AS 10 MAIS REPETIDAS ENCONTRA A POSIÇÃO ONDE SE ENCONTRA
        if(cont>repetitions[n-1]){

            //CASO SEJA O QUE MAIS SE REPETE INCLUI NA PRIMEIRA POSICAO
            if(cont>=repetitions[0]){
                for(j=n-1;j>=0;j--){
                    mostRepeated[j+1] = mostRepeated[j];
                    repetitions[j+1] = repetitions[j];
                }
                mostRepeated[0] = aux1->key;
                repetitions[0] = cont;        
            }

            else{
                
                for(i=n-2;i>=0;i--){
                    
                    //POSICIONA O NÚMERO IMEDIATAMENTE ANTES DE UM NÚMERO COM MAIS REPETICOES QUE ELE
                    if(repetitions[i]>cont){
                        for(j=n-2;j>i;j--){
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


        if(aux1!=NULL){    
            aux1 = aux1->right;
        }
    }
};
