#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

struct Movimento{
    int num;
    char direction[5];
};

struct Movimento* readR(int *size){
    int line = 1, num;
    char ch[5];
    FILE* file;

    file = fopen("assets/input.txt", "r");
    fscanf(file, "%d", size);

    char string[100];
    while (fgets(string, 100, file) != NULL){
        if (line > *size){
            fscanf(file, "%d", size);
            break;
        }
        line++;
    }

    printf("tamanho da lista: %d\n", *size);
    struct Movimento *movimento = (struct Movimento*) malloc(*size * sizeof(struct Movimento));
    
    for(int i = 0; i < *size; i++){
        fscanf(file, "%d %s", &movimento[i].num, &movimento[i].direction);
        printf("%d ", movimento[i].num);
        printf("%s \n", movimento[i].direction);
    }

    // for(int i = 0; i < size; i++){
    //     printf("%d ", movimento[i].num);
    //     printf("%s\n", movimento[i].direction);
    // }
    return movimento;
}