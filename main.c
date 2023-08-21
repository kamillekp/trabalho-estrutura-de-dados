#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>


//#include "dll.h"
#include "dll.c"
//#include "avl.h"
#include "avl.c"

void insertDataDLL(DLLNode *head, int *data, int n);
AVLNode* insertDataAVL(AVLNode *root, int *data, int n);
void generateData(int n1, int *vetor);
void formatTime(long int difference, long int timeDLL, long int timeAVL); // FUNÇÃO PARA FORMATAR O TEMPO DE EXECUÇÃO
void bubbleSort(int data[], int orderedData[], int length);
void zeros(int arr[], int n);
void printArr(int arr[], int n);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int n[3] = {5000,10000,100000}, i, ok;

    clock_t startTime, endTime;
    double timeDifference, dataGenerationTime, timeDLL[3], timeAVL[3];

    int biggerDLL, biggerAVL, smallerDLL, smallerAVL, mediumDLL, mediumAVL;
    int biggerDLLSorted, biggerAVLSorted, smallerDLLSorted, smallerAVLSorted, mediumDLLSorted, mediumAVLSorted;

    int tenDLL[10], tenReps[10], tenAVL[10], fiftyDLL[50], fiftyReps[50], fiftyAVL[50];
    int tenDLLSorted[10], tenRepsSorted[10], tenAVLSorted[10], fiftyDLLSorted[50], fiftyRepsSorted[50], fiftyAVLSorted[50];


    int data1 [n[0]];
    int orderedData1 [n[0]];
    int data2 [n[1]];
    int orderedData2 [n[1]];
    int data3 [n[2]];
    int orderedData3 [n[2]];

    int* data[3] = {data1,data2,data3};
    int* orderedData[3] = {orderedData1,orderedData2,orderedData3};

    startTime = clock();
    for(i=0;i<3;i++){
        generateData(n[i], data[i]);
        bubbleSort(data[i],orderedData[i],n[i]);
    }
    endTime = clock();
    dataGenerationTime = (double)(endTime - startTime)/CLOCKS_PER_SEC;

