#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <windows.h>
#include "dll.c"
#include "avl.c"
#define NUM 3

void insertDataDLL(DLLNode *head, int *data, int n, int *cont);
AVLNode* insertDataAVL(AVLNode *root, int *data, int n, int *cont);
void generateData(int n1, int *vetor);
void bubbleSort(int data[], int orderedData[], int length);
void zeros(int arr[], int n);
void printArr(int arr[], int n);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int n[3] = {5000,10000,100000}, i, ok, aux;
    int cont;

    LARGE_INTEGER start_time, end_time, frequency;

    //TESTE 1
    long long timeInsertDLL[3], timeInsertDLLSorted[3], timeInsertAVL[3], timeInsertAVLSorted[3];
    double timeInsertDLLDecimal[3], timeInsertDLLSortedDecimal[3], timeInsertAVLDecimal[3], timeInsertAVLSortedDecimal[3];
    int contInsertDLL[3], contInsertDLLSorted[3], contInsertAVL[3], contInsertAVLSorted[3];

    //TESTE 2
    long long timeBiggerSmallerDLL[3], timeBiggerSmallerDLLSorted[3], timeBiggerSmallerAVL[3], timeBiggerSmallerAVLSorted[3];
    double timeBiggerSmallerDLLDecimal[3], timeBiggerSmallerDLLSortedDecimal[3], timeBiggerSmallerAVLDecimal[3], timeBiggerSmallerAVLSortedDecimal[3];
    int contBiggerSmallerDLL[3], contBiggerSmallerDLLSorted[3], contBiggerSmallerAVL[3], contBiggerSmallerAVLSorted[3];

    //TESTE 3
    long long timeMediumValueDLL[3], timeMediumValueDLLSorted[3], timeMediumValueAVL[3], timeMediumValueAVLSorted[3];
    double timeMediumValueDLLDecimal[3], timeMediumValueDLLSortedDecimal[3], timeMediumValueAVLDecimal[3], timeMediumValueAVLSortedDecimal[3];
    int contMediumValueDLL[3], contMediumValueDLLSorted[3], contMediumValueAVL[3], contMediumValueAVLSorted[3];

    //TESTE 4
    long long timeTenMostRepeatedDLL[3], timeTenMostRepeatedDLLSorted[3], timeTenMostRepeatedAVL[3], timeTenMostRepeatedAVLSorted[3];
    double timeTenMostRepeatedDLLDecimal[3], timeTenMostRepeatedDLLSortedDecimal[3], timeTenMostRepeatedAVLDecimal[3], timeTenMostRepeatedAVLSortedDecimal[3];
    int contTenMostRepeatedAVL[3], contTenMostRepeatedAVLSorted[3];
    unsigned long long contTenMostRepeatedDLL[3], contTenMostRepeatedDLLSorted[3];

    //TESTE 5
    long long timeFiftyMostRepeatedDLL[3], timeFiftyMostRepeatedDLLSorted[3], timeFiftyMostRepeatedAVL[3], timeFiftyMostRepeatedAVLSorted[3];
    double timeFiftyMostRepeatedDLLDecimal[3], timeFiftyMostRepeatedDLLSortedDecimal[3], timeFiftyMostRepeatedAVLDecimal[3], timeFiftyMostRepeatedAVLSortedDecimal[3];
    int contFiftyMostRepeatedAVL[3], contFiftyMostRepeatedAVLSorted[3];
    unsigned long long contFiftyMostRepeatedDLL[3], contFiftyMostRepeatedDLLSorted[3];

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

    QueryPerformanceFrequency(&frequency);

    startTime = clock();
    for(i=0;i<NUM;i++){
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

    for(i=0;i<NUM;i++){

        aux = n[i];

        printf("\n==================================");
        printf("\nConjunto de dados %d",i+1);
        printf("\n==================================");
        printf("\nDLL %d",i+1);
        printf("\n==================================");


        // CRIA DLL
        headDLL = createDLLNode(data[i][0]);
        headDLLSorted = createDLLNode(orderedData[i][0]);


        // INSERE NA DLL
        QueryPerformanceCounter(&start_time);
        insertDataDLL(headDLL,data[i], aux, &cont);
        contInsertDLL[i] = cont;
        QueryPerformanceCounter(&end_time);


        timeInsertDLL[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeInsertDLLDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeInsertDLL[i];

        QueryPerformanceCounter(&start_time);
        insertDataDLL(headDLLSorted,orderedData[i], aux, &cont);
        contInsertDLLSorted[i] = cont;
        QueryPerformanceCounter(&end_time);


        timeInsertDLLSorted[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeInsertDLLSortedDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeInsertDLLSorted[i];

        // BUSCA MAIOR E MENOR NA DLL

        cont = 0;
        QueryPerformanceCounter(&start_time);
        biggerDLL = searchBiggerDLLNode(headDLL, &cont);
        smallerDLL = searchSmallerDLLNode(headDLL, &cont);
        contBiggerSmallerDLL[i] = cont;
        cont = 0;
        QueryPerformanceCounter(&end_time);

        timeBiggerSmallerDLL[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeBiggerSmallerDLLDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeBiggerSmallerDLL[i];

        QueryPerformanceCounter(&start_time);
        biggerDLLSorted = searchBiggerDLLNode(headDLLSorted, &cont);
        smallerDLLSorted = searchSmallerDLLNode(headDLLSorted, &cont);
        contBiggerSmallerDLLSorted[i] = cont;
        cont = 0;
        QueryPerformanceCounter(&end_time);

        timeBiggerSmallerDLLSorted[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeBiggerSmallerDLLSortedDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeBiggerSmallerDLLSorted[i];

        //IMPRIME MAIOR VALOR
        printf("\nMaior valor: %d",biggerDLL);
        printf("\nMaior valor sorted: %d",biggerDLLSorted);

        //IMPRIME MENOR VALOR
        printf("\nMenor valor: %d",smallerDLL);
        printf("\nMenor valor sorted: %d",smallerDLLSorted);

        // VALOR MÉDIO NA DLL

        QueryPerformanceCounter(&start_time);
        mediumDLL = searchMediumDLLNode(headDLL, aux, &cont);
        QueryPerformanceCounter(&end_time);
        contMediumValueDLL[i] = cont;
        cont = 0;
        timeMediumValueDLL[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeMediumValueDLLDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeMediumValueDLL[i];

        QueryPerformanceCounter(&start_time);
        mediumDLLSorted = searchMediumDLLNode(headDLLSorted, aux, &cont);
        QueryPerformanceCounter(&end_time);
        contMediumValueDLLSorted[i] = cont;
        cont = 0;
        timeMediumValueDLLSorted[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeMediumValueDLLSortedDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeMediumValueDLLSorted[i];

        //IMPRIME VALOR MÉDIO
        printf("\nValor médio: %d",mediumDLL);
        printf("\nValor médio sorted: %d",mediumDLLSorted);

        // 10 MAIS REPETIDOS NA DLL

        QueryPerformanceCounter(&start_time);
        searchMostRepeatedDLLNodes(headDLL,tenDLL,tenReps,10,&cont);
        QueryPerformanceCounter(&end_time);
        contTenMostRepeatedDLL[i] = cont;
        cont = 0;
        timeTenMostRepeatedDLL[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeTenMostRepeatedDLLDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeTenMostRepeatedDLL[i];

        QueryPerformanceCounter(&start_time);
        searchMostRepeatedDLLNodes(headDLLSorted,tenDLLSorted,tenRepsSorted,10,&cont);
        QueryPerformanceCounter(&end_time);
        contTenMostRepeatedDLLSorted[i] = cont;
        cont = 0;
        timeTenMostRepeatedDLLSorted[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeTenMostRepeatedDLLSortedDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeTenMostRepeatedDLLSorted[i];
        
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

        QueryPerformanceCounter(&start_time);
        searchMostRepeatedDLLNodes(headDLL,fiftyDLL,fiftyReps, 50,&cont);
        QueryPerformanceCounter(&end_time);
        contFiftyMostRepeatedDLL[i] = cont;
        cont = 0;
        timeFiftyMostRepeatedDLL[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeFiftyMostRepeatedDLLDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeFiftyMostRepeatedDLL[i];

        QueryPerformanceCounter(&start_time);
        searchMostRepeatedDLLNodes(headDLLSorted,fiftyDLLSorted,fiftyRepsSorted, 50, &cont);
        QueryPerformanceCounter(&end_time);
        contFiftyMostRepeatedDLLSorted[i] = cont;
        cont = 0;
        timeFiftyMostRepeatedDLLSorted[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeFiftyMostRepeatedDLLSortedDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeFiftyMostRepeatedDLLSorted[i];

        headDLL = destroyDLL(headDLL);
        headDLLSorted = destroyDLL(headDLLSorted);

        printf("\n==================================");
        printf("\nAVL %d",i+1);
        printf("\n==================================");

        // CRIA AVL
        rootAVL[i] = NULL;
        rootAVLSorted[i] = NULL;

        // INSERE NA AVL

        QueryPerformanceCounter(&start_time);
        rootAVL[i]=insertDataAVL(rootAVL[i],data[i], aux, &cont);
        contInsertAVL[i] = cont;

        QueryPerformanceCounter(&end_time);
        timeInsertAVL[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeInsertAVLDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeInsertAVL[i];

        QueryPerformanceCounter(&start_time);
        rootAVLSorted[i]=insertDataAVL(rootAVLSorted[i],orderedData[i], aux, &cont);
        contInsertAVLSorted[i] = cont;

        QueryPerformanceCounter(&end_time);
        timeInsertAVLSorted[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeInsertAVLSortedDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeInsertAVLSorted[i];
        
        // BUSCA MAIOR E MAIOR NA AVL
        cont = 0;
        QueryPerformanceCounter(&start_time);
        biggerAVL = searchBiggerAVLNode(rootAVL[i], &cont);
        smallerAVL = searchSmallerAVLNode(rootAVL[i], &cont);
        QueryPerformanceCounter(&end_time);
        contBiggerSmallerAVL[i] = cont;
        cont = 0;
        timeBiggerSmallerAVL[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeBiggerSmallerAVLDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeBiggerSmallerAVL[i];

        QueryPerformanceCounter(&start_time);
        biggerAVLSorted = searchBiggerAVLNode(rootAVLSorted[i],&cont);
        smallerAVLSorted = searchSmallerAVLNode(rootAVLSorted[i],&cont);
        QueryPerformanceCounter(&end_time);
        contBiggerSmallerAVLSorted[i] = cont;
        cont = 0;
        timeBiggerSmallerAVLSorted[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeBiggerSmallerAVLSortedDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeBiggerSmallerAVLSorted[i];

        //IMPRIME MAIOR VALOR
        printf("\nMaior valor: %d",biggerAVL);
        printf("\nMaior valor sorted: %d",biggerAVLSorted);

        //IMPRIME MENOR VALOR
        printf("\nMenor valor: %d",smallerAVL);
        printf("\nMenor valor sorted: %d",smallerAVLSorted);

        // VALOR MÉDIO NA AVL

        QueryPerformanceCounter(&start_time);
        mediumAVL = searchMediumAVLNode(rootAVL[i], &cont);
        QueryPerformanceCounter(&end_time);
        contMediumValueAVL[i] = cont;
        cont = 0;
        timeMediumValueAVL[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeMediumValueAVLDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeMediumValueAVL[i];

        QueryPerformanceCounter(&start_time);
        mediumAVLSorted = searchMediumAVLNode(rootAVLSorted[i],&cont);
        QueryPerformanceCounter(&end_time);
        contMediumValueAVLSorted[i] = cont;
        cont = 0;
        timeMediumValueAVLSorted[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeMediumValueAVLSortedDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeMediumValueAVLSorted[i];

        //IMPRIME VALOR MÉDIO
        printf("\nValor médio: %d",mediumDLL);
        printf("\nValor médio sorted: %d",mediumDLLSorted);

        // 10 MAIS REPETIDO NA AVL

        for(int j=0;j<10;j++){
            tenAVL[j] = 0;
            tenReps[j] = 0;
            tenAVLSorted[j] = 0;
            tenRepsSorted[j] = 0;
        }

        QueryPerformanceCounter(&start_time);
        searchMostRepeatedAVLNodes(rootAVL[i], tenAVL, tenReps, 10,&cont);
        QueryPerformanceCounter(&end_time);
        contTenMostRepeatedAVL[i] = cont;
        cont = 0;
        timeTenMostRepeatedAVL[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeTenMostRepeatedAVLDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeTenMostRepeatedAVL[i];

        QueryPerformanceCounter(&start_time);
        searchMostRepeatedAVLNodes(rootAVL[i], tenAVLSorted, tenRepsSorted, 10,&cont);
        QueryPerformanceCounter(&end_time);
        contTenMostRepeatedAVLSorted[i] = cont;
        cont = 0;
        timeTenMostRepeatedAVLSorted[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeTenMostRepeatedAVLSortedDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeTenMostRepeatedAVLSorted[i];

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

        QueryPerformanceCounter(&start_time);
        searchMostRepeatedAVLNodes(rootAVL[i], fiftyAVL, fiftyReps, 50, &cont);
        QueryPerformanceCounter(&end_time);
        contFiftyMostRepeatedAVL[i] = cont;
        cont = 0;
        timeFiftyMostRepeatedAVL[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeFiftyMostRepeatedAVLDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeFiftyMostRepeatedAVL[i];

        QueryPerformanceCounter(&start_time);
        searchMostRepeatedAVLNodes(rootAVL[i], tenAVLSorted, tenRepsSorted, 50, &cont);
        QueryPerformanceCounter(&end_time);
        contFiftyMostRepeatedAVLSorted[i] = cont;
        cont = 0;
        timeFiftyMostRepeatedAVLSorted[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000) / frequency.QuadPart;
        timeFiftyMostRepeatedAVLSortedDecimal[i] = ((end_time.QuadPart - start_time.QuadPart) * 1000.0 / frequency.QuadPart) - timeFiftyMostRepeatedAVLSorted[i];

    }

    printf("\n==================================");
    printf("\nTESTES:");
    printf("\n==================================");

    printf("\nData generation");
    printf("\nElapsed time: %f seconds", dataGenerationTime);
    
    printf("\n==================================");
    printf("\nInserção:");
    printf("\n==================================");

    for(int j = 0;j<NUM;j++){
        printf("\nInsert DLL %d",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeInsertDLL[j],(long long)(timeInsertDLLDecimal[j] * 1000));
        printf("\nComparisons: %d", contInsertDLL[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nInsert DLL %d (Sorted)",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeInsertDLLSorted[j],(long long)(timeInsertDLLSortedDecimal[j] * 1000));
        printf("\nComparisons: %d", contInsertDLLSorted[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nInsert AVL %d",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeInsertAVL[j],(long long)(timeInsertAVLDecimal[j] * 1000));
        printf("\nComparisons: %d", contInsertAVL[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nInsert AVL %d (Sorted)",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeInsertAVLSorted[j],(long long)(timeInsertAVLSortedDecimal[j] * 1000));
        printf("\nComparisons: %d", contInsertAVLSorted[j]);
        printf("\n----------------------------------");
    }

    printf("\n==================================");
    printf("\nMaior e menor:");
    printf("\n==================================");


    for(int j = 0;j<NUM;j++){
        printf("\nBiggerSmaller DLL %d",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeBiggerSmallerDLL[j],(long long)(timeBiggerSmallerDLLDecimal[j] * 1000));
        printf("\nComparisons: %d", contBiggerSmallerDLL[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nBiggerSmaller DLL %d (Sorted)",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeBiggerSmallerDLLSorted[j],(long long)(timeBiggerSmallerDLLSortedDecimal[j] * 1000));
        printf("\nComparisons: %d", contBiggerSmallerDLLSorted[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nBiggerSmaller AVL %d",j+1);
        printf("\nElapsed time: %lld,%lld microsseconds", timeBiggerSmallerAVL[j],timeBiggerSmallerAVLDecimal[j]);
        printf("\nComparisons: %d", contBiggerSmallerAVL[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nBiggerSmaller AVL %d (Sorted)",j+1);
        printf("\nElapsed time: %lld,%lld microsseconds", timeBiggerSmallerAVLSorted[j],timeBiggerSmallerAVLSortedDecimal[j]);
        printf("\nComparisons: %d", contBiggerSmallerAVLSorted[j]);
        printf("\n----------------------------------");
    }

    printf("\n==================================");
    printf("\nValor médio:");
    printf("\n==================================");


    for(int j = 0;j<NUM;j++){
        printf("\nMediumValue DLL %d",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeMediumValueDLL[j],(long long)(timeMediumValueDLLDecimal[j] * 1000));
        printf("\nComparisons: %d", contMediumValueDLL[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nMediumValue DLL %d (Sorted)",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeMediumValueDLLSorted[j],(long long)(timeMediumValueDLLSortedDecimal[j] * 1000));
        printf("\nComparisons: %d", contMediumValueDLLSorted[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nMediumValue AVL %d",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeMediumValueAVL[j],(long long)(timeMediumValueAVLDecimal[j] * 1000));
        printf("\nComparisons: %d", contMediumValueAVL[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nMediumValue AVL %d (Sorted)",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeMediumValueAVLSorted[j],(long long)(timeMediumValueAVLSortedDecimal[j] * 1000));
        printf("\nComparisons: %d", contMediumValueAVLSorted[j]);
        printf("\n----------------------------------");
    }

    printf("\n==================================");
    printf("\n10 mais repetidos:");
    printf("\n==================================");

    for(int j = 0;j<NUM;j++){
        printf("\nTenMostRepeated DLL %d",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeTenMostRepeatedDLL[j],(long long)(timeTenMostRepeatedDLLDecimal[j] * 1000));
        printf("\nComparisons: %llu", contTenMostRepeatedDLL[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nTenMostRepeated DLL %d (Sorted)",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeTenMostRepeatedDLLSorted[j],(long long)(timeTenMostRepeatedDLLSortedDecimal[j] * 1000));
        printf("\nComparisons: %llu", contTenMostRepeatedDLLSorted[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nTenMostRepeated AVL %d",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeTenMostRepeatedAVL[j],(long long)(timeTenMostRepeatedAVLDecimal[j] * 1000));
        printf("\nComparisons: %d", contTenMostRepeatedAVL[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nTenMostRepeated AVL %d (Sorted)",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeTenMostRepeatedAVLSorted[j],(long long)(timeTenMostRepeatedAVLSortedDecimal[j] * 1000));
        printf("\nComparisons: %d", contTenMostRepeatedAVLSorted[j]);
        printf("\n----------------------------------");
    }

    printf("\n==================================");
    printf("\n50 mais repetidos:");
    printf("\n==================================");

    for(int j = 0;j<NUM;j++){
        printf("\nFiftyMostRepeated DLL %d",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeFiftyMostRepeatedDLL[j],(long long)(timeFiftyMostRepeatedDLLDecimal[j] * 1000));
        printf("\nComparisons: %llu", contFiftyMostRepeatedDLL[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nFiftyMostRepeated DLL %d (Sorted)",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeFiftyMostRepeatedDLLSorted[j],(long long)(timeFiftyMostRepeatedDLLSortedDecimal[j] * 1000));
        printf("\nComparisons: %llu", contFiftyMostRepeatedDLLSorted[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nFiftyMostRepeated AVL %d",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeFiftyMostRepeatedAVL[j],(long long)(timeFiftyMostRepeatedAVLDecimal[j] * 1000));
        printf("\nComparisons: %d", contFiftyMostRepeatedAVL[j]);
        printf("\n----------------------------------");
    }
    for(int j = 0;j<NUM;j++){
        printf("\nFiftyMostRepeated AVL %d (Sorted)",j+1);
        printf("\nElapsed time: %lld,%03lld millisseconds", timeFiftyMostRepeatedAVLSorted[j],(long long)(timeFiftyMostRepeatedAVLSortedDecimal[j] * 1000));
        printf("\nComparisons: %d", contFiftyMostRepeatedAVLSorted[j]);
        printf("\n----------------------------------");
    }


    return 0;
}

void insertDataDLL(DLLNode *head, int *data, int n, int *cont){
    *cont = 0;
    for(int i = 1; i < n; i++){
        insertDLLNode(head, data[i], cont);
    }
}

AVLNode* insertDataAVL(AVLNode *root, int *data, int n, int *cont){
    int ok;
    *cont = 0;
    
    for(int i = 1; i < n; i++){
        root = insertAVLNode(root, data[i], &ok, cont);
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
