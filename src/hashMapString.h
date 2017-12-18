#ifndef _HASHMAPSTRING_H
#define _HASHMAPSTRING_H
#include <string.h>
#include "HashMap.h"
#include "CException.h"
#include "Exception.h"

void hashMapAddString(HashTable *table,uint32_t key, char *data);
void *hashMapSearchString(HashTable *table,uint32_t key);
void *hashMapRemoveString(HashTable *table, uint32_t key);
#endif // _HASHMAPSTRING_H
