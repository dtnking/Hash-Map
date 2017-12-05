#ifndef _HASHMAP_H
#define _HASHMAP_H
#include "stdint.h"
#include "linkedlist.h"

#define SIZE_FACTOR   3

typedef int (*Compare)(void *data,void *refData);

typedef struct HashTable HashTable;
struct HashTable{
  LinkedList **list;
  int size;
};

void hashMapInit(HashTable *table, int size);
void _hashMapAdd(HashTable *table, void *data, int index);
void _hashMapSearch(HashTable *table,void *data,int index,Compare compareFunc);
void _hashMapRemove(HashTable *table, void *data, int index, Compare compareFunc);
uint32_t hashUsingModulo(uint32_t value,uint32_t range);
void hashMapAddInteger(HashTable *table, int data);
void hashMapSearch(HashTable *table, int data);
void hashMapRemove(HashTable *table, int data);
#endif // _HASHMAP_H
