#include "hashMapInteger.h"

CEXCEPTION_T ex;

int integerKeyCompare(uint32_t key,Data *data){
  return key == data->key;
}

void hashMapAddInteger(HashTable *table,uint32_t key, int data){
  Try{
    int hashIndex = hashUsingModulo(key,table->size);
    Data *dataVal = dataCreate(key,data);
    _hashMapAdd(table,key,dataVal,hashIndex,(Compare)integerKeyCompare);
  }Catch(ex){
    Throw(ex);
 }
}

void *hashMapSearchInteger(HashTable *table,uint32_t key){
  Try{
    _hashMapSearch(table, key,hashUsingModulo(key,table->size),(Compare)integerKeyCompare);
  }Catch(ex){
    Throw(ex);
  }
}

void hashMapRemoveInteger(HashTable *table, uint32_t key){
  Try{
    _hashMapRemove(table, key,hashUsingModulo(key,table->size),(Compare)integerKeyCompare);
  }Catch(ex){
    Throw(ex);
  }
}
