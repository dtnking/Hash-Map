#include "hashMapString.h"

int compareString(char *str,char *strRef){
  return !strcmp(str,strRef);
}
void hashMapAddString(HashTable *table,uint32_t key, char *data, int index){
  _hashMapAdd(table,key,data,hashUsingModulo(key,table->size),(Compare)compareString);
}

void *hashMapSearchString(HashTable *table,uint32_t key,int index){
  _hashMapSearch(table,key,data,hashUsingModulo(key,table->size),(Compare)compareString);
}

void *hashMapRemoveString(HashTable *table, uint32_t key, int index){
  _hashMapRemove(table,key,data,hashUsingModulo(key,table->size),(Compare)compareString);
}
