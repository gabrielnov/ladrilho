#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"

struct Movimento{
    int num;
    char direction[5];
};

void printMatrix(int **matrix, int row, int column){
    printf("######################\n");
    for (int a = 0; a < row; a++){
        for (int b = 0; b < column; b++)
            printf("%d ", matrix[a][b]);
        printf("\n");           
    }
    printf("######################\n");
}

int main(){

    int **matrix, i , j, size, row, column, flag = 0, aux;
    struct Movimento *movimento;
    matrix = readMatrix(&size);
    row = size;
    column = size;
    movimento = readR(&size);
    //procurar o local do 0 e retornar as posicoes
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++){
            if (matrix[i][j] == 0){
                printf("%d\n", matrix[i][j]);
                flag = 1;
                break;
            }
        }
        if (flag == 1){
            break;
        }
    }

    printf("i e j: %d %d\n", i, j);
    //mover os ladrilhos de acordo com o moveset
    for(int x = 0; x < size; x++){
        printf("movimento: %d ", movimento[x].num);
        printf("%s \n", movimento[x].direction);
        if(strcmp(movimento[x].direction, "d") == 0){ //coluna + 1
            //verificamos se o movimento[x].num é correspondente
            aux = matrix[i][j];
            matrix[i][j] = matrix[i][j-1];
            matrix[i][j-1] = aux;
            j--;
        } else if (strcmp(movimento[x].direction, "e") == 0){ //coluna -1
            aux = matrix[i][j];
            matrix[i][j] = matrix[i][j+1];
            matrix[i][j+1] = aux;
            j++;
        } else if (strcmp(movimento[x].direction, "b") == 0){ //linha - 1
            aux = matrix[i][j];
            matrix[i][j] = matrix[i-1][j];
            matrix[i-1][j] = aux;
            i--;
        } else if (strcmp(movimento[x].direction, "c") == 0){//linha - 1
            aux = matrix[i][j];
            matrix[i][j] = matrix[i+1][j];
            matrix[i+1][j] = aux;
            i++;
        }
        printMatrix(matrix, row, column);
    }

    for (int i = 0; i < column; i++){
        free(matrix[i]);
    }

    free(matrix);
    return 0;
}