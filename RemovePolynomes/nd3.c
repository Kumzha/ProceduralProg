#include "ND3F.h"


int main() {
    char input[100];
    char output[100];
    FILE *inputFile, *outputFile;

    printf("\nIveskite duomenu faila. ");
    openFile(input);
    printf("\nIveskite rezultato faila. ");
    openFile(output);

    removePalindrome(input, output);
}