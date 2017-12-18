#ifndef _HASHMAPINTEGER_H
#define _HASHMAPINTEGER_H
#include "Data.h"
#include "Compare.h"
#include "HashMap.h"
#include "CException.h"
#include "Exception.h"
int integerKeyCompare(uint32_t key,Data *data);
void hashMapRemoveInteger(HashTable *table, uint32_t key);
void *hashMapSearchInteger(HashTable *table,uint32_t key);
void hashMapAddInteger(HashTable *table,uint32_t key, int data);

#endif // _HASHMAPINTEGER_H
