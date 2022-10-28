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

void encontraPos(int *posi, int *posj, int **matrix, int movimento, int row, int column){
    int flag = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            if(movimento == matrix[i][j]){
                *posi = i;
                *posj = j;
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            break;
        }
    }
}

int validaPos(int i, int j, char *move, int row, int column, int **matrix){
    if(strcmp(move, "d") == 0){ //coluna - 1
        if(j >= column-1 || matrix[i][j+1] != 0) {
            return 0;
        }
    } else if (strcmp(move, "e") == 0){ //coluna + 1
        if(j <= 0 || matrix[i][j-1] != 0){
            return 0;
        }
    } else if (strcmp(move, "b") == 0){ //linha - 1
        if(i >= row-1 || matrix[i+1][j] != 0){
            return 0;
        }
    } else if (strcmp(move, "c") == 0){//linha + 1
        if(i <= 0 || matrix[i-1][j] != 0){
            return 0;
        }
    } return 1;
}

int validaZero(int i, int j, int **matrix, int row, int column){
    if(matrix[i+1][j] != 0 || matrix[i-1][j] != 0 || matrix[i][j+1] != 0 || matrix[i][j-1] != 0 ){
        return 0;
    } else {
        return 1;
    }
}

void moveNum(int *posi, int*posj, int **matrix, char *move){
    int aux;
    aux = matrix[*posi][*posj];
    printf("o valor que quremos mudar eh %d", aux);
    if(strcmp(move, "d") == 0){ //coluna + 1
        matrix[*posi][*posj] = matrix[*posi][*posj+1];
        matrix[*posi][*posj+1] = aux;
    } else if (strcmp(move, "e") == 0){ //coluna -1
        matrix[*posi][*posj] = matrix[*posi][*posj-1];
        matrix[*posi][*posj-1] = aux;
    } else if (strcmp(move, "b") == 0){ //linha - 1
        matrix[*posi][*posj] = matrix[*posi+1][*posj];
        matrix[*posi+1][*posj] = aux;
    } else if (strcmp(move, "c") == 0){//linha - 1
        matrix[*posi][*posj] = matrix[*posi-1][*posj];
        matrix[*posi-1][*posj] = aux;
    }
}

int main(){

    int **matrix, i , j, size, row, column, flag = 0;
    struct Movimento *movimento;
    matrix = readMatrix(&size);
    row = size;
    column = size;
    movimento = readR(&size);

    //mover os ladrilhos de acordo com o moveset
    for(int x = 0; x < size; x++){
        flag = 0;
        encontraPos(&i, &j, matrix, movimento[x].num, row, column);
        printf("i e j: %d %d\n", i, j);
        printf("movimento: %d ", movimento[x].num);
        printf("%s \n", movimento[x].direction);
        if(strcmp(movimento[x].direction, "d") == 0){ //coluna - 1
            flag = validaPos(i, j, movimento[x].direction, row, column, matrix);
        } else if (strcmp(movimento[x].direction, "e") == 0){ //coluna + 1
            flag = validaPos(i, j, movimento[x].direction, row, column, matrix);
        } else if (strcmp(movimento[x].direction, "b") == 0){ //linha - 1
            flag = validaPos(i, j, movimento[x].direction, row, column, matrix);
        } else if (strcmp(movimento[x].direction, "c") == 0){//linha + 1
            flag = validaPos(i, j, movimento[x].direction, row, column, matrix);
        }
        flag = validaZero(i, j, matrix, row, column);
        if(flag == 1){
            moveNum(&i, &j, matrix, movimento[x].direction);
        } else {
            printf("movimento invalido\n");
            break;
        }
        printMatrix(matrix, row, column);
    }

    for (int i = 0; i < column; i++){
        free(matrix[i]);
    }

    free(matrix);
    return 0;
}