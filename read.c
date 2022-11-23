//ALEX SE YOON KOO 32129319
//GABRIEL DE CARVALHO NOVAES 31897282
#include <stdio.h>
#include <stdlib.h>
#include "read.h"

int** readMatrix(int *size, char caminho[]){
    int i, j, value;
    FILE* file;
    
    //abre o input.txt
    file = fopen(caminho, "r");
    //le a primeira linha do arquivo q eh o tamanho da matriz
    fscanf(file, "%d", size);

    //faz a alocacao dinamica de uma matriz
    int **matrix = (int**) malloc(*size * sizeof(int*));
 
    for (int i = 0; i < *size; i++)
        matrix[i] = (int*) malloc(*size * sizeof(int));


    //le linha por linha e vai preenchendo a matriz
    for (int i = 0; i < *size; i++){
        for (int j = 0; j < *size; j++){
            fscanf(file, "%d", &value);        
            matrix[i][j] = value;
        }
    }
    
    return matrix;
}