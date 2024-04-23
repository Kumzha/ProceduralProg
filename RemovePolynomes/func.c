#include "ND3F.h"


int isPalindrome1(char *str, int start, int length) {
    int i, j;
    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[start + i] != str[start + j]) {
            return 0;
        }
    }
    return 1;
}
//Funkcija pasalinanti palindromus
void removePalindrome(char *inputFileName, char *outputFileName) {
    long int fileSize;
    char *buffer;
    char *result;

    //Atidaro input file
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Klaida atidarant duomenu faila\n");
        return;
    }

    //Atidaro output file
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Klaida atidarant rezultato faila\n");
        fclose(inputFile);
        return;
    }

    //Nustato input file size
    fseek(inputFile, 0, SEEK_END);
    fileSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    //Atminties alokacija buferiui[fileSize]
    buffer = (char*)malloc((fileSize + 1)*sizeof(char));

    if (!buffer) {
        fclose(inputFile);
        printf("\nKlaida su malloc");
        return;
    }

    //Nuskaito inputfile i bufferi
    fread(buffer, 1, fileSize, inputFile);

    //Buferio gale string terminatoriu uzrasome
    buffer[fileSize-1] = '\0';

    //Uzdaromas inputfile
    fclose(inputFile);


    int wordStart = 0;
    int wordLength = 0;

    int numLines = 0;

    //Ciklas einantis, per bufferi, 
    for (int i = 0; i <= fileSize; i++) {
        //If ivykdomas jei pasiektas tarpas, failo pabaiga arba nauja eilute
        if (buffer[i] == ' '||i == fileSize || buffer[i]=='\n') {
            wordStart = i - wordLength;
            if (!isPalindrome1(buffer, wordStart, wordLength)) {
                for (int j = 0; j < wordLength; j++) {
                    fputc(buffer[wordStart + j], outputFile);
                    ;
                }
            }
            //Jei bufferi tarpas arba nauja eilute, tai i output irgi printinamas tarpas arba nauja elute
            if(buffer[i] == ' '){
            fputc(' ', outputFile);
            }
            if(buffer[i]=='\n'){
                fputc('\n', outputFile);
            }
            wordLength = 0;
        } else {
            wordLength++;
        }
    }
    //Atlaisvinamas bufferis ir uzdaromas outputfile
    free(buffer);
    fclose(outputFile);

    return;
}

int openFile(char fileName[]) {
    int open = 0;

    do {
        printf("\nFailo pavadinimas: ");
        scanf("%s", fileName);

        FILE *file = fopen(fileName, "r");

        if (file == NULL) {
            printf("\nTokio failo aplankale rasti nepavyko.");
        } else {
            printf("\nIvestis sekminga.");
            fclose(file);

            open = 1;
        }
    } while (open == 0);

    return open;
}
