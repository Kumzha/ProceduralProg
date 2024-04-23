// sudaryti vienpusį sąrašą. Parašyti procedūrą,
// kuri įterpia prieš reikšme nurodytą elementą 
// naują elementą. Jeigu tokio elemento nėra, turi būti išvestas atitinkamas pranešimas.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funkcijos.h"

//Menu spausdinimo funkcija
void atspausdintiMenu()
{
    printf("------------------------------------------\n");
    printf("1. Sukurti Tuscia Sarasa\n");
    printf("2. Uzpildyti Sarasa Duomenimis Is Nurodyto Failo\n");
    printf("3. Pavaizduoti Saraso Duomenis krane\n");
    printf("4. Iterpia Nauja Elementa Pries Pasirinkta Elementa Sarase\n");
    printf("5. Istrinti Visa Sarasa\n");
    printf("6. Uzdaryti Programa\n");
    printf("------------------------------------------\n");
    printf("Irasykite Savo Pasirinkima: ");
    return;
}

//Naudotojo input patikrinimas meniu naudojimui
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
    if (*naudotIvest < 1 || *naudotIvest > 7)
    {
        printf("Tokio pasirinkimo nera! Rinkites is naujo.\n");
        gautiNaudotojoSkaiciu(naudotIvest);
    }
}
//Naudotojo input patikrinimas meniu naudojimui (y/n)
void gautiNaudotojoPasirinkima(char *naudotojoPasirinkimas)
{
    printf("Ar norite istrinti sarasa? y/n?");
    while (scanf("%1c", naudotojoPasirinkimas) != 1 || getchar() != '\n')
    {
        while (getchar() != '\n')
            ;
        printf("Neteisingai ivestas atsakymas! Iveskite y arba n raide.\n");
        printf("Ar tikrai norite istrinti visa sarasa? y/n? ");
    }
    if (*naudotojoPasirinkimas != 'y' && *naudotojoPasirinkimas != 'n')
    {
        printf("Neteisingai ivestas atsakymas! Iveskite y arba n raide.\n");
        gautiNaudotojoPasirinkima(naudotojoPasirinkimas);
    }
}

//Funkcija sukurti listui
struct list *createList(){
    struct list *head = (struct list*) malloc(sizeof(struct list));
    head->next = NULL;
    return head;
}

//Funkcija pasalinanti sukurta lista
void deleteList(struct list **head)
{
    struct list *delete;
    while (*head != NULL)
    {
        delete = *head;
        *head = (*head)->next;
        free(delete);
    }
}

//funkcija isprintinanti lista
void printList(struct list *head)
{
    printf("Saraso duomenys yra: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

//Uzpildo lista is nurodyto failo
void fillList(struct list *head, bool *listFull)
{
    FILE *readingFile;
    char *reading = (char *)malloc(30);
    printf("Iveskite duomenu failo pavadinima: ");
    scanf("%s", reading);
    readingFile = fopen(reading, "r");
    if (readingFile == NULL)
    {
        printf("Jusu nurodyto failo nepavyko atidaryti.\n");
        free(reading);
        return;
    }
    int fileData;
    reading = (char *)realloc(reading, strlen(reading) + 1);
    while (fscanf(readingFile, "%d", &fileData) == 1)
    {
        insertData(head, fileData, listFull);
    }
    fclose(readingFile);
    free(reading);
}

//Iterpia pries pasirinkta node sarase, nauja node
struct list *insertBefore(struct list *head, int target, int newData) 
{
    struct list *newNode = (struct list*)malloc(sizeof(struct list));
    newNode->data = newData;
  
    if(head == NULL) 
    {
        newNode->next = NULL;
        printf("Elementas iterptas sekmingai:)\n");
        return newNode; 
    }

    if(head->data == target) 
    {
        newNode->next = head;
        printf("Elementas iterptas sekmingai:)\n");
        return newNode;
    }

    struct list *curr = head;
    while(curr->next != NULL) 
    {
        if(curr->next->data == target) 
        {
            newNode->next = curr->next;
            curr->next = newNode;
            printf("Elementas iterptas sekmingai:)\n");
            return head;
        }   
    curr = curr->next;
    }
    printf("Tokio elemento sarase rasti nepavyko\n");  
    return head;
}

//Iterpia nauja node
void insertData(struct list *head, int fileData, bool *listFull){
    if(!*listFull){
        head->data = fileData;
        *listFull = true;
        return;
    }
    struct list *newNode = (struct list*) malloc(sizeof(struct list));
    newNode->data = fileData;
    newNode->next = NULL;
    struct list *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

