#include "hashMapString.h"


CEXCEPTION_T ex;
int compareString(char *str,char *strRef){
  return !strcmp(str,strRef);
}
void hashMapAddString(HashTable *table,uint32_t key, char *data){
  Try{
    _hashMapAdd(table,key,data,hashUsingModulo(key,table->size),(Compare)compareString);
  }Catch(ex){
      Throw(ex);
 }
}

void *hashMapSearchString(HashTable *table,uint32_t key){
  Try{
    _hashMapSearch(table,key,hashUsingModulo(key,table->size),(Compare)compareString);
  }Catch(ex){
    Throw(ex);
  }
}

void *hashMapRemoveString(HashTable *table, uint32_t key){
  Try{
    _hashMapRemove(table,key,hashUsingModulo(key,table->size),(Compare)compareString);
  }Catch(ex){
    Throw(ex);
  }
}
