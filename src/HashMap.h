#ifndef _HASHMAP_H
#define _HASHMAP_H
#include "stdint.h"
#include "Compare.h"
#include "linkedlist.h"
#include "Exception.h"
#include "CExceptionConfig.h"
#include "Data.h"

#define SIZE_FACTOR   3

typedef int (*Compare)(void *data,void *refData);

typedef struct HashTable HashTable;
struct HashTable{
  LinkedList *list;
  int size;
  int sizeFactor;
};

void hashMapInit(HashTable *table, int size);
void _hashMapAdd(HashTable *table,uint32_t key, void *data, int index, Compare compareFunc);
void *_hashMapSearch(HashTable *table,uint32_t key,int index,Compare compareFunc);
void *_hashMapRemove(HashTable *table, uint32_t key, int index, Compare compareFunc);
uint32_t hashUsingModulo(uint32_t value,uint32_t range);
void hashMapAdd(HashTable *table,uint32_t key, void *value, int index, Compare compareFunc);
void hashMapSearch(HashTable *table,uint32_t key,Compare compareFunc);
void hashMapRemove(HashTable *table, uint32_t key);
#endif // _HASHMAP_H
