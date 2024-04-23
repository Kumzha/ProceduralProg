#include <assert.h>
#include <math.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "IlgasInt.h"

#define MAX(x, y) ((x) > (y) ? (x) : (y))


#define mallocSkaiciai(skaiciuKiekis) malloc((skaiciuKiekis) * sizeof(unsigned char))
#define okaySkaiciai(skaiciai,skaiciuKiekis) 1
#define freeSkaiciai(skaiciai,skaiciuKiekis) free(skaiciai)

void atspausdintiMenu()
{
    printf("------------------------------------------\n");
    printf("1. Ivesti pirma ilga sveika skaiciu\n");
    printf("2. Ivesti antra ilga sveika skaiciu\n");
    printf("3. Pavaizduoti skaicius ekrane\n");
    printf("4. Sudeti skaicius\n");
    printf("5. Atimti skaicius\n");
    printf("6. Pakeisti pirma skaiciu\n");
    printf("7. Pakeisti antra skaiciu\n");
    printf("8. Skaiciu daugyba\n");
    printf("9. Skaiciu dalyba\n");
    printf("10. Uzdaryti programa\n");
    printf("------------------------------------------\n");
    printf("Irasykite savo pasirinkima: ");
    return;
}

void gautiNaudotojoSkaiciu(int *naudotIvest)
{
    atspausdintiMenu();
    while (scanf("%d", naudotIvest) != 1 || getchar() != '\n')
    {
        while (getchar() != '\n')
            ;
        printf("Tokio pasirinkimo nera! Rinkites is naujo.\n");
        atspausdintiMenu();
    }
    if (*naudotIvest < 1 || *naudotIvest > 10)
    {
        printf("Tokio pasirinkimo nera! Rinkites is naujo.\n");
        gautiNaudotojoSkaiciu(naudotIvest);
    }
}

void gautiNaudotojoPasirinkima(char *naudotojoPasirinkimas)
{
    printf("Ar norite istrinti sena skaiciu? y/n?");
    while (scanf("%1c", naudotojoPasirinkimas) != 1 || getchar() != '\n')
    {
        while (getchar() != '\n')
            ;
        printf("Neteisingai ivestas atsakymas! Iveskite y arba n raide.\n");
        printf("Ar tikrai norite istrinti skaiciu? y/n? ");
    }
    if (*naudotojoPasirinkimas != 'y' && *naudotojoPasirinkimas != 'n')
    {
        printf("Neteisingai ivestas atsakymas! Iveskite y arba n raide.\n");
        gautiNaudotojoPasirinkima(naudotojoPasirinkimas);
    }
}




IlgasInt* nIlgasInt(int reiksme) {

    IlgasInt* didelisInt = malloc(sizeof(IlgasInt));
    if(!didelisInt) {
        return NULL;
    }
    unsigned int reiksme2;
    if(reiksme < 0) {
        didelisInt->arNeigiamas = 1;
        reiksme2 = -reiksme;
    } else {
        didelisInt->arNeigiamas = 0;
        reiksme2 = reiksme;
    }

    didelisInt->skaiciuKiekis = floor(log10(reiksme2)) + 1;

    if(didelisInt->skaiciuKiekis == 0) {
        didelisInt->skaiciuKiekis = 1;
    }

    didelisInt->priskirtaSkaiciu = didelisInt->skaiciuKiekis;
    didelisInt->skaiciai = mallocSkaiciai(didelisInt->priskirtaSkaiciu);
    if(!didelisInt->skaiciai) {
        free(didelisInt);
        return NULL;
    }

    unsigned int count = didelisInt->skaiciuKiekis;
    unsigned char* skaiciai = didelisInt->skaiciai;
    while(count--) {
        (*skaiciai++) = reiksme2 % 10;
        reiksme2 /= 10;
    }

    return didelisInt;
}

IlgasInt* nIlgasIntIsString(const char* str) {
    BOOL arNeigiamas = (*str == '-');
    if(arNeigiamas) {
        str++;
    }

    unsigned int skaiciuKiekis = strlen( str );
    IlgasInt* didelisInt = malloc(sizeof(IlgasInt));
    if(!didelisInt){
        return NULL;
    }
    didelisInt->arNeigiamas = arNeigiamas;
    didelisInt->priskirtaSkaiciu = skaiciuKiekis;
    didelisInt->skaiciai = mallocSkaiciai(skaiciuKiekis);
    if(!didelisInt->skaiciai){
        free(didelisInt);
        return NULL;
    }
    const char* end = str + skaiciuKiekis - 1;
    unsigned char* skaiciai = didelisInt->skaiciai;
    while( end >= str ){
        unsigned char vienasSkaicius = *(end--);
        if(vienasSkaicius < '0' || vienasSkaicius > '9'){
            freeIlgasInt(didelisInt);
            errno = EINVAL;
            return NULL;
        }
        *skaiciai++ = vienasSkaicius - '0';
    }
    didelisInt->skaiciuKiekis = skaiciai - didelisInt->skaiciai;
    assert(okaySkaiciai(didelisInt->skaiciai, didelisInt->priskirtaSkaiciu));
    return didelisInt;
}

void freeIlgasInt(IlgasInt* skaicius1) {
    if(skaicius1) {
        freeSkaiciai(skaicius1->skaiciai, skaicius1->priskirtaSkaiciu);
        free(skaicius1);
    }
}

int palyginimasIlgasInt(const IlgasInt* a, const IlgasInt* b) {
    if(a->skaiciuKiekis > 0 || a->skaiciai[0] > 0 || b->skaiciuKiekis > 0 || b->skaiciai[0] > 0) {
        if (a->arNeigiamas && !b->arNeigiamas) {
            return -1;
        } else if (!a->arNeigiamas && b->arNeigiamas) {
            return 1;
        }
    }

    return a->arNeigiamas ? palyginimasIlgasIntSkaiciai(b, a) : palyginimasIlgasIntSkaiciai(a, b);
}


int palyginimasIlgasIntSkaiciai(const IlgasInt* a, const IlgasInt* b) {

    if(a->skaiciuKiekis > b->skaiciuKiekis) {
       return 1;
    } else if(a->skaiciuKiekis < b->skaiciuKiekis) {
       return -1;
    }

    unsigned int count = a->skaiciuKiekis;
    const unsigned char* pa = &a->skaiciai[count-1];
    const unsigned char* pb = &b->skaiciai[count-1];
    while(count--) {
        char da = *(pa--);
        char db = *(pb--);
        if(da > db) {
            return 1;
        } else if(da < db) {
            return -1;
        }
    }

    return 0;
}


BOOL sudetisIlgasInt(IlgasInt* skaicius1, const IlgasInt* skaicius2) {
    if(skaicius1->arNeigiamas == skaicius2->arNeigiamas) {

        if(!sudetisIlgasIntSkaiciai(skaicius1, skaicius2)) {
            return 0;
        }
    } else {

        unsigned int result_arNeigiamas = palyginimasIlgasIntSkaiciai(skaicius1, skaicius2) > 0 ?
                skaicius1->arNeigiamas : skaicius2->arNeigiamas;

        if(!atimtisIlgasIntSkaiciai(skaicius1, skaicius2)) {
            return 0;
        }
        skaicius1->arNeigiamas = result_arNeigiamas;
    }
    return 1;
}

BOOL sudetisIlgasIntIrInt(IlgasInt* skaicius1, const int skaicius2) {
    IlgasInt* skaicius1_skaicius2 = nIlgasInt(skaicius2);
    if(!skaicius1_skaicius2) {
        return 0;
    }
    BOOL result = sudetisIlgasInt(skaicius1, skaicius1_skaicius2);
    freeIlgasInt(skaicius1_skaicius2);
    return result;
}

BOOL sudetisIlgasIntSkaiciai(IlgasInt* skaicius1, const IlgasInt* skaicius2) {
    unsigned int skaiciaiReikalingi = MAX(skaicius1->skaiciuKiekis, skaicius2->skaiciuKiekis) + 1; 
    if(!IlgasIntSkaiciuPatikra(skaicius1, skaiciaiReikalingi)) {
        return 0;
    }

    int i;
    int carry = 0;

    for(i = 0; i < skaicius2->skaiciuKiekis || carry > 0; ++i) { 

        if(i == skaicius1->skaiciuKiekis) {
            ++skaicius1->skaiciuKiekis;
            skaicius1->skaiciai[i] = 0;
        }

        unsigned int skaicius2_vienasSkaicius = i < skaicius2->skaiciuKiekis ? skaicius2->skaiciai[i] : 0;
        unsigned int total = skaicius1->skaiciai[i] + skaicius2_vienasSkaicius + carry;
        skaicius1->skaiciai[i] = total % 10;
        carry = (total >= 10) ? 1 : 0;
    }
    return 1;
}

BOOL atimtisIlgasInt(IlgasInt* skaicius1, const IlgasInt* skaicius2) {
    unsigned int result_arNeigiamas = palyginimasIlgasInt(skaicius1, skaicius2) >= 0 ? 0 : 1;
    
    if(skaicius1->arNeigiamas == skaicius2->arNeigiamas) {
        if(!atimtisIlgasIntSkaiciai(skaicius1, skaicius2)) {
            return 0;
        }
    } else {
        if(!sudetisIlgasIntSkaiciai(skaicius1, skaicius2)) {
            return 0;
        }
    }
    
    skaicius1->arNeigiamas = result_arNeigiamas;
    return 1;
}


BOOL atimtisIlgasIntInt(IlgasInt* skaicius1, const int skaicius2) {
    IlgasInt* skaicius1_skaicius2 = nIlgasInt(skaicius2);
    if(!skaicius1_skaicius2) {
        return 0;
    }
    BOOL result = atimtisIlgasInt(skaicius1, skaicius1_skaicius2);
    freeIlgasInt(skaicius1_skaicius2);
    return result;
}

BOOL atimtisIlgasIntSkaiciai(IlgasInt* skaicius1, const IlgasInt* skaicius2) {

    unsigned int skaiciaiReikalingi = MAX(skaicius1->skaiciuKiekis, skaicius2->skaiciuKiekis) + 1;
    if(!IlgasIntSkaiciuPatikra(skaicius1, skaiciaiReikalingi)) {
        return 0;
    }

    unsigned char* greaterIntDigits;
    unsigned char* smallerIntDigits;
    unsigned int smallerIntNumDigits;
    unsigned int greaterIntNumDigits;

    if(palyginimasIlgasIntSkaiciai(skaicius1, skaicius2) > 0) {
        greaterIntDigits = skaicius1->skaiciai;
        greaterIntNumDigits = skaicius1->skaiciuKiekis;
        smallerIntDigits = skaicius2->skaiciai;
        smallerIntNumDigits = skaicius2->skaiciuKiekis;
    } else {
        greaterIntDigits = skaicius2->skaiciai;
        greaterIntNumDigits = skaicius2->skaiciuKiekis;
        smallerIntDigits = skaicius1->skaiciai;
        smallerIntNumDigits = skaicius1->skaiciuKiekis;
    }

    int i;
    int carry = 0;
    skaicius1->skaiciuKiekis = 1;

    for(i = 0; i < greaterIntNumDigits; ++i) {
        int new_vienasSkaicius;
        if(i < smallerIntNumDigits) {
            new_vienasSkaicius = (int)greaterIntDigits[i] - (int)smallerIntDigits[i] + carry;
        } else {
            new_vienasSkaicius = (int)greaterIntDigits[i] + carry;
        }

        if(new_vienasSkaicius < 0) {
            carry = -1;
            new_vienasSkaicius += 10;
        } else {
            carry = 0;
        }

        assert(new_vienasSkaicius >= 0);
        skaicius1->skaiciai[i] = new_vienasSkaicius;
        if(new_vienasSkaicius != 0) {
            skaicius1->skaiciuKiekis = i + 1;
        }
    }

    assert(carry == 0);
    return 1;
}

void spausdintiIlgasInt(const IlgasInt* skaicius1) {
    fspausdintiIlgasInt(stdout, skaicius1);
}

void fspausdintiIlgasInt(FILE *dest, const IlgasInt* skaicius1) {
    const unsigned char* base = skaicius1->skaiciai;
    const unsigned char* skaiciai = &base[skaicius1->skaiciuKiekis-1];
    if (skaicius1->arNeigiamas) fputc('-', dest);
    while(skaiciai >= base) {
        fputc('0' + *(skaiciai--), dest);
    }
}

unsigned int strlenIlgasInt(const IlgasInt* skaicius1){
    unsigned int len = skaicius1->skaiciuKiekis;
    if( skaicius1->arNeigiamas ){
        len++;
    }
    return len;
}

BOOL IlgasIntIString(const IlgasInt* skaicius1, char* buf, unsigned int bufDydis){
    const unsigned char* base = skaicius1->skaiciai;
    const unsigned char* skaiciai = &base[skaicius1->skaiciuKiekis-1];
    if (skaicius1->arNeigiamas){
        if(!bufDydis--){
            errno = ERANGE;
            return 0;
        }
        *buf++ = '-';
    }

    while( skaiciai >= base ){
        if(!bufDydis--){
            errno = ERANGE;
            return 0;
        }
        *buf++ = '0' + *(skaiciai--);
    }

    if(!bufDydis--){
        errno = ERANGE;
        return 0;
    }
    *buf++ = 0;

    return 1;
}

char* IlgasIntNString(const IlgasInt* skaicius1){
    unsigned int bufDydis = strlenIlgasInt(skaicius1) + 1;
    char* buf = malloc(bufDydis);
    if(!buf) {
        return NULL;
    }
    BOOL result = IlgasIntIString(skaicius1, buf, bufDydis);
    assert(result);
    return buf;
}

BOOL IlgasIntSkaiciuPatikra(IlgasInt* skaicius1, unsigned int skaiciaiReikalingi) {
    if(skaicius1->priskirtaSkaiciu < skaiciaiReikalingi) {
        assert(okaySkaiciai(skaicius1->skaiciai, skaicius1->priskirtaSkaiciu));
        unsigned char* new_skaiciai = mallocSkaiciai(skaiciaiReikalingi);
        if(!new_skaiciai) {
            return 0;
        }
        assert(okaySkaiciai(new_skaiciai, skaiciaiReikalingi));
        unsigned int old_allocated = skaicius1->priskirtaSkaiciu;
        unsigned char* old_skaiciai = skaicius1->skaiciai;
        memcpy(new_skaiciai, old_skaiciai, skaicius1->skaiciuKiekis * sizeof(unsigned char));
        skaicius1->skaiciai = new_skaiciai;
        skaicius1->priskirtaSkaiciu = skaiciaiReikalingi;

        freeSkaiciai(old_skaiciai, old_allocated);
        assert(okaySkaiciai(skaicius1->skaiciai, skaicius1->priskirtaSkaiciu));
    }
    return 1;
}

BOOL IlgasIntSulyginti(IlgasInt* target, const IlgasInt* source)
{
    if(!IlgasIntSkaiciuPatikra(target, source->skaiciuKiekis)) {
        return 0;
    }

    memmove(target->skaiciai, source->skaiciai, source->skaiciuKiekis * sizeof(unsigned char));

    target->arNeigiamas = source->arNeigiamas;
    target->skaiciuKiekis = source->skaiciuKiekis;
    return 1;
}

BOOL IlgasIntSulyginti_int(IlgasInt* target, const int source) {
    unsigned int value;
    if(value < 0) {
        target->arNeigiamas = 1;
        value = -source;
    } else {
        target->arNeigiamas = 0;
        value = source;
    }

    target->skaiciuKiekis = floor(log10(value)) + 1;

    if(target->skaiciuKiekis == 0) {
        target->skaiciuKiekis = 1;
    }

    if(!IlgasIntSkaiciuPatikra(target, target->skaiciuKiekis)) {
        return 0;
    }

    unsigned int count = target->skaiciuKiekis;
    unsigned char* skaiciai = target->skaiciai;
    while(count--) {
        *(skaiciai++) = value % 10;
        value /= 10;
    }
    return 1;
}

IlgasInt* IlgasIntKlonavimas(const IlgasInt* big_int, unsigned int priskirtaSkaiciu) {
    if(priskirtaSkaiciu < big_int->skaiciuKiekis) {
        priskirtaSkaiciu = big_int->skaiciuKiekis;
    }
    IlgasInt* new_big_int = malloc(sizeof(IlgasInt));
    if(!new_big_int) {
        return NULL;
    }
    new_big_int->skaiciai = mallocSkaiciai(priskirtaSkaiciu);
    if(!new_big_int->skaiciai) {
        free(new_big_int);
        return NULL;
    }
    new_big_int->priskirtaSkaiciu = priskirtaSkaiciu;
    new_big_int->arNeigiamas = big_int->arNeigiamas;
    new_big_int->skaiciuKiekis = big_int->skaiciuKiekis;
    memmove(new_big_int->skaiciai, big_int->skaiciai, big_int->skaiciuKiekis * sizeof(unsigned char));
    assert(okaySkaiciai(new_big_int->skaiciai, new_big_int->priskirtaSkaiciu));
    return new_big_int;
}

BOOL IlgasIntMultiply(IlgasInt* skaicius1, const IlgasInt* daugiklis) {

    IlgasInt* result = nIlgasInt(0);
    if(!result) {
        return 0;
    }

    IlgasInt* addend = nIlgasInt(0);
    if(!addend) {
        freeIlgasInt(result);
        return 0;
    }

    unsigned int skaiciaiReikalingi = skaicius1->skaiciuKiekis + daugiklis->skaiciuKiekis + 1;
    if(!IlgasIntSkaiciuPatikra(addend, skaiciaiReikalingi)) {
        freeIlgasInt(result);
        freeIlgasInt(addend);
        return 0;
    }

    int i, j;
    int carry = 0;
    for(i = 0; i < daugiklis->skaiciuKiekis; ++i) {

        if(i > 0) {
            addend->skaiciuKiekis = i;
            addend->skaiciai[i - 1] = 0;
        }

        for(j = 0; j < skaicius1->skaiciuKiekis || carry > 0; ++j) { // TODO FIXME: potential infinite loop
            if(j + i == addend->skaiciuKiekis) {
                ++addend->skaiciuKiekis;
            }

            assert(skaiciaiReikalingi >= j + 1);

            int total;
            if(j < skaicius1->skaiciuKiekis) {
                total = (skaicius1->skaiciai[j] * daugiklis->skaiciai[i]) + carry;
            } else {
                total = carry;
            }

            addend->skaiciai[i + j] = total % 10;
            carry = total / 10;
        }

        if(!sudetisIlgasInt(result, addend)) {
            freeIlgasInt(result);
            freeIlgasInt(addend);
            return 0;
        }
    }

    result->arNeigiamas = skaicius1->arNeigiamas != daugiklis->arNeigiamas;


    while(result->skaiciuKiekis > 1 && !result->skaiciai[result->skaiciuKiekis-1]) {
        result->skaiciuKiekis--;
    }

    BOOL success = IlgasIntSulyginti(skaicius1, result);
    freeIlgasInt(result);
    freeIlgasInt(addend);
    return success;
}

BOOL IlgasIntMultiply_int(IlgasInt* skaicius1, const int daugiklis) {
    IlgasInt* skaicius1Daugiklis = nIlgasInt(daugiklis);
    if(!skaicius1Daugiklis) {
        return 0;
    }
    BOOL result = IlgasIntMultiply(skaicius1, skaicius1Daugiklis);
    freeIlgasInt(skaicius1Daugiklis);
    return result;
}

BOOL IlgasInt_divide(
    IlgasInt* dividend, IlgasInt* divisor,
    IlgasInt* quotient, IlgasInt* remainder)
{
    int result = 0; 
    IlgasInt* nulis = nIlgasInt(0);
    IlgasInt* div2 = NULL;
    IlgasInt* div3 = NULL;
    IlgasInt* div4 = NULL;
    IlgasInt* div5 = NULL;
    IlgasInt* div6 = NULL;
    IlgasInt* div7 = NULL;
    IlgasInt* div8 = NULL;
    IlgasInt* div9 = NULL;
    IlgasInt* ten = NULL;
    IlgasInt* _quotient = NULL;
    IlgasInt* _remainder = NULL;

    if(!palyginimasIlgasInt(divisor, nulis)) {
        errno = ERANGE; 
        goto cleanup;
    }
    // jei nulis

    div2 = IlgasIntKlonavimas(divisor, divisor->skaiciuKiekis + 1);
    if(!div2 || !IlgasIntMultiply_int(div2, 2)) {
        goto cleanup;
    }
    div3 = IlgasIntKlonavimas(divisor, divisor->skaiciuKiekis + 1);
    printf("\n 3div: %s", IlgasIntNString(div3));
    if(!div3 || !IlgasIntMultiply_int(div3, 3)) {
        goto cleanup;
    }
    div4 = IlgasIntKlonavimas(divisor, divisor->skaiciuKiekis + 1);
    if(!div4 || !IlgasIntMultiply_int(div4, 4)) {
        goto cleanup;
    }
    printf("\n 4div: %s", IlgasIntNString(div4));
    div5 = IlgasIntKlonavimas(divisor, divisor->skaiciuKiekis + 1);
    if(!div5 || !IlgasIntMultiply_int(div5, 5)) {
        goto cleanup;
    }
    printf("\n 5div: %s", IlgasIntNString(div5));
    div6 = IlgasIntKlonavimas(divisor, divisor->skaiciuKiekis + 1);
    if(!div6 || !IlgasIntMultiply_int(div6, 6)) {
        goto cleanup;
    }
    printf("\n 6div: %s", IlgasIntNString(div6));
    div7 = IlgasIntKlonavimas(divisor, divisor->skaiciuKiekis + 1);
    if(!div7 || !IlgasIntMultiply_int(div7, 7)) {
        goto cleanup;
    }
    printf("\n 7div: %s", IlgasIntNString(div7));
    div8 = IlgasIntKlonavimas(divisor, divisor->skaiciuKiekis + 1);
    if(!div8 || !IlgasIntMultiply_int(div8, 8)) {
        goto cleanup;
    }
    printf("\n 8div: %s", IlgasIntNString(div8));
    div9 = IlgasIntKlonavimas(divisor, divisor->skaiciuKiekis + 1);
    if(!div9 || !IlgasIntMultiply_int(div9, 9)) {
        goto cleanup;
    }
    printf("\n 9div: %s", IlgasIntNString(div9));
 

    ten = nIlgasInt( 10 );
    _quotient = nIlgasInt( 0 );
    _remainder = nIlgasInt( 0 );
    if(!ten || !_quotient || !_remainder) 
    {
        goto cleanup;
    }

    IlgasInt* divs[10];

    divs[1] = divisor;
    divs[2] = div2;
    divs[3] = div3;
    divs[4] = div4;
    divs[5] = div5;
    divs[6] = div6;
    divs[7] = div7;
    divs[8] = div8;
    divs[9] = div9;

    const unsigned char* base = dividend->skaiciai; // prisiskiriu skaicius 
    const unsigned char* skaiciai = &base[dividend->skaiciuKiekis-1]; // kiek skaiciu

    while(skaiciai >= base) {
        if(!IlgasIntMultiply(_remainder, ten)) {
            goto cleanup;
        }
        if(!sudetisIlgasIntIrInt(_remainder, *skaiciai)) {
            goto cleanup;
        }
        int new_digit = 0;
        for(int i = 9; i >= 1; i--) {
            if(palyginimasIlgasInt(_remainder, divs[i]) >= 0) {
                if(!atimtisIlgasInt(_remainder, divs[i])) {
                    goto cleanup;
                }
                new_digit = i;
                break;
            }
        }
        if(!IlgasIntMultiply(_quotient, ten) || !sudetisIlgasIntIrInt(_quotient, new_digit)) {
            goto cleanup;
        }
        skaiciai--;
    }
    
    if(quotient) {
        if(!IlgasIntSulyginti(quotient, _quotient)) {
            goto cleanup;
        }
    }
    if(remainder) {
        if(!IlgasIntSulyginti(remainder, _remainder)) {
            goto cleanup;
        }
    }
    
    result = 1;
cleanup:
    freeIlgasInt(div2);
    freeIlgasInt(div3);
    freeIlgasInt(div4);
    freeIlgasInt(div5);
    freeIlgasInt(div6);
    freeIlgasInt(div7);
    freeIlgasInt(div8);
    freeIlgasInt(div9);
    freeIlgasInt(ten);
    freeIlgasInt(_remainder);
    freeIlgasInt(_quotient);
    return result;
}




