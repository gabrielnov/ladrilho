#include <stdio.h>
#include <stdlib.h>
#include "read.h"

int** readMatrix(int *size){
    int i, j, value;

    FILE* file;

    file = fopen("assets/input.txt", "r");
    
    fscanf(file, "%d", size);
    
    int **matrix = (int**) malloc(*size * sizeof(int*));
 
    for (int i = 0; i < *size; i++)
        matrix[i] = (int*) malloc(*size * sizeof(int));

    for (int i = 0; i < *size; i++){
        for (int j = 0; j < *size; j++){
            fscanf(file, "%d", &value);        
            matrix[i][j] = value;
        }
    }

    // for (int i = 0; i < *size; i++){
    //     for (int j = 0; j < *size; j++)
    //         printf("%d ", matrix[i][j]);
    //     printf("\n");           
    // }  
    
    return matrix;
}