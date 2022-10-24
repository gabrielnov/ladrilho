#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "read.h"

struct Movimento{
    int num;
    char direction[5];
};

struct Movimento* readR(){
    int line = 1, size, num;
    char ch[5];
    FILE* file;

    file = fopen("assets/input.txt", "r");
    fscanf(file, "%d", &size);

    char string[100];
    while (fgets(string, 100, file) != NULL){
        if (line > size){
            fscanf(file, "%d", &size);
            printf("%d\n", size);
            break;
        }
        line++;
    }
 
    struct Movimento *movimento = (struct Movimento*) malloc(size * sizeof(struct Movimento));
    
    for(int i = 0; i < size; i++){
        fscanf(file, "%d", &movimento[i].num);
        fscanf(file, "%s", &movimento[i].direction);
        printf("%d ", movimento[i].num);
        printf("%s \n", movimento[i].direction);
    }

    // for (int i = 0; i < size; i++){
    //     for (int j = 0; j < size; j++)
    //         printf("%c ", matrix[i][j]);
    //     printf("\n");           
    // } 

    return movimento;
}