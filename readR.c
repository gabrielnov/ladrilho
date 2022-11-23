//ALEX SE YOON KOO 32129319
//GABRIEL DE CARVALHO NOVAES 31897282
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read.h"

struct Movimento* readR(int *size, char caminho[]){
    int line = 1, num;
    char ch[5];
    char string[100];
    FILE* file;

    //abre o arquivo input.txt
    file = fopen("assets/input.txt", "r");
    //pega o tamanho da matriz
    fscanf(file, "%d", size);

    //ignoramos as primeiras linhas até passar do tamanho da matriz
    while (fgets(string, 100, file) != NULL){
        if (line > *size){
            fscanf(file, "%d", size);
            break;
        }
        line++;
    }

    //alocacao dinamica para uma lista de struct
    struct Movimento *movimento = (struct Movimento*) malloc(*size * sizeof(struct Movimento));
    
    //lemos linha por linha e preenchemos o vetor de struct
    for(int i = 0; i < *size; i++){
        fscanf(file, "%d %s", &movimento[i].num, &movimento[i].direction);
    }

    return movimento;
}