#include "file.h"
#include <time.h>

void fillArray(int size, int* arr){
    int count = 0;
    srand(time(NULL));
    while(count<=size){
        arr[count]=  1 + rand() % (1000 + 1 - 1);
        count++;
    }
}
void printArray(int size, int* arr){
    int count = 0;
    printf("\nPRINTED ARRAY:\n");
    while(count<=size){
        printf("\narr[%i]=%i",count, arr[count]);
        count++;
    }
}
void compareArray(int* arr1, int size1, int* arr2, int size2){
    if(size1!=size2){
        printf("\nsomething's wrong!\n");
    }else{
        for(int i = 0; i<=size1; i++){
            if(arr1[i]==arr2[i]){
                continue;
            }else{
                printf("\nNOT GOOD...\n");
                break;
            }
        }
        printf("\n\nALL GOOD MY MAN!\n");
    }
}
void nullCount(int* x, int* y){
    *x = 0;
    *y = 0;
}

// as PRIOE JUROS

int main(){
    int* ptrarr;
    int* ptrarr2;
    int* ptrarr3;

    ptrarr =  (int*)malloc(11 * sizeof(int));
    ptrarr2 = (int*)malloc(11 * sizeof(int));
    ptrarr3 = (int*)malloc(11 * sizeof(int));

    if (ptrarr == NULL|| ptrarr2 == NULL|| ptrarr3 == NULL) {
        printf("Memory not allocated.\n");
        exit(0); 
    }

    int count = 0;

    fillArray(10, ptrarr);
    printArray(10, ptrarr);
    saveToFile(ptrarr, 10, "inout.txt");

    printf("\n\nSECOND ARRAY TAKEN FROM THE FILE:\n");

    ptrarr2 = loadFromFile("inout.txt");
    while(count<=10){
        printf("\narr2[%i] = %i", count, *(ptrarr2+count));
        count++;
    }

    compareArray(ptrarr, 10, ptrarr2, 10);

    fillArray(10, ptrarr);
    fillArray(10, ptrarr2);
    fillArray(10, ptrarr3);

    saveToFile(ptrarr, 10, "inout.txt");
    saveToFile(ptrarr3, 10, "inout.txt");
    ptrarr = loadFromFile("inout.txt");
    saveToFile(ptrarr2, 10, "inout2.txt");
    ptrarr3 = loadFromFile("inout2.txt");
    ptrarr2 = loadFromFile("inout.txt");

    printf("\nSave count: %i\nLoad count: %i\n", saveCount, loadCount);

    if(saveCount==loadCount){
        printf("\nALL GOOD TWICE MAN!\n");
    }
}

//3 14
//2 18
//1 18