//ALEX SE YOON KOO 32129319
//GABRIEL DE CARVALHO NOVAES 31897282
struct Movimento{
    int num;
    char direction[5];
};

int** readMatrix(int *size, char caminho[]);
struct Movimento* readR(int *size, char caminho[]);