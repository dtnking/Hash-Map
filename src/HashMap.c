#include "HashMap.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

void hashMapInit(HashTable *table, int size){
  table->list = (LinkedList **)calloc(size * SIZE_FACTOR , sizeof(LinkedList **));
  table->size = size;
}

void _hashMapAdd(HashTable *table, void *data, int index){

}

void _hashMapSearch(HashTable *table,void *data,int index,Compare compareFunc){

}

void _hashMapRemove(HashTable *table, void *data, int index, Compare compareFunc){


  //Free some memory
}

uint32_t hashUsingModulo(uint32_t value,uint32_t range){
  return value % range;
}
void hashMapAddInteger(HashTable *table, int data){
  //Compute hash hashValue
  //hashValue = hash(...)
  uint32_t hashValue = hashUsingModulo(data,table->size);
  _hashMapAdd(table,(void*)data,hashValue);
  //_hashMapAdd(table,data,hashValue)
}

void hashMapSearch(HashTable *table, int data){
  //Compute hash hashValue
  //hashValue = hash(...)

  //_hashMapSearch(table,data,hashValue,integerCompare)
}

void hashMapRemove(HashTable *table, int data){
  //Compute hash hashValue
  //hashValue = hash(...)

  //_hashMapRemove(table,data,hashValue,integerCompare)
}
