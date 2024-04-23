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

void removePalindrome(char *inputFileName, char *outputFileName) {
    long int file_size;
    char *buffer;
    char *result;

    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Klaida atidarant duomenu faila\n");
        return;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Klaida atidarant rezultato faila\n");
        fclose(inputFile);
        return;
    }

    fseek(inputFile, 0, SEEK_END);
    file_size = ftell(inputFile);

    buffer = (char*)malloc((file_size + 1)*sizeof(char));

    if (!buffer) {
        fclose(inputFile);
        printf("\nKlaida su malloc");
        return;
    }

    fseek(inputFile, 0, SEEK_SET);
    
    if (fread(buffer, 1, file_size, inputFile) != file_size) {
        fclose(inputFile);
        free(buffer);
        printf("\nKlaida skaitant faila");
        return;
    }

    buffer[file_size] = '\0';
    fclose(inputFile);

    int wordStart = 0;
    int wordLength = 0;

    for (int i = 0; i <= file_size; i++) {
        // printf("\nWS: %d\tI: %d\tWL: %d", wordStart, i, wordLength);
        if (buffer[i] == ' ') {
            wordStart = i - wordLength;
            if (!isPalindrome1(buffer, wordStart, wordLength)) {
                for (int j = 0; j < wordLength; j++) {
                    fputc(buffer[wordStart + j], outputFile);
                    ;
                }
            }
            fputc(' ', outputFile);
            wordLength = 0;
        } else {
            wordLength++;
        }
    }

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
