#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include "Data.h"
#include "Compare.h"
#include "Exception.h"
#include "CException.h"

typedef struct Item Item;
typedef struct LinkedList LinkedList;

struct Item{
	Item *next;
	Data *data;
};

struct LinkedList{
	Item *head;
	Item *tail;
	int len;
};

void listInit(LinkedList *list);
void listAdd(LinkedList *list,Item *item,uint32_t key,Compare compareFunc);
void *listRemove(LinkedList *list,uint32_t key,Compare compareFunc);
void *listSearch(LinkedList *list,uint32_t key,Compare compareFunc);
void createNew(Item *item,void *data,Item *next);

#endif // _LINKEDLIST_H
