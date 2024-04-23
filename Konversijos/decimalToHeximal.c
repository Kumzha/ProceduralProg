#include <stdio.h>

int decToHexConvert(){
    long dec, quotient, remainder;
    int i, j=0;
    char hex[100];

    printf("Enter decimal number: ");
    scanf("%ld", &dec);

    quotient = dec;

    while(quotient !=0)
    {
        remainder = quotient % 16;
        if(remainder < 10)
            hex[j++] = 48 + remainder;
        else
            hex[j++]=55 + remainder;
        quotient = quotient / 16;

    }

    // for(i=j; i>=0; i--)
    //     printf("%c",hex[i]);

    return hex;

}