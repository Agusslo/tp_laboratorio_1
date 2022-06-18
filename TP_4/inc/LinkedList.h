#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif


LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* esto);
Node* test_getNode(LinkedList* esto, int nodeIndex);
int test_addNode(LinkedList* esto, int nodeIndex,void* pElement);
int ll_add(LinkedList* esto, void* pElement);
void* ll_get(LinkedList* esto, int index);
int ll_set(LinkedList* esto, int index,void* pElement);
int ll_remove(LinkedList* esto,int index);
int ll_clear(LinkedList* esto);
int ll_deleteLinkedList(LinkedList* esto);
int ll_indexOf(LinkedList* esto, void* pElement);
int ll_isEmpty(LinkedList* esto);
int ll_push(LinkedList* esto, int index, void* pElement);
void* ll_pop(LinkedList* esto,int index);
int ll_contains(LinkedList* esto, void* pElement);
int ll_containsAll(LinkedList* esto,LinkedList* esto2);
LinkedList* ll_subList(LinkedList* esto,int from,int to);
LinkedList* ll_clone(LinkedList* esto);
int ll_sort(LinkedList* esto, int (*pFunc)(void* ,void*), int order);