//==========================================================================================================================================================
    // DADOS 1

    // CRIA STRUCTS DE DLL E AVL
    DLLNode *headDLL;
    DLLNode *headDLLSorted;
    AVLNode *rootAVL1,*rootAVL2,*rootAVL3;
    AVLNode *rootAVL1Sorted,*rootAVL2Sorted,*rootAVL3Sorted;
    AVLNode* rootAVL[3] = {rootAVL1,rootAVL2,rootAVL3};
    AVLNode* rootAVLSorted[3] = {rootAVL1Sorted,rootAVL2Sorted,rootAVL3Sorted};

    for(i=0;i<3;i++){


        printf("\n==================================");
        printf("\nConjunto de dados %d",i+1);
        printf("\n==================================");
        printf("\nDLL %d",i+1);
        printf("\n==================================");


        // CRIA DLL
        headDLL = createDLLNode(data[i][0]);
        headDLLSorted = createDLLNode(orderedData[i][0]);

        // INSERE NA DLL
        startTime = clock();
        insertDataDLL(headDLL,data[i], n[i]);
        insertDataDLL(headDLLSorted,orderedData[i], n[i]);
     

        //IMPRIME DLL
        //printDLL(headDLL);

        // BUSCA MAIOR NA DLL
        biggerDLL = searchBiggerDLLNode(headDLL);
        biggerDLLSorted = searchBiggerDLLNode(headDLLSorted);

        //IMPRIME MAIOR VALOR
        printf("\nMaior valor: %d",biggerDLL);
        printf("\nMaior valor sorted: %d",biggerDLLSorted);

        // BUSCA MENOR NA DLL
        smallerDLL = searchSmallerDLLNode(headDLL);
        smallerDLLSorted = searchSmallerDLLNode(headDLLSorted);

        //IMPRIME MENOR VALOR
        printf("\nMenor valor: %d",smallerDLL);
        printf("\nMenor valor sorted: %d",smallerDLLSorted);

        // VALOR MÉDIO NA DLL
        mediumDLL = searchMediumDLLNode(headDLL, 10);
        mediumDLLSorted = searchMediumDLLNode(headDLLSorted, 10);

        //IMPRIME VALOR MÉDIO
        printf("\nValor médio: %d",mediumDLL);
        printf("\nValor médio sorted: %d",mediumDLLSorted);

        // 10 MAIS REPETIDOS NA DLL

        searchMostRepeatedDLLNodes(headDLL,tenDLL,tenReps,10);
        searchMostRepeatedDLLNodes(headDLLSorted,tenDLLSorted,tenRepsSorted,10);
        
        printf("\n==================================");
        printf("\n10 mais repetidos");
        for(int i=0;i<10;i++){
            printf("\n%d aparece %d vezes", tenDLL[i],tenReps[i]);
        }
        printf("\n==================================");
        printf("\n10 mais repetidos (sorted)");
        for(int i=0;i<10;i++){
            printf("\n%d aparece %d vezes", tenDLLSorted[i],tenRepsSorted[i]);
        }

        // 50 MAIS REPETIDOS NA DLL

        searchMostRepeatedDLLNodes(headDLL,fiftyDLL,fiftyReps, 50);
        searchMostRepeatedDLLNodes(headDLLSorted,fiftyDLLSorted,fiftyRepsSorted, 50);
        endTime = clock();
        timeDLL[i] = (double)(endTime - startTime)/CLOCKS_PER_SEC;

        /*
        printf("\n==================================");
        printf("\n50 mais repetidos");
        for(int i=0;i<50;i++){
            printf("\n%d aparece %d vezes", fiftyDLL[i],fiftyReps[i]);
        }
        */

        destroyDLL(headDLL);
        destroyDLL(headDLLSorted);

        printf("\n==================================");
        printf("\nAVL %d",i+1);
        printf("\n==================================");

        //timeDLL = (double)(endTime - startTime)/CLOCKS_PER_SEC;
        //time_t startTime = clock();
        // CRIA AVL
        rootAVL[i] = NULL;
        rootAVLSorted[i] = NULL;

        // INSERE NA AVL

        startTime = clock();
        rootAVL[i]=insertDataAVL(rootAVL[i],data[i],n[i]);
        rootAVLSorted[i]=insertDataAVL(rootAVLSorted[i],orderedData[i],n[i]);
        endTime = clock();
        timeAVL[i] = (double)(endTime - startTime)/CLOCKS_PER_SEC;
       

        // BUSCA MAIOR NA AVL
        biggerAVL = searchBiggerAVLNode(rootAVL[i]);
        biggerAVLSorted = searchBiggerAVLNode(rootAVLSorted[i]);

        //IMPRIME MAIOR VALOR
        printf("\nMaior valor: %d",biggerAVL);
        printf("\nMaior valor sorted: %d",biggerAVLSorted);

        // BUSCA MENOR NA AVL
        
        smallerAVL = searchSmallerAVLNode(rootAVL[i]);
        smallerAVLSorted = searchSmallerAVLNode(rootAVLSorted[i]);


        //IMPRIME MENOR VALOR
        printf("\nMenor valor: %d",smallerAVL);
        printf("\nMenor valor sorted: %d",smallerAVLSorted);


        // VALOR MÉDIO NA AVL

        // 10 MAIS REPETIDO NA AVL

        for(int j=0;j<10;j++){
            tenAVL[j] = 0;
            tenReps[j] = 0;
            tenAVLSorted[j] = 0;
            tenRepsSorted[j] = 0;
        }

        searchMostRepeatedAVLNodes(rootAVL[i], tenAVL, tenReps, 10);
        searchMostRepeatedAVLNodes(rootAVL[i], tenAVLSorted, tenRepsSorted, 10);

        printf("\n==================================");
        printf("\n10 mais repetidos");
        for(int i=0;i<10;i++){
            printf("\n%d aparece %d vezes", tenAVL[i],tenReps[i]);
        }
        printf("\n==================================");
        printf("\n10 mais repetidos sorted");
        for(int i=0;i<10;i++){
            printf("\n%d aparece %d vezes", tenAVLSorted[i],tenRepsSorted[i]);
        }

        // 50 MAIS REPETIDO NA AVL

        for(int j=0;j<50;j++){
            fiftyAVL[j] = 0;
            fiftyReps[j] = 0;
            tenAVLSorted[j] = 0;
            tenRepsSorted[j] = 0;
        }

        searchMostRepeatedAVLNodes(rootAVL[i], fiftyAVL, fiftyReps, 50);
        searchMostRepeatedAVLNodes(rootAVL[i], tenAVLSorted, tenRepsSorted, 50);

        /*
        printf("\n==================================");
        printf("\n50 mais repetidos");
        for(int i=0;i<50;i++){
            printf("\n%d aparece %d vezes", fiftyAVL[i],fiftyReps[i]);
        }
        */

        /*time_t endtime = clock();
        timeAVL = (double)(endTime - startTime)/CLOCKS_PER_SEC;*/

        // VERIFICAÇÃO DE TEMPO DE EXECUÇÃO PARA CADA ESTRUTURA
        //timeDifference = abs(timeDLL - timeAVL);

        // VERIFICAR DIFERENÇA DO NÚMERO DE COMPARAÇÕES DE CADA (if/while/for...)


        // IMPRIME OS RESULTADOS
        //formatTime(timeDifference, timeDLL, timeAVL);

        // LIMPA AS STRUCTS
    }

    printf("\n==================================");
    printf("\nTempo de execução:");
    printf("\n==================================");

    printf("\nData generation");
    printf("\nElapsed time: %f seconds\n", dataGenerationTime);

    printf("\nDLL1");
    printf("\nElapsed time: %f seconds\n", timeDLL[0]);
    printf("\nDLL2");
    printf("\nElapsed time: %f seconds\n", timeDLL[1]);
    printf("\nDLL3");
    printf("\nElapsed time: %f seconds\n", timeDLL[2]);

    printf("\nAVL1");
    printf("\nElapsed time: %f seconds\n", timeAVL[0]);
    printf("\nAVL2");
    printf("\nElapsed time: %f seconds\n", timeAVL[1]);
    printf("\nAVL3");
    printf("\nElapsed time: %f seconds\n", timeAVL[2]);    

    return 0;
}

