#include <stdio.h>
#include <math.h>
#include <string.h>

int binToDecConvert(long long n) {
  int dec = 0, i = 0, rem;

  while (n!=0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
  }

  return dec;
}

void decimalToBinary(int num) {   
    if (num == 0) {
        printf("0");
        return;
    }
   
   int binaryNum[32];
   int i=0;
   
   for ( ;num > 0; ){
      binaryNum[i++] = num % 2;
      num /= 2;
   }
   for (int j = i-1; j >= 0; j--){
      printf("%d", binaryNum[j]);
   }
   printf("\n");
}


int hexToDecConvert(char *hex) {
    int p = 0;
    int dec = 0;
    int r, i;

    for(i = strlen(hex) - 1 ; i >= 0 ; --i){
        if(hex[i]>='0'&&hex[i]<='9'){
            r = hex[i] - '0';
        }
        else{
            r = hex[i] - 'A' + 10;
        }
        dec = dec + r * pow(16 , p);
        ++p;
    }
    return dec;
}

void decToHexConvert(long dec){
    long quotient, remainder;
    int i, j=0;
    char hex[100];

    quotient = dec;

    while(quotient !=0)
    {
        remainder = dec % 16;
        if(remainder < 10)
            hex[j++] = 48 + remainder;
        else
            hex[j++]=55 + remainder;
        quotient = quotient / 16;

    }

    for(i=j; i>=0; i--){
        printf("%c",hex[i]);
    }
    printf("\n");

}

int main(){

    printf("\n%ld",binToDecConvert(11011));
    printf("\n%ld",binToDecConvert(10010100));
    printf("\n%ld",binToDecConvert(11001011010101));

    printf("\n\n");

    decimalToBinary(37);
    decimalToBinary(241);
    decimalToBinary(2487);

    printf("\n%ld",hexToDecConvert("6E2"));
    printf("\n%ld",hexToDecConvert("ED33"));
    printf("\n%ld",hexToDecConvert("123456"));

    printf("\n\n");

    decToHexConvert(243);
    decToHexConvert(2483);
    decToHexConvert(4612);

}