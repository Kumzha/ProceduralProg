#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int saveCount = 0;
int loadCount = 0;

void saveToFile(int* arr, int size, char* fileName){
    FILE* f = fopen(fileName, "w");
    	if (!f)
	{
		printf ("\nError opening data file!\n");
        exit(1);
	}
    
    int i = 0;

    fprintf(f, "\n%i\n", (size+1));

    while(i<=size){
        fprintf(f, "\n%i", *(arr+i));
        i++;
    }
    saveCount++;
    fclose(f);
}

int* loadFromFile(char* fileName){
    int i, size;
    int* p;
    FILE* f = fopen(fileName, "r");

    if (!f){
		printf ("\nError opening data file!\n");
        exit(1);
    }

    fscanf(f, "%i", &size);


    p = (int*)malloc((size+1) * sizeof(int));
    
    for(int j = 0; j<=size; j++){
            fscanf(f, "%i", &i);
            p[j]=i;
    }
    loadCount++;
    return p;
}

int main(){}