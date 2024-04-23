#ifndef FUNKCIJOS
#define FUNKCIJOS

struct list
{
    int data;
    struct list *next;
};

void printMenu();
void getNumber(int *userInput);
void getUserAnswer(char *userAnswer);
struct list *createList();
void deleteList(struct list **head);
void printList(struct list *head);
void fillList(struct list *head, bool *listFull);
void insertData(struct list *head, int fileData, bool *listFull);
struct list *insertBefore(struct list *head, int target, int newData);

#endif