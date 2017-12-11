#ifndef _HASHMAPINTEGER_H
#define _HASHMAPINTEGER_H
#include "Data.h"
#include "Compare.h"
#include "HashMap.h"
int integerKeyCompare(uint32_t key,Data *data);
void *hashMapRemoveInteger(HashTable *table, uint32_t key, int index);
void *hashMapSearchInteger(HashTable *table,uint32_t key,int index);
void hashMapAddInteger(HashTable *table,uint32_t key, char *data, int index);

#endif // _HASHMAPINTEGER_H
