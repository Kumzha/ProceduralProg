// Teorija

// https://www.hindawi.com/journals/jopti/2017/5650364/
// https://en.wikipedia.org/wiki/Mathematical_chess_problem
// https://en.wikipedia.org/wiki/Salem%E2%80%93Spencer_set


#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "funkcijos.c"

int main(){


    clock_t begin = clock();
    FILE *f = fopen("log.txt", "w");
    int size = 8;
    int numOfQueens = 5;

    if (size>8){
        fprintf(f, "Lentos dydis negali buti didesnis nei 8");
        return 0;
    }

    //naudojama tikrint be pabaigos array, 36
    int combSize = (int)pow(size, 2);

    //naudojama tikrint su pabaiga array, 37
    int combSizeEnd = ((int)pow(size,2)+1);

    // Alocuojame memory ( Array dydis (size*size)+1 simboliai, paskutinis simbolis zymimas 36 )
    int *combination = (int*)malloc(combSizeEnd*sizeof(int));

    //Uzpildo array nuliais
    for(int i = 0; i<combSize; i++){combination[i]=0;}

    // Paskutinis array simbolis yra 2, simbolizuoja pabaiga
    combination[combSize]=End;

    //Priskiria vietos lentai 
    int **board = (int**)malloc(size*sizeof(int*));
        for(int i = 0; i < size; i++){board[i]=(int*)malloc(size*sizeof(int));}

    //Užpildo lentą nuliais
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++){board[i][j] = Free;}
    }

    

    fprintf(f,"\n1 DALIS SALYGA");
    fprintf(f, "\n2 uzduotis 5 variantas, Dominykas Kumza,  2 grupe, 2 pogrupis.");
    fprintf(f, "\nSalyga: Sustatyti lentoje NxN (N=6,7,8) 5 valdoves, kad kiekviena langeli kirstu bent viena valdove. Rasti VISUS variantus.\n");

    fprintf(f,"\n2 DALIS DUOMENYS");
    fprintf(f,"\n1) Lentos dydis: %dX%d", size, size);
    fprintf(f,"\n2) Karalieniu skaicius: %d\n", numOfQueens);
    
    findCombinations(combination, combSize, numOfQueens, size, board, f);

    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\ntime spent: %fs", time_spent);

    free(combination);
    free(*board);
    fclose(f);
}
