
#include <stdio.h>

#include "IlgasInt.h"
#include "IlgasIntTest.h"


int main() {

    // Testavimas();

    IlgasInt* didelisInt1 = nIlgasIntIsString("1000");
    IlgasInt* didelisInt2 = nIlgasIntIsString("3");
    IlgasInt* didelisInt3 = nIlgasIntIsString("0");
    IlgasInt* didelisInt4 = nIlgasIntIsString("0");

    IlgasInt_divide(didelisInt1, didelisInt2, didelisInt3, didelisInt4);
        printf("\n");
    spausdintiIlgasInt(didelisInt1);
       printf("\n");
        spausdintiIlgasInt(didelisInt2);
       printf("\n");
        spausdintiIlgasInt(didelisInt3);
       printf("\n");
        spausdintiIlgasInt(didelisInt4);
       printf("\n");


    return 0;
}



