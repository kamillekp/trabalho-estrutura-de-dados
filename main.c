#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

#include "compare.h"

void generateData(int n1, int *vetor);
void formatTime(long int difference, long int timeDLL, long int timeAVL);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int n1 = 5000, n2 = 10000, n3 = 100000;
    time_t timeDifference, timeDLL, timeAVL;
    
    int dados1 [n1];
    int dados2 [n2];
    int dados3 [n3];
        
    //PARA O CONJUNTO DE DADOS 1
    generateData(n1, dados1);
    //PARA O CONJUNTO DE DADOS 2
    generateData(n2, dados2);
    //PARA O CONJUNTO DE DADOS 3
    generateData(n3, dados3); 

    time_t startTime = time(NULL);
    // CRIA DLL 

    // INSERE NA DLL 

    // BUSCA MAIOR NA DLL 

    // BUSCA MENOR NA DLL 

    // BUSCA VALOR MÉDIO NA DLL 

    // 10 MAIS REPETIDO NA DLL 

    // 50 MAIS REPETIDO NA DLL 
    time_t endTime = time(NULL);

    timeDLL = abs(endTime - startTime);

    time_t startTime = time(NULL);
    // CRIA AVL
    
    // INSERE NA AVL

    // BUSCA MAIOR NA AVL 

    // BUSCA MENOR NA AVL 

    // BUSCA VALOR MÉDIO NA AVL 

    // 10 MAIS REPETIDO NA AVL 

    // 50 MAIS REPETIDO NA AVL
    time_t endtime = time(NULL);
    
    timeAVL = abs(endtime - startTime);

    timeDifference = abs(timeDLL - timeAVL);
    formatTime(timeDifference, timeDLL, timeAVL);


    // VERIFICAR DIFERENÇA DO NÚMERO DE COMPARAÇÕES DE CADA (if/while/for...)

    return 0;
}

void generateData (int num, int *vetor){
    srand(time(NULL));

    //GERA 90% DOS DADOS DE FORMA PSEUDOALEATÓRIA
    for(int i = 0; i < (0.9 * num); i ++){
        vetor[i] = (rand() % num)+1;
    }

    //GERA 10% DOS DADOS QUE CERTAMENTE SÃO REPETIDOS
    for(int i = (0.9 * num); i < num; i ++){
        //PEGA UM NÚMERO JÁ EXISTENTE NO ARRAY
        int indice = rand()%(i - 1);
        int numero = vetor[indice];

        //COLOCA O NUMERO EM UM ÍNDICE QUALQUER DO ARRAY PARA QUE OS REPETIDOS NÃO FIQUEM SÓ NO FINAL
        indice = rand()%(i - 1);
        int aux = vetor[indice];
        vetor[indice] = numero;
        vetor[i] = aux;
    }
}

void formatTime(long int difference, long int timeDLL, long int timeAVL){
    int flag = 0;

    if(timeDLL > timeAVL)
        flag = 1;

    if(difference >= 60)
        if(flag == 1)
            printf("A DLL demorou %ld minutos a mais que a AVL.\n", difference / 60);
        else
            printf("A AVL demorou %ld minutos a mais que a DLL.\n", difference / 60);
    else if(difference >= 3600)
        if(flag == 1)
            printf("A DLL demorou %ld horas a mais que a AVL.\n", difference / 3600);
        else
            printf("A AVL demorou %ld horas a mais que a DLL.\n", difference / 3600);
    else
        if(flag == 1)
            printf("A DLL demorou %ld segundos a mais que a AVL.\n", difference);
        else
            printf("A AVL demorou %ld segundos a mais que a DLL.\n", difference);
}

void compareComparisons(int compara1, int compara2){
    // COMPARA O NÚMERO DE COMPARAÇÕES DA DLL E DA AVL
}
