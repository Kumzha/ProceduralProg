#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "IlgasInt.h"

#define MAXIMUM 40

int main() {


    int naudotojoIvestis, naudotojoTikslas;
    char naudotojoDuomenys[100];
    char naudotojoAts;
    bool skaicius1 = false, skaicius2 = false;
    IlgasInt* IlgasInt1, *IlgasInt2;
    IlgasInt* liekana = nIlgasInt(0), *atsakymas = nIlgasInt(0);

    printf("Sveiki, si programa leidzia jums valdyti 2 sveikus ilgus skaicius.\n");
    while (1)
    {
        gautiNaudotojoSkaiciu(&naudotojoIvestis);
        switch (naudotojoIvestis)
        {
        case 1:
            if (skaicius1)
            {
                printf("Pirmas skaicius jau ivestas. Istrinkite sena, kad galetumete sukurti nauja\n");
                break;
            }
            else
            {
                printf("Iveskite pirmo ilgo sveiko skaiciaus reiksme: \n");
                scanf("%s", &naudotojoDuomenys);
                if(strlen(naudotojoDuomenys) > MAXIMUM){
                    printf("Skaiciu negali buti ilgesnis nei %d simboliai\n", MAXIMUM);
                    break;
                }else{
                IlgasInt1 = nIlgasIntIsString(naudotojoDuomenys);
                skaicius1 = true;
                break;
                }
            }
        case 2:
            if (skaicius2)
            {
                printf("Antras skaicius jau ivestas. Istrinkite sena, kad galetumete sukurti nauja\n");
                break;
            }
            else
            {
                
                printf("Iveskite antro ilgo sveiko skaiciaus reiksme: \n");
                scanf("%s", &naudotojoDuomenys);
                if(strlen(naudotojoDuomenys) > MAXIMUM){
                    printf("Skaiciu negali buti ilgesnis nei %d simboliai\n", MAXIMUM);
                    break;
                }else{
                IlgasInt2 = nIlgasIntIsString(naudotojoDuomenys);
                skaicius2 = true;
                break;
                }
            }
        case 3:
            if (!skaicius1 && !skaicius2)
            {
                printf("Skaiciai neegzistuoja, jei norite pavaizduoti skaicius ekrane reikia juos sukurti\n");
                break;
            }
            else if (!skaicius2)
            {
            printf("\nPirmas Skaicius:");
            spausdintiIlgasInt(IlgasInt1);
            printf("\n");
            printf("\nAntras Skaicius:");
            printf("Nera antro skaiciaus\n");
            printf("\n");
            break;
            }
            else if (!skaicius1)
            {
            printf("\nPirmas Skaicius:");
            printf("Nera pirmo skaiciaus\n");
            printf("\n");
            printf("\nAntras Skaicius:");
            spausdintiIlgasInt(IlgasInt2);
            printf("\n");
            break;
            }
            printf("\nPirmas Skaicius:");
            spausdintiIlgasInt(IlgasInt1);
            printf("\n");
            printf("\nAntras Skaicius:");
            spausdintiIlgasInt(IlgasInt2);
            printf("\n");
            break;

        case 4:
            if (!skaicius1 || !skaicius2)
            {
                printf("Skaiciai neegzistuoja, jei norite atlikti sudeti reikia juos sukurti\n");
                break;
            }
            IlgasInt* temp = IlgasIntKlonavimas(IlgasInt1, IlgasInt1->priskirtaSkaiciu);
            sudetisIlgasInt(IlgasInt1, IlgasInt2);
            printf("\nSudeties atsakymas: ");
            spausdintiIlgasInt(IlgasInt1);
            printf("\n");
            IlgasInt1= IlgasIntKlonavimas(temp, temp->priskirtaSkaiciu);
            freeIlgasInt(temp);  
            break;

        case 5:
            if (!skaicius1 || !skaicius2)
            {
                printf("Skaiciai neegzistuoja, jei norite atlikti atimti reikia juos sukurti\n");
                break;
            }
            IlgasInt* temp2 = IlgasIntKlonavimas(IlgasInt1, IlgasInt1->priskirtaSkaiciu);
            atimtisIlgasInt(IlgasInt1, IlgasInt2);
            printf("\nAtimties atsakymas: ");
            spausdintiIlgasInt(IlgasInt1);
            printf("\n");   
            IlgasInt1= IlgasIntKlonavimas(temp2, temp2->priskirtaSkaiciu);  
            freeIlgasInt(temp2);       
            break;
        case 6:
            gautiNaudotojoPasirinkima(&naudotojoAts);
            if (naudotojoAts == 'y')
            {
                if(skaicius1){ 
                    freeIlgasInt(IlgasInt1);
                }else{
                    printf("Pirmo skaiciaus nera\n");
                }
                printf("Skaicius sekmingai istrintas.\n");
                
                printf("Iveskite pirmo ilgo sveiko skaiciaus reiksme: \n");
                scanf("%s", &naudotojoDuomenys);
                IlgasInt1 = nIlgasIntIsString(naudotojoDuomenys);
                skaicius1 = true;
                break;
            }else
            {
                printf("Skaicius nebuvo pakeistas.\n");
                break;
            }
        case 7:
            gautiNaudotojoPasirinkima(&naudotojoAts);
            if (naudotojoAts == 'y')
            {
                if(skaicius2){ 
                    freeIlgasInt(IlgasInt2);
                }else{
                    printf("Antro skaiciaus nera\n");
                }
                printf("Skaicius sekmingai istrintas.\n");

                printf("Iveskite pirmo ilgo sveiko skaiciaus reiksme: \n");
                scanf("%s", &naudotojoDuomenys);
                IlgasInt1 = nIlgasIntIsString(naudotojoDuomenys);
                skaicius2 = true;
                break;
            }else
            {
                printf("Skaicius nebuvo istrintas.\n");
                break;
            }
        case 8:
            if (skaicius1&&skaicius2){
                IlgasInt* temp = IlgasIntKlonavimas(IlgasInt1, IlgasInt1->priskirtaSkaiciu);
                IlgasIntMultiply(IlgasInt1, IlgasInt2);
                printf("\nDaugybos atsakymas: ");
                spausdintiIlgasInt(IlgasInt1);
                printf("\n");
                IlgasInt1 = IlgasIntKlonavimas(temp, temp->priskirtaSkaiciu);
                freeIlgasInt(temp);  
                break;
            }else{
                printf("Skaiciai neegzistuoja, jei norite atlikti sudeti reikia juos sukurti\n");
                break;
            }
        case 9:
            if (skaicius1&&skaicius2){
                IlgasInt* nulis = nIlgasInt(0);
                if (palyginimasIlgasInt(IlgasInt2, nulis)==0)
                {
                    printf("Dalyba is nulio negalima\n");
                }else{
                    IlgasInt_divide(IlgasInt1, IlgasInt2, atsakymas, liekana);
                }
                    printf("\nAtsakymas:");
                spausdintiIlgasInt(atsakymas);
                    printf("\nLiekana:");
                spausdintiIlgasInt(liekana);
                printf("\n");
                break;
            }else{
                printf("Skaiciai neegzistuoja, jei norite atlikti sudeti reikia juos sukurti\n");
                break;
            }
        case 10:
            if (skaicius1)
            {
                freeIlgasInt (IlgasInt1);
            }

            if (skaicius2)
            {
                freeIlgasInt(IlgasInt2);
            }

            printf("\nPrograma baigia darba. Aciu!\n");
            return 0;
            
        }
    }

    return 0;
}




