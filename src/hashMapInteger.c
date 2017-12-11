#include "hashMapInteger.h"


int integerKeyCompare(uint32_t key,Data *data){
  return key == data->key;
}

void hashMapAddInteger(HashTable *table,uint32_t key, char *data, int index){
  _hashMapAdd(table,key,data,hashUsingModulo(key,table->size),(Compare)integerKeyCompare);
}

void *hashMapSearchInteger(HashTable *table,uint32_t key,int index){
  _hashMapSearch(table, key,hashUsingModulo(key,table->size),(Compare)integerKeyCompare);
}

void *hashMapRemoveInteger(HashTable *table, uint32_t key, int index){
  _hashMapRemove(table, key,hashUsingModulo(key,table->size),(Compare)integerKeyCompare);
}
