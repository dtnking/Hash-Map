#include "unity.h"
#include "HashMap.h"
#include <malloc.h>
#include "linkedlist.h"
#include "Data.h"
#include "hashMapInteger.h"
#include "Exception.h"
#include "CException.h"

void setUp(void){}

void tearDown(void){}


void test_hashMapAddInteger_given_empty_hash_table_and_value_5_is_addded_expect_5_is_inserted(void){
  Data *data;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  hashMapAddInteger(&hashTable,1,5);
  TEST_ASSERT_NOT_NULL(hashTable.list[1].head);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].tail->data->name);
}

void test_hashMapAddIntege2r_given_empty_hash_table_and_value_5_is_addded_expect_5_is_inserted(void){
  Data *data;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  hashMapAddInteger(&hashTable,1,5);
  hashMapAddInteger(&hashTable,11,2);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(2,hashTable.list[1].tail->data->name);
}
void xtest_hashMapAddInteger_given_value_5_and_value_2_is_addded_expect_2_is_inserted(void){
  Data *data;
  HashTable hashTable;
  hashMapInit(&hashTable,10);

  hashMapAddInteger(&hashTable,1,5);
  hashMapAddInteger(&hashTable,11,2);
  TEST_ASSERT_NOT_NULL(hashTable.list[1].head);
  //TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data);
  //TEST_ASSERT_EQUAL(2,hashTable.list[1].tail->data);
}
