#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void geradados(int n1, int *vetor);

int main(){

    int n1 = 5000, n2 = 10000, n3 = 100000;
    
    int dados1 [n1];
    int dados2 [n2];
    int dados3 [n3];
        
    //PARA O CONJUNTO DE DADOS 1
    geraDados(n1, dados1);
    //PARA O CONJUNTO DE DADOS 2
    geraDados(n2, dados2);
    //PARA O CONJUNTO DE DADOS 3
    geraDados(n3, dados3); 

    return 0;
}

void geraDados (int num, int *vetor){
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
