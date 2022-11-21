//ALEX SE YOON KOO 32129319
//GABRIEL DE CARVALHO NOVAES 31897282
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "read.h"

bool ordenado(int **matrix, int size){
    int current = matrix[0][0];
    for(int i = 1; i < size; i++){
        for(int j = 1; j < size; j++){
            if(current > matrix[i][j]){
                return false;
            } else {
                current = matrix[i][j];
            }
        }
    }
    return true;
}

void printMatrix(int **matrix, int size){
    printf("######################\n");
    for(int a = 0; a < size; a++){
        printf("----------------------\n");
        for(int b = 0; b < size; b++){
            printf("|");
            printf(" %d ", matrix[a][b]);
        }
        printf("|\n");           
    }
    printf("----------------------\n");
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


int main(int argc, char** argv){

    int **matrix, i , j, size, flag = 0, continua, tamanho;
    struct Movimento *movimento;
    if (argv[1] == NULL){
        printf("colocar o caminho do arquivo input.txt");
        return 0;
    }
    matrix = readMatrix(&size, argv[1]);
    printf("--- matriz inicial ---\n");
    printMatrix(matrix, size);
    tamanho = size;
    movimento = readR(&size);

    //mover os ladrilhos de acordo com o moveset
    for(int x = 0; x < size; x++){
        printf("\ndigite 1 para continuar ou qualquer outro numero para terminar: ");
        scanf("%d", &continua);
        if (continua == 1){
            flag = 0;
            encontraPos(&i, &j, matrix, movimento[x].num, tamanho);
            printf("----------------------\n");
            printf("posicao i e j do ZERO: %d %d\n", i, j);
            printf("--- movimento: %d %s ---\n", movimento[x].num, movimento[x].direction);

            flag = validaPos(i, j, movimento[x].direction, tamanho, matrix);

            if(flag == 1){
                moveNum(&i, &j, matrix, movimento[x].direction);
            } else {
                printf("movimento invalido\n");
                break;
            }
            if(ordenado(matrix, size) == true){
                printf("---matriz ordenada!!---\n");
            } else {
                printf("---matrix nao ordenada!!---\n");
            }

            printMatrix(matrix, tamanho);
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