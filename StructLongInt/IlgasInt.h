#ifndef LONG_INT_H
#define LONG_INT_H

#include <stdint.h>

#ifndef NULL
#define NULL 0
#endif

#ifndef BOOL
#define BOOL int8_t
#endif

typedef struct IlgasInt {
    unsigned char* skaiciai; 
    unsigned int skaiciuKiekis; 
    unsigned int priskirtaSkaiciu; 
    BOOL arNeigiamas; 
} IlgasInt;

IlgasInt* IlgasIntKlonavimas(const IlgasInt* big_int, unsigned int priskirtaSkaiciu);

BOOL IlgasIntSulyginti_int(IlgasInt* target, const int source);

BOOL IlgasIntSulyginti(IlgasInt* target, const IlgasInt* source);

IlgasInt* IlgasIntKlonavimas(const IlgasInt* skaicius1, unsigned int priskirtaSkaiciu);

void atspausdintiMenu();

void gautiNaudotojoPasirinkima(char *naudotojoPasirinkimas);

void gautiNaudotojoSkaiciu(int *naudotIvest);

IlgasInt* nIlgasInt(int reiksme);

IlgasInt* nIlgasIntIsString(const char* str);

void freeIlgasInt(IlgasInt* skaicius1);

void spausdintiIlgasInt(const IlgasInt* skaicius1);

void fspausdintiIlgasInt(FILE *dest, const IlgasInt* skaicius1);

unsigned int strlenIlgasInt(const IlgasInt* skaicius1);

BOOL IlgasIntIString(const IlgasInt* skaicius1, char* buf, unsigned int bufDydis);

char* IlgasIntNString(const IlgasInt* skaicius1);

int palyginimasIlgasInt(const IlgasInt* a, const IlgasInt* b);

BOOL sudetisIlgasInt(IlgasInt* skaicius1, const IlgasInt* skaicius2);

BOOL sudetisIlgasIntIrInt(IlgasInt* skaicius1, const int skaicius2);

BOOL atimtisIlgasInt(IlgasInt* skaicius1, const IlgasInt* skaicius2);

BOOL atimtisIlgasIntInt(IlgasInt* skaicius1, const int skaicius2);

BOOL IlgasIntSkaiciuPatikra(IlgasInt* skaicius1, unsigned int skaiciaiReikalingi);

int palyginimasIlgasIntSkaiciai(const IlgasInt* a, const IlgasInt* b);

BOOL sudetisIlgasIntSkaiciai(IlgasInt* skaicius1, const IlgasInt* skaicius2);

BOOL atimtisIlgasIntSkaiciai(IlgasInt* skaicius1, const IlgasInt* skaicius2);

BOOL IlgasInt_divide(IlgasInt* dividend, IlgasInt* divisor, IlgasInt* quotient, IlgasInt* remainder);

BOOL IlgasIntMultiply_int(IlgasInt* skaicius1, const int daugiklis);

BOOL IlgasIntMultiply(IlgasInt* skaicius1, const IlgasInt* daugiklis);

#endif 

