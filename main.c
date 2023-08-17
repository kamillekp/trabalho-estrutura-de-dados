#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>


//#include "dll.h"
#include "dll.c"
//#include "avl.h"
#include "avl.c"

void insertData(DLLNode *head, int *data, int n);
void generateData(int n1, int *vetor);
void formatTime(long int difference, long int timeDLL, long int timeAVL); // FUNÇÃO PARA FORMATAR O TEMPO DE EXECUÇÃO
void bubbleSort(int data[], int orderedData[], int length);
void zeros(int arr[], int n);
void printArr(int arr[], int n);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int n[3] = {5000,10000,100000}, i;

    //time_t timeDifference, timeDLL, timeAVL;

    int biggerDLL, biggerAVL, smallerDLL, smallerAVL, mediumDLL, mediumAVL;

    int tenDLL[10], tenReps[10], tenAVL[10], fiftyDLL[50], fiftyReps[50], fiftyAVL[50];


    int data1 [n[0]];
    int orderedData1 [n[0]];
    int data2 [n[1]];
    int orderedData2 [n[1]];
    int data3 [n[2]];
    int orderedData3 [n[2]];

    int* data[3] = {data1,data2,data3};
    int* orderedData[3] = {orderedData1,orderedData2,orderedData3};

    for(i=0;i<3;i++){
        generateData(n[i], data[i]);
        bubbleSort(data[i],orderedData[i],n[i]);
    }

//==========================================================================================================================================================
    // DADOS 1

    // CRIA STRUCTS DE DLL E AVL
    DLLNode *headDLL;
    AVLNode *rootAVL;

    for(i=0;i<3;i++){
        //time_t startTime = time(NULL);
        printf("\n==================================");
        printf("\nConjunto de dados %d",i+1);
        printf("\n==================================");

        // CRIA DLL
        headDLL = createDLLNode(data[i][0]);

        // INSERE NA DLL
        insertData(headDLL,data[i], n[i]);

        //IMPRIME DLL
        //printDLL(headDLL);

        // BUSCA MAIOR NA DLL
        biggerDLL = searchBiggerDLLNode(headDLL);

        //IMPRIME MAIOR VALOR
        printf("\nMaior valor: %d",biggerDLL);

        // BUSCA MENOR NA DLL
        smallerDLL = searchSmallerDLLNode(headDLL);

        //IMPRIME MENOR VALOR
        printf("\nMenor valor: %d",smallerDLL);

        // VALOR MÉDIO NA DLL
        mediumDLL = searchMediumDLLNode(headDLL, 10);

        //IMPRIME VALOR MÉDIO
        printf("\nValor médio: %d",mediumDLL);

        // 10 MAIS REPETIDO NA DLL

        searchMostRepeatedDLLNodes(headDLL,tenDLL,tenReps,10);
        
        printf("\n==================================");
        printf("\n10 mais repetidos");
        for(int i=0;i<10;i++){
            printf("\n%d aparece %d vezes", tenDLL[i],tenReps[i]);
        }

        // 50 MAIS REPETIDO NA DLL

        searchMostRepeatedDLLNodes(headDLL,fiftyDLL,fiftyReps, 50);
        
        /*
        printf("\n==================================");
        printf("\n50 mais repetidos");
        for(int i=0;i<50;i++){
            printf("\n%d aparece %d vezes", fiftyDLL[i],fiftyReps[i]);
        }*/

        destroyDLL(headDLL);

        //timeDLL = abs(endTime - startTime);
        //time_t startTime = time(NULL);
        // CRIA AVL

        // INSERE NA AVL

        // BUSCA MAIOR NA AVL

        // BUSCA MENOR NA AVL

        // VALOR MÉDIO NA AVL

        // 10 MAIS REPETIDO NA AVL

        // 50 MAIS REPETIDO NA AVL
        /*time_t endtime = time(NULL);
        timeAVL = abs(endtime - startTime);*/

        // VERIFICAÇÃO DE TEMPO DE EXECUÇÃO PARA CADA ESTRUTURA
        //timeDifference = abs(timeDLL - timeAVL);

        // VERIFICAR DIFERENÇA DO NÚMERO DE COMPARAÇÕES DE CADA (if/while/for...)

        // IMPRIME OS RESULTADOS
        //formatTime(timeDifference, timeDLL, timeAVL);

        // LIMPA AS STRUCTS
    }

    

    return 0;
}

void insertData(DLLNode *head, int *data, int n){
    for(int i = 1; i < n; i++){
        insertDLLNode(head, data[i]);
    }
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

//CHAT GPT
void bubbleSort(int data[], int orderedData[], int length) {

    for (int i = 0; i < length; i++) {
        orderedData[i] = data[i];
    }

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (orderedData[j] > orderedData[j + 1]) {
                // Swap the elements
                int temp = orderedData[j];
                orderedData[j] = orderedData[j + 1];
                orderedData[j + 1] = temp;
            }
        }
    }
}

void zeros(int arr[], int n){
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
}

void printArr(int arr[], int n){
    printf("%d",n);
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
}
