#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void generateData(int n1, int *vetor);

int main(){

    int n1 = 5000, n2 = 10000, n3 = 100000;
    
    int dados1 [n1];
    int dados2 [n2];
    int dados3 [n3];
        
    //PARA O CONJUNTO DE DADOS 1
    generateData(n1, dados1);
    //PARA O CONJUNTO DE DADOS 2
    generateData(n2, dados2);
    //PARA O CONJUNTO DE DADOS 3
    generateData(n3, dados3); 


    // CRIA DLL 

    // INSERE NA DLL 

    // BUSCA MAIOR NA DLL 

    // BUSCA MENOR NA DLL 

    // BUSCA VALOR MÉDIO NA DLL 

    // 10 MAIS REPETIDO NA DLL 

    // 50 MAIS REPETIDO NA DLL 

    // CRIA AVL
    
    // INSERE NA AVL

    // BUSCA MAIOR NA AVL 

    // BUSCA MENOR NA AVL 

    // BUSCA VALOR MÉDIO NA AVL 

    // 10 MAIS REPETIDO NA AVL 

    // 50 MAIS REPETIDO NA AVL

    // VERIFICAR TEMPO DE CADA USANDO TIME.H

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

int formatTime(int tempo){
    // FORMATA O TEMPO PARA SER EXIBIDO EM MINUTOS/SEGUNDOS (veremos)
}

void compareTime(int tempo1, int tempo2){
    // COMPARA OS TEMPOS DA DLL E DA AVL
}

void compareComparisons(int compara1, int compara2){
    // COMPARA O NÚMERO DE COMPARAÇÕES DA DLL E DA AVL
}
