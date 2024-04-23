#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funkcijos.h"

// kas jei tokio elemento nera
// ivestis teisinga



int main()
{
    int naudotojoIvestis, naudotojoDuomenys, naudotojoTikslas;
    char naudotojoAtsr;
    bool listExists = false, listFull = false;
    struct list *head;

    printf("Sveiki, si programa leidzia jums valdyti vienpusi sarasa, pasirinkite viena is zemiau nurodytu variantu:\n");
    while (1)
    {
        gautiNaudotojoSkaiciu(&naudotojoIvestis);
        switch (naudotojoIvestis)
        {
        case 1:
            if (listExists)
            {
                printf("Sarasas jau yra sukurtas! Istrinkite sena, kad galetumete sukurti nauja\n");
                break;
            }
            else
            {
                head = createList();
                printf("Sarasas sukurtas sekmingai.\n");
                listExists = true;
                break;
            }
        case 2:
            if (!listExists)
            {
                printf("Nera sukurto saraso, kad uzpildytumete sarasa duomenimis, reikia ji sukurti(1).\n");
                break;
            }
            else if (listFull)
            {
                printf("Sarasas jau uzpidlytas, jei norite ji uzpildyti is naujo, reikia istrinti sena(5), sukurti nauja(1) ir tada uzpildyti duomenimis.\n");
                break;
            }
            fillList(head, &listFull);
            if (listFull)
            {
                printf("Sarasas sekmingai uzpildytas duomenimis.\n");
            }
            break;
        case 3:
            if (!listExists)
            {
                printf("Sarasas neegzistuoja, jei norite pavaizduoti saraso dumenis ekrane, reikia sukurti sarasa(1), ir ji uzpildyti duomenimis(2)\n");
                break;
            }
            else if (!listFull)
            {
                printf("Sarase duomenu atrasti nepavyko, jei nori juos pavaizduoti, reikes sarasa uzpildyti duomenimis(2)\n");
                break;
            }
            printList(head);
            break;

        case 4:
            if (!listExists)
            {
                printf("Nera sukurto saraso, norint iterpti nauja elementa, sukurkite sarasa(1), uzpildykite ji duomenimis(2).\n");
                break;
            }
            else if(listFull)
            {
                printf("Elementas, pries kuri norite iterpti nauja elementa: ");

                while (scanf("%d", &naudotojoTikslas) != 1 || getchar() != '\n')
                {
                    while (getchar() != '\n')
                        ;
                    printf("Toks elementas negali egzistuoti\nIveskite elementa is naujo: ");
                }

                printf("Iveskite naujo elemento duomenis: ");
                while (scanf("%d", &naudotojoDuomenys) != 1 || getchar() != '\n')
                {
                    while (getchar() != '\n')
                        ;
                }

                insertBefore(head, naudotojoTikslas, naudotojoDuomenys);
                break;
            }else
            {
                printf("Sarasas tuscias, uzpildikite ji duomenimis(2), kad galetumete iterpti nauja elementa");
                break;
            }

        case 5:
            if (!listExists)
            {
                printf("Saraso nera, nera ko istrinti:D.\n");
                break;
            }
            gautiNaudotojoPasirinkima(&naudotojoAtsr);
            if (naudotojoAtsr == 'y')
            {
                deleteList(&head);
                printf("Sarasas sekmingai istrintas.\n");
                listExists = false;
                listFull = false;
                break;
            }
            else
            {
                printf("Sarasas nebuvo istrintas.\n");
                break;
            }
        case 6:
            if (listExists)
            {
                deleteList(&head);
            }
            return 0;
        }
    }
    return 0;
}