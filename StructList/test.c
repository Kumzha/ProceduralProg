#include "funkcijos.c"
#include "funkcijos.h"
#include "assert.h"

void testInsertData() 
{
    bool listFull = false;
    struct list* head = createList();
    insertData(head, 5, &listFull);
    assert(5 == head->data);
    insertData(head, 10, &listFull);
    printf("insertData() test passed\n");
}
void testDeleteList()
{
    bool listFull = false;
    struct list* head = createList();
    insertData(head, 5, &listFull);
    insertData(head, 10, &listFull);
    insertData(head, 15, &listFull);
    deleteList(&head);
    assert(head == NULL);
    printf("deleteList() test passed\n");
}

void testCreateList()  
{
    struct list* head = createList();
    assert(head!= NULL);

    printf("testCreateList() test passed\n");
}
void testFillList()
{
    struct list* head = createList();
    bool listFull = false;
    fillList(head, &listFull);
    assert(head->data == 1);
    assert(head->next->data == 2);
    assert(head->next->next->data == 3);
    printf("testFillList() test passed\n");
}
void testInsertBefore()
{
    bool listFull = false;
    struct list* head = createList();
    insertData(head, 5, &listFull);
    insertData(head, 10, &listFull);
    insertBefore(head, 10, 20);
    assert(head->next->data == 20);
    printf("testInsertBefore() test passed\n");
}
void testPrintList()
{
    struct list* head = createList();
    bool listFull = false;
    fillList(head, &listFull);
    printList(head);
    printf("testPrintlist() test passed\n");
}

int main()
{
    testInsertBefore();
    testInsertData();
    testPrintList();
    testFillList();
    testDeleteList();
}