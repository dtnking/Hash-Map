#ifndef _HASHMAPSTRING_H
#define _HASHMAPSTRING_H

#include "HashMap.h"

void hashMapAddString(HashTable *table,uint32_t key, char *data, int index);
void *hashMapSearchString(HashTable *table,uint32_t key,int index);
void *hashMapRemoveString(HashTable *table, uint32_t key, int index);
#endif // _HASHMAPSTRING_H