void insertDataDLL(DLLNode *head, int *data, int n){
    for(int i = 1; i < n; i++){
        insertDLLNode(head, data[i]);
    }
}

AVLNode* insertDataAVL(AVLNode *root, int *data, int n){
    int ok;
    for(int i = 1; i < n; i++){
        root = insertAVLNode(root, data[i],&ok);
    }
    return root;
}

void generateData (int num, int *vetor){
    srand(clock());


    if(num==100000){
        //A FUNÇÃO RAND É LIMITADA POR UM VALOR MÁXIMO
        //RAND_MAX = 32767
        //DESSA FORMA, SERÃO GERADOS 4 NÚMEROS ALEATÓRIOS EM UM INTERVALO MENOR
        int num2 = 25000;
        //GERA 90% DOS DADOS DE FORMA PSEUDOALEATÓRIA
        for(int i = 0; i < (0.9 * num); i ++){
            //NÃO SEI DIREITO COMO ISSO FUNCIONOU, MAS GERA UM NÚMERO ENTRE 1 E 100000.
            vetor[i] = 4*((rand() % num2-2)+3)-((rand() % 4)+1)+1;
        }

        //GERA 10% DOS DADOS QUE CERTAMENTE SÃO REPETIDOS
        for(int i = (0.9 * num); i < num; i ++){
            int j = floor((i-1)/4);
            //PEGA UM NÚMERO JÁ EXISTENTE NO ARRAY
            //int indice = rand()%(j)+rand()%(j)+rand()%(j)+rand()%(j);
            //GERA UM NÚMERO DE 1 A j-1, MULTIPLICA POR 4 E SUBTRAI UM NÚMERO ENTRE 0 E 4.
            int indice = 4*((rand() % j-2)+1)-(rand() % 4);
            int numero = vetor[indice];

            //COLOCA O NUMERO EM UM ÍNDICE QUALQUER DO ARRAY PARA QUE OS REPETIDOS NÃO FIQUEM SÓ NO FINAL
            indice = rand()%(i - 1);
            int aux = vetor[indice];
            vetor[indice] = numero;
            vetor[i] = aux;
        }
    }
    else{
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
