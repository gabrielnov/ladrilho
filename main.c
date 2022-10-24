#include <stdio.h>
#include "read.h"

struct Movimento{
    int num;
    char direction[5];
};

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
                printf("%d", matrix[i][j]);
                flag = 1;
                break;
            }
        }
        if (flag == 1){
            break;
        }
    }
    printf("i e j: %d %d", i, j);
    //mover os ladrilhos de acordo com o moveset
    for(int i = 0; i < size; i++){
        printf("%d ", movimento[i].num);
        printf("%s \n", movimento[i].direction);
        if(movimento[i].direction == 'd'){
            
        }
    }

    return 0;
}