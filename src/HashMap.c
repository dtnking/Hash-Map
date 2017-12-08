#include "HashMap.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

void hashMapInit(HashTable *table, int size){
  table->list = (LinkedList **)calloc(size * SIZE_FACTOR , sizeof(LinkedList));
  table->size = size;
}

void _hashMapAdd(HashTable *table,uint32_t key, void *data, int index, Compare compareFunc){
  Item *newItem = (Item *)malloc(sizeof(Item));
  createNew(newItem,data,NULL);
  if(index < table->size){
  if(listSearch(&table->list[index],key,compareFunc)==NULL)
    listAdd(&table->list[index],newItem);
  }
}

void *_hashMapSearch(HashTable *table,uint32_t key,int index,Compare compareFunc){
  return listSearch(&table->list[index],key,compareFunc);
}

void *_hashMapRemove(HashTable *table, uint32_t key, int index, Compare compareFunc){
  return listRemove1(&table->list[index],key,compareFunc);

  //Free some memory
}

uint32_t hashUsingModulo(uint32_t value,uint32_t range){
  return value % range;
}
// void hashMapAddInteger(HashTable *table, int data){
//   //Compute hash hashValue
//   //hashValue = hash(...)
//   uint32_t hashValue = hashUsingModulo(data,table->size);
//   _hashMapAdd(table,(void*)data,hashValue);
//   //_hashMapAdd(table,data,hashValue)
// }
//
// void hashMapSearch(HashTable *table,uint32_t key){
//   //Compute hash hashValue
//   //hashValue = hash(...)
//
//   //_hashMapSearch(table,data,hashValue,integerCompare)
// }
//
// void hashMapRemove(HashTable *table, uint32_t key){
//   //Compute hash hashValue
//   //hashValue = hash(...)
//
//   //_hashMapRemove(table,data,hashValue,integerCompare)
// }
