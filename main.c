#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"

void printMatrix(int **matrix, int size){
    printf("######################\n");
    for (int a = 0; a < size; a++){
        for (int b = 0; b < size; b++)
            printf("%d ", matrix[a][b]);
        printf("\n");           
    }
    printf("######################\n");
}

void encontraPos(int *posi, int *posj, int **matrix, int movimento, int size){
    int flag = 0;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
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

int validaPos(int i, int j, char *move, int size, int **matrix){
    if(strcmp(move, "d") == 0){ //coluna - 1
        if(j >= size-1 || matrix[i][j+1] != 0) {
            return 0;
        }
    } else if (strcmp(move, "e") == 0){ //coluna + 1
        if(j <= 0 || matrix[i][j-1] != 0){
            return 0;
        }
    } else if (strcmp(move, "b") == 0){ //linha - 1
        if(i >= size-1 || matrix[i+1][j] != 0){
            return 0;
        }
    } else if (strcmp(move, "c") == 0){//linha + 1
        if(i <= 0 || matrix[i-1][j] != 0){
            return 0;
        }
    } return 1;
}

void moveNum(int *posi, int*posj, int **matrix, char *move){
    int aux;
    aux = matrix[*posi][*posj];

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

    int **matrix, i , j, size, flag = 0, continua;
    struct Movimento *movimento;
    matrix = readMatrix(&size);

    movimento = readR(&size);

    //mover os ladrilhos de acordo com o moveset
    for(int x = 0; x < size; x++){
        printf("digite 1 para continuar e 0 para terminar: ");
        scanf("%d", &continua);
        if (continua == 1){
            flag = 0;
            encontraPos(&i, &j, matrix, movimento[x].num, size);
            printf("posicao i e j: %d %d\n", i, j);
            printf("movimento: %d %s \n", movimento[x].num, movimento[x].direction);

            flag = validaPos(i, j, movimento[x].direction, size, matrix);

            if(flag == 1){
                moveNum(&i, &j, matrix, movimento[x].direction);
            } else {
                printf("movimento invalido\n");
                break;
            }
            printMatrix(matrix, size);
        } else {
            break;
        }

    }

    for (int i = 0; i < size; i++){
        free(matrix[i]);
    }

    free(matrix);
    return 0;
}