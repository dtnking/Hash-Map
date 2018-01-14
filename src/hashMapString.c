#include "hashMapString.h"


CEXCEPTION_T ex;
int stringKeyCompare(uint32_t key,Data *data){
  return key == data->key;
}

void hashMapAddString(HashTable *table,uint32_t key, char *data){
  Try{
    int hashIndex = hashUsingModulo(key,table->size);
    if(data == (void *)(intptr_t)NULL){
      Throw(createException("Data to be added cannot be NULL", HASH_DATA_NULL));
    }else{
      Data *dataVal = dataCreate(key,data);
      _hashMapAdd(table,key,dataVal,hashIndex,(Compare)stringKeyCompare);
    }
  }Catch(ex){
      Throw(ex);
 }
}

void *hashMapSearchString(HashTable *table,uint32_t key){
  Try{
    return _hashMapSearch(table,key,hashUsingModulo(key,table->size),(Compare)stringKeyCompare);
  }Catch(ex){
    Throw(ex);
  }
}

void *hashMapRemoveString(HashTable *table, uint32_t key){
  Try{
    _hashMapRemove(table,key,hashUsingModulo(key,table->size),(Compare)stringKeyCompare);
  }Catch(ex){
    Throw(ex);
  }
}
