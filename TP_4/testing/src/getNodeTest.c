#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"

void getNodeTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void getNodeTest01(void)
{
    LinkedList* list;
    Node* nodo1;
    Node* nodo2;
    Node* nodoAux;

    list = ll_newLinkedList();
    nodo1 = malloc(sizeof(Node));
    nodo2 = malloc(sizeof(Node));
    nodo1->pNextNode = nodo2;
    nodo2->pNextNode = NULL;
    list->pFirstNode = nodo1;
    list->size=2;
    nodoAux = test_getNode(list,0);
    utest_assertNotNullMsg(nodoAux,"\nError en el valor de retorno de <getNode> si los parametros son correctos\n y la lista tiene elementos la funcion retorna el puntero al nodo\n");

}


void getNodeTest02(void)
{
    LinkedList* list;
    Node* nodo1;
    Node* nodo2;
    Node* nodoAux;

    list = ll_newLinkedList();
    nodo1 = malloc(sizeof(Node));
    nodo2 = malloc(sizeof(Node));
    nodo1->pNextNode = nodo2;
    nodo2->pNextNode = NULL;
    list->pFirstNode = nodo1;
    list->size=2;
    nodoAux = test_getNode(list,0);
    utest_assertEqualsPointerMsg(nodoAux,nodo1,"\nError en el valor de retorno de <getNode> al solicitar el primer elemento\n");

}

void getNodeTest03(void)
{
    LinkedList* list;
    Node* nodo1;
    Node* nodo2;
    Node* nodoAux;

    list = ll_newLinkedList();
    nodo1 = malloc(sizeof(Node));
    nodo2 = malloc(sizeof(Node));
    nodo1->pNextNode = nodo2;
    nodo2->pNextNode = NULL;
    list->pFirstNode = nodo1;
    list->size=2;
    nodoAux = test_getNode(list,1);
    utest_assertEqualsPointerMsg(nodoAux,nodo2,"\nError en el valor de retorno de <getNode> al solicitar el ultimo elemento\n");

}

void getNodeTest04(void)
{
    LinkedList* list;
    Node* nodo1;
    Node* nodo2;
    Node* nodoAux;

    list = ll_newLinkedList();
    nodo1 = malloc(sizeof(Node));
    nodo2 = malloc(sizeof(Node));
    nodo1->pNextNode = nodo2;
    nodo2->pNextNode = NULL;
    list->pFirstNode = nodo1;
    list->size=1;
    nodoAux = test_getNode(list,-1);
    utest_assertNullMsg(nodoAux, "\nError en el valor de retorno de <getNode> al solicitar un elemento fuera de indice (-1),\n se deberia retornar NULL\n");
    nodoAux = test_getNode(list,1);
    utest_assertNullMsg(nodoAux, "\nError en el valor de retorno de <getNode> al solicitar un elemento fuera de indice (>= a ll_len),\n se deberia retornar NULL\n");


}

void getNodeTest05(void)
{
    utest_assertNullMsg(test_getNode(NULL,0),"\nError en el valor de retorno de <get> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}

