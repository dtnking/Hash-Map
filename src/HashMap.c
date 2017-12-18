#include "HashMap.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>
#include "Exception.h"
#include "CException.h"

CEXCEPTION_T ex;

void hashMapInit(HashTable *table, int size){
  table->list = (LinkedList *)calloc(size * SIZE_FACTOR , sizeof(LinkedList));
  table->size = size;
}

void _hashMapAdd(HashTable *table,uint32_t key, void *data, int index, Compare compareFunc){
  if(data == NULL)
    Throw(createException("Data to be added cannot be NULL", HASH_DATA_NULL));
  Item *newItem = (Item *)malloc(sizeof(Item));
  createNew(newItem,data,NULL);
  if(index < table->size)
    listAdd(&table->list[index],newItem,key,compareFunc);
  else
    Throw(createException("Index is out of bound", HASH_BOUNDARY_ERROR));
}

void *_hashMapSearch(HashTable *table,uint32_t key,int index,Compare compareFunc){
  if(index>=table->size)
    Throw(createException("Index is out of bound", HASH_BOUNDARY_ERROR));
  return listSearch(&table->list[index],key,compareFunc);
}

void *_hashMapRemove(HashTable *table, uint32_t key, int index, Compare compareFunc){
  if(index>=table->size){
    Throw(createException("Index is out of bound", HASH_BOUNDARY_ERROR));
   }
  return listRemove(&table->list[index],key,compareFunc);

  //Free some memory
}

uint32_t hashUsingModulo(uint32_t value,uint32_t range){
  return value % range;
}

// void hashMapAdd(HashTable *table,uint32_t key, void *value, int index, Compare compareFunc){
//   //Compute hash hashValue
//
//   Data *data = dataCreate(key,value);
//   int hashValue = hashUsingModulo(data->key,table->size);
//   Try{
//     _hashMapAdd(table,key,data,hashValue,compareFunc);
//   }Catch(ex){
//      Throw(ex);
//   }
// }
//
// void hashMapSearch(HashTable *table,uint32_t key,Compare compareFunc){
//   //Compute hash hashValue
//
//   int hashValue = hashUsingModulo(key,table->size);
//   _hashMapSearch(table,key,hashValue,compareFunc);
//   //_hashMapSearch(table,data,hashValue,integerCompare)
// }
//
// void hashMapRemove(HashTable *table, uint32_t key){
//   //Compute hash hashValue
//   //hashValue = hash(...)
//
//   //_hashMapRemove(table,data,hashValue,integerCompare)
// }
