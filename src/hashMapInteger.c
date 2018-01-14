#include "hashMapInteger.h"

CEXCEPTION_T ex;

int integerKeyCompare(uint32_t key,Data *data){
  return key == data->key;
}

void hashMapAddInteger(HashTable *table,uint32_t key, int data){
  Try{
    int hashIndex = hashUsingModulo(key,table->size);
    if(data == (intptr_t)NULL){
        Throw(createException("Data to be added cannot be NULL", HASH_DATA_NULL));
    }else{
      Data *dataVal = dataCreate(key,(void *)(intptr_t)data);
      _hashMapAdd(table,key,dataVal,hashIndex,(Compare)integerKeyCompare);
    }
  }Catch(ex){
    Throw(ex);
 }
}

void *hashMapSearchInteger(HashTable *table,uint32_t key){
  Try{
    return _hashMapSearch(table, key,hashUsingModulo(key,table->size),(Compare)integerKeyCompare);
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
