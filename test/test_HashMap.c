#include "unity.h"
#include "HashMap.h"
#include "linkedlist.h"
#include "IntegerCompare.h"

void setUp(void){}

void tearDown(void){}

void test__hashMapAdd_given_empty_hash_table_and_value3_is_added_expect_3(void){
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  _hashMapAdd(&hashTable,5,5);
  TEST_ASSERT_EQUAL(5,(int)(hashTable.list[5]->head->data));
}
