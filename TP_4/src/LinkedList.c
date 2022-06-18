#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* esto, int nodeIndex);
static int addNode(LinkedList* esto, int nodeIndex, void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* esto = NULL;
    esto = (LinkedList*) malloc(sizeof(LinkedList));

    if(esto != NULL)
    {
    	esto->size = 0;
    	esto->pFirstNode = NULL;
    }

    return esto;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param esto LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* esto)
{
    int returnn = -1;

    if(esto != NULL)
    {
    	returnn = esto->size;
    }

    return returnn;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param esto LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* esto, int nodeIndex)
{
	Node* pNode = NULL;
	int i;

	if(esto != NULL && nodeIndex >= 0 && nodeIndex < ll_len(esto))
	{
		pNode = esto->pFirstNode;

		for(i=0; i<nodeIndex ;i++)
		{
			pNode = pNode->pNextNode;
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param esto LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* esto, int nodeIndex)
{
    return getNode(esto,nodeIndex);
}

/** \brief agrega un nuevo nodo y lo vincula a la lista
 *
 * \param esta LinkedList* puntero a la lista
 * \param nodeIndex int donde se agregará el nuevo nodo
 * \param pElement void* apunta al elemento que va a contener el nuevo nodo
 * \return int return (-1) error: si el puntero a la lista es NULL o (si el índice es menor que 0 o mayor que la longitud de la lista)
                        (0) si funciona bien
 *
 */
static int addNode(LinkedList* esto, int nodeIndex, void* pElement)
{
    int returnn = -1;
    Node* pNodeNew = NULL;
    Node* pNodePrev = NULL;

    if(esto != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(esto))
    {
		pNodeNew = (Node*) malloc(sizeof(Node));

		if(pNodeNew != NULL)
		{
			pNodeNew->pElement = pElement;

			if(nodeIndex == 0)
			{
				pNodeNew->pNextNode = esto->pFirstNode;
				esto->pFirstNode = pNodeNew;
			}else
			{
				pNodePrev = getNode(esto,nodeIndex-1);

				if(pNodePrev != NULL)
				{
					pNodeNew->pNextNode = pNodePrev->pNextNode;
					pNodePrev->pNextNode = pNodeNew;
				}
			}
			esto->size++;
			returnn = 0;
    	}
    }

    return returnn;
}

/** \brief le permite probar la función addNode, que es privada
 *
 * \param esta LinkedList* puntero a la lista
 * \param nodeIndex int donde se agregará el nuevo nodo
 * \param pElement void* apunta al elemento que va a contener el nuevo nodo
  * \return int return (-1) error: si el puntero a la lista es NULL o (si el índice es menor que 0 o mayor que la longitud de la lista)
                        (0) si funciona bien
 *
 */
int test_addNode(LinkedList* esto, int nodeIndex, void* pElement)
{
    return addNode(esto,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* esto, void* pElement)
{
    int returnn = -1;

    if(esto != NULL)
    {
		returnn = addNode(esto,ll_len(esto),pElement);
    }

    return returnn;
}

/** \brief le permite probar la función addNode, que es privada
 *
 * \param esta LinkedList* puntero a la lista
 * \param nodeIndex int la posición del elemento a obtener
 * \return void* Devuelve (NULL) Error: si el puntero a la lista es NULL o (si el índice es menor que 0 o mayor que el len)
                            (pElement) si funciona bien
 *
 */
void* ll_get(LinkedList* esto, int index)
{
    void* returnn = NULL;
    Node* pNode = NULL;

    if(esto != NULL && index >= 0)
    {
    	if(index < ll_len(esto))
    	{
			pNode = getNode(esto, index);

			if(pNode != NULL)
			{
	    		returnn = pNode->pElement;
			}
    	}
    }

    return returnn;
}

/** \brief modifica un elemento de la lista
 *
 * \param esta LinkedList* puntero a la lista
 * \param nodeIndex int posición del elemento a modificar
 * \param pElement void* puntero a nuevo elemento
 * \return int Devuelve (-1) Error: si el puntero a la lista es NULL o (si el índice es menor que 0 o mayor que el len)
                        (0) si funciona bien
 *
 */
int ll_set(LinkedList* esto, int index, void* pElement)
{
    int returnn = -1;
    Node* pNode = NULL;

    if(esto != NULL && index >= 0)
    {
    	if(index < ll_len(esto))
    	{
    		pNode = getNode(esto,index);

    		if(pNode != NULL)
    		{
    			pNode->pElement = pElement;
    		    returnn = 0;
    		}
    	}
    }

    return returnn;
}

/** \brief elimina un elemento de la lista
 *
 * \param esta LinkedList* puntero a la lista
 * \param nodeIndex int posición del elemento a eliminar
 * \return int Devuelve (-1) Error: si el puntero a la lista es NULL o (si el índice es menor que 0 o mayor que el len)
                        (0) si funciona bien
 *
 */
int ll_remove(LinkedList* esto, int index)
{
    int returnn = -1;
    int len;
    Node* pNodeAux = NULL;
    Node* pNodePrev = NULL;

    if(esto != NULL && index >= 0)
    {
    	len = ll_len(esto);

    	if(index < len)
    	{
    		pNodeAux = getNode(esto,index);

    		if(pNodeAux != NULL)
    		{
    			if(index == 0)
    			{
    				esto->pFirstNode = pNodeAux->pNextNode;
    				free(pNodeAux);
    				esto->size--;
    				returnn = 0;
    			}else
    			{
    				pNodePrev = getNode(esto,index-1);

    				if(pNodePrev != NULL)
    				{
    		        	pNodePrev->pNextNode = pNodeAux->pNextNode;
    		        	free(pNodeAux);
    		        	esto->size--;
    					returnn = 0;
    				}
    			}
    		}
    	}
    }

    return returnn;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param esto LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* esto)
{
    int returnn = -1;
    int i;

    if(esto != NULL)
    {
    	if(!ll_isEmpty(esto))
    	{
    		for(i=0; i<ll_len(esto) ;i++)
    		{
    			ll_remove(esto,i);
    			returnn = 0;
    		}
    	}else
    	{
        	esto->pFirstNode = NULL;
        	esto->size = 0;
        	returnn = 0;
    	}
    }

    return returnn;
}

/** \brief elimina todos los elementos de listas y listas
 *
 * \param esta LinkedList* puntero a la lista
 * \return int return (-1) error: si el puntero a la lista es NULL
                        (0) si funciona bien
 *
 */
int ll_deleteLinkedList(LinkedList* esto)
{
    int returnn = -1;

    if(esto != NULL)
    {
    	if(!ll_clear(esto))
    	{
        	free(esto);
        	returnn = 0;
    	}
    }

    return returnn;
}

/** \brief elimina todos los elementos de listas y listas
 *
 * \param esta LinkedList* puntero a la lista
 * \return int return (-1) error: si el puntero a la lista es NULL
                        (0) si funciona bien
 *
 */
int ll_indexOf(LinkedList* esto, void* pElement)
{
    int returnn = -1;
    int i;
    Node* pNode = NULL;

    if(esto != NULL)
    {
    	if(!ll_isEmpty(esto))
    	{
        	for(i=0; i<ll_len(esto) ;i++)
        	{
        		pNode = getNode(esto,i);

        		if(pNode != NULL && pNode->pElement == pElement)
        		{
        			returnn = i;
        			break;
        		}
        	}
    	}
    }

    return returnn;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param esto LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* esto)
{
    int returnn = -1;
    int len;

    if(esto != NULL)
    {
    	len = ll_len(esto);

    	if(len>0)
    	{
    		returnn = 0;
    	}else
    	{
    		returnn = 1;
    	}
    }

    return returnn;
}

/** \brief Inserta un nuevo elemento en la posición especificada en la lista
 *
 * \param esta LinkedList* puntero a la lista
 * \param nodeIndex int donde se agregará el nuevo elemento
 * \param pElement void* puntero a nuevo elemento
 * \return int return (-1) error: si el puntero a la lista es NULL o (si el índice es menor que 0 o mayor que la longitud de la lista)
                        (0) si funciona bien
 *
 */
int ll_push(LinkedList* esto, int index, void* pElement)
{
    int returnn = -1;

    if(esto != NULL && index >= 0 && index <= ll_len(esto))
    {
        returnn = addNode(esto,index,pElement);//le paso el indice y el elemento a guardar
    }

    return returnn;
}

/** \brief elimina el elemento de la posición especificada y devuelve su puntero
 *
 * \param esta LinkedList* puntero a la lista
 * \param nodeIndex int posición de eliminación del elemento
 * \return void* Devuelve (NULL) Error: si el puntero a la lista es NULL o (si el índice es menor que 0 o mayor que el len)
                            (pElement) si funciona bien
 *
 */
void* ll_pop(LinkedList* esto, int index)
{
    void* returnn = NULL;
    void* pAux = NULL;

    if(esto != NULL && index >= 0 && index <= ll_len(esto))
    {
    	 pAux = ll_get(esto,index);

		if(!ll_remove(esto,index))
		{
			returnn = pAux;
		}
    }

    return returnn;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param esto LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* esto, void* pElement)
{
    int returnn = -1;
    int i;

    if(esto != NULL)
    {
    	returnn = 0;

    	if(!ll_isEmpty(esto))
    	{
    		for(i=0; i<ll_len(esto) ;i++)
    		{
    			if(ll_indexOf(esto,pElement)==i)
    			{
    				returnn = 1;
    			}
    		}
    	}
    }

    return returnn;
}

/** \brief  Determina si todos los elementos de la lista (esto2)
            estan contenidos en la lista (esto)
 *
 * \param esto LinkedList* Puntero a la lista
 * \param esto2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (esto2) estan contenidos en la lista (esto)
                        ( 0) si los elementos de (esto2) NO estan contenidos en la lista (esto)
*/
int ll_containsAll(LinkedList* esto,LinkedList* esto2)
{
    int returnn = -1;
    int i;
    void* pElement = NULL;

    if(esto != NULL && esto2 != NULL)
    {
    	returnn = 1;

    	if(!ll_isEmpty(esto2) && !ll_isEmpty(esto))
    	{
    		for(i=0; i<ll_len(esto2) ;i++)
    		{
    			pElement = ll_get(esto2,i);

    			if(pElement != NULL)
    			{
    				if(!ll_contains(esto,pElement))
    				{
    					returnn = 0;
    					break;
    				}
    			}
    		}
    	}
    }

    return returnn;
}

/** \brief crea y devuelve una nueva lista que contiene los elementos especificados
 *
 * \param pList LinkedList* puntero a lista
 * \param from int copia el índice del elemento en la nueva lista
 * \param para int el índice al que se copia el elemento en la nueva lista (exclusivo)
 * \return LinkedList* devuelve (NULL) error: si el puntero a la lista es NULL
                                o (si el índice from es menor que 0 o mayor que la longitud de la lista)
                                o (si el índice de to es menor o igual que from o mayor que la longitud de la lista)
                         (puntero a nueva lista) sí
*/
LinkedList* ll_subList(LinkedList* esto, int from, int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    int i;

    if(esto != NULL && from >= 0 && to >= 0 && from <= ll_len(esto) && to <= ll_len(esto))
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(i=from; i<to ;i++)
    		{
    			pElement = ll_get(esto,i);
    			ll_add(cloneArray,pElement);
    		}
    	}
    }

    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* esto)
{
    LinkedList* cloneArray = NULL;

    if(esto != NULL)
    {
    	cloneArray = ll_subList(esto,0,ll_len(esto));
    }

    return cloneArray;
}

/** \brief ordena los elementos de la lista usando las funciones estándar recibidas como argumentos
 * \param pList LinkedList* puntero a lista
 * \param pFunc (*pFunc) puntero a función estándar
 * \param order int [1] para orden ascendente - [0] para orden descendente
 * \return int return (-1) error: si el puntero de la lista es NULL
                                (0) si
 */
int ll_sort(LinkedList* esto, int (*pFunc)(void* ,void*), int order)
{
    int returnn = -1;
    int i;
    int e;
    int len;
    void* pElementI = NULL;
    void* pElementJ = NULL;

    if(esto != NULL && (order==1 || order==0) && pFunc!=NULL)
    {
    	len = ll_len(esto);

    	for(i=0; i<len-1 ;i++)
    	{
    		for(e=i+1; e<len ;e++)
    		{
    			pElementI = ll_get(esto,i);
    			pElementJ = ll_get(esto,e);

    			if(pFunc(pElementI,pElementJ)>0 && order==1)
    			{
    				 ll_set(esto,i,pElementJ);
    				 ll_set(esto,e,pElementI);
    				 returnn = 0;
    			}else
    			{
    				if(pFunc(pElementI,pElementJ)<=0 && order==0)
    				{
    					ll_set(esto,i,pElementJ);
    					ll_set(esto,e,pElementI);
    					returnn = 0;
    				}
    			}
    		}
    	}
    }

    return returnn;
}

