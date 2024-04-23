#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "IlgasInt.h"
#include "IlgasIntTest.h"


void IlgasIntTest_print() {
    IlgasInt* skaicius1 = nIlgasInt(10000);
    assert(skaicius1);
    assert(atimtisIlgasIntInt(skaicius1, 9900));

    assert(6==skaicius1->priskirtaSkaiciu);
    assert(3==skaicius1->skaiciuKiekis);

    printf("Isvedimo Testas sekmignas!\n");
}
   

void testCreation(){
    IlgasInt *skaicius1 = nIlgasInt(0);
    assert(skaicius1);
    freeIlgasInt(skaicius1);
    IlgasInt *skaicius2 = nIlgasIntIsString("456789465312314567");
    assert(skaicius2);
    freeIlgasInt(skaicius2);
    printf("Sukurimo Testas sekmignas!\n");
} 

void teststrlenIlgasInt(){
    IlgasInt *skaicius1 = nIlgasIntIsString("456789465312314567");
    assert(skaicius1);
    assert(18 == strlenIlgasInt(skaicius1));
    freeIlgasInt(skaicius1);
    IlgasInt *skaicius2 = nIlgasInt(0);
    assert(skaicius2);
    assert(1 == strlenIlgasInt(skaicius2));
    freeIlgasInt(skaicius2);
    printf("Sukurimo Testas sekmignas!\n");
}

void testIlgasIntIString(){
    IlgasInt *skaicius1 = nIlgasIntIsString("456789465312314567");
    char *str = IlgasIntNString(skaicius1);
    assert(!strcmp(str, "456789465312314567"));
    free(str);
    freeIlgasInt(skaicius1);

    IlgasInt *skaicius2 = nIlgasInt(12);
    str = IlgasIntNString(skaicius2);
    assert(!strcmp(str, "12"));
    free(str);
    freeIlgasInt(skaicius2);
    printf("Convertavimo is Int i String Testas Sekmingas!\n");
}

void testCompareIlgasInt(){
    IlgasInt *skaicius1 = nIlgasIntIsString("456789465312314567");
    IlgasInt *skaicius2 = nIlgasIntIsString("456789465312314566");
    assert(palyginimasIlgasInt(skaicius1, skaicius2) == 1);

    skaicius2 = nIlgasIntIsString("456789465312314568");
    assert(palyginimasIlgasInt(skaicius1, skaicius2) == -1);

    skaicius2 = nIlgasIntIsString("456789465312314567");
    assert(palyginimasIlgasInt(skaicius1, skaicius2) == 0);

    freeIlgasInt(skaicius1);
    freeIlgasInt(skaicius2);
    
    printf("Palyginimo Testas Sekmingas!\n");
}

void testSudetis(){
    IlgasInt *skaicius1 = nIlgasIntIsString("456789465312314567");
    int skaicius2 = 1;
    sudetisIlgasIntIrInt(skaicius1, skaicius2);

    char *str = IlgasIntNString(skaicius1);
    assert(!strcmp(str, "456789465312314568"));

    free(str);
    freeIlgasInt(skaicius1);

    IlgasInt *number3 = nIlgasIntIsString("456789465312314567");
    IlgasInt *number4 = nIlgasIntIsString("10003");
    sudetisIlgasInt(number3, number4);

    char *str2 = IlgasIntNString(number3);
    assert(!strcmp(str2, "456789465312324570"));

    free(str2);
    freeIlgasInt(number3);
    freeIlgasInt(number4);
    printf("Sudeties Testas Sekmingas!\n");
}

void testAtimtis(){
    IlgasInt *skaicius1 = nIlgasIntIsString("456789465312314567");
    IlgasInt *skaicius2 = nIlgasIntIsString("10003");
    atimtisIlgasInt(skaicius1, skaicius2);

    char *str = IlgasIntNString(skaicius1);
    assert(!strcmp(str, "456789465312304564"));

    free(str);
    freeIlgasInt(skaicius1);
    freeIlgasInt(skaicius2);
    printf("Atimties Testas Sekmingas!\n");
}

void testIlgasIntSkaiciuPatikra(){
    IlgasInt *skaicius1 = nIlgasInt(123);
    assert(skaicius1->skaiciuKiekis == 3);
    assert(skaicius1->priskirtaSkaiciu >= 3);

    IlgasIntSkaiciuPatikra(skaicius1, 5);
    assert(skaicius1->skaiciuKiekis == 3);
    assert(skaicius1->priskirtaSkaiciu >= 5);

    freeIlgasInt(skaicius1);
    printf("Skaiciu patikrinimo Testas Sekmingas!\n");
}

void testCompareIlgasIntDigits(){
    IlgasInt *skaicius1 = nIlgasInt(123);
    IlgasInt *skaicius2 = nIlgasInt(456);

    assert(palyginimasIlgasIntSkaiciai(skaicius1, skaicius2) == -1);

    skaicius2 = nIlgasInt(123);
    assert(palyginimasIlgasIntSkaiciai(skaicius1, skaicius2) == 0);

    skaicius2 = nIlgasInt(12);
    assert(palyginimasIlgasIntSkaiciai(skaicius1, skaicius2) == 1);

    freeIlgasInt(skaicius1);
    freeIlgasInt(skaicius2);
    printf("Palyginimo individualiu skaiciu Testas Sekmingas!\n");
}

void Testavimas(){

    printf("Pradedamas IlgasInt testas...\n\n");

    IlgasIntTest_print();

    testCreation();
    teststrlenIlgasInt();
    testIlgasIntIString();
    testCompareIlgasInt();
    testSudetis();
    testAtimtis();
    testIlgasIntSkaiciuPatikra();
    testCompareIlgasIntDigits();

    IlgasIntTest_print();

     printf("\n\nTestavimas Baigtas.");
}