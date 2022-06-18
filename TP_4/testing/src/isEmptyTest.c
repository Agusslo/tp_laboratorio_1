#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"

void isEmptyTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void isEmptyTest01(void)
{
    LinkedList* list;
    int r;
    list = ll_newLinkedList();
    r = ll_isEmpty(list);
    utest_assertEqualsIntMsg(r,1,"\nError en el valor de retorno de <isEmpty> si los parametros son correctos y \nla lista NO tiene elementos debe retornar 1\n");
    ll_add(list,NULL);
    r = ll_isEmpty(list);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <isEmpty> si los parametros son correctos y \nla lista tiene elementos debe retornar 0\n");

}

void isEmptyTest02(void)
{
    int r;
    r = ll_isEmpty(NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <isEmpty> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}
