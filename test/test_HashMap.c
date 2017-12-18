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


void test__hashMapAdd_given_empty_hash_table_and_value_5_is_addded_expect_5_is_inserted(void){
  Data *data;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  data = dataCreate(5,"David");
  _hashMapAdd(&hashTable,5,(void *)data, 7,(Compare)integerKeyCompare);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);
  free(data);
}


void test__hashMapAdd_given_value_5_and_3_are_added_expect_the_data_in_the_list_at_index_7(void){
  Data *data,*david,*ali;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  david = dataCreate(5,"David");
  _hashMapAdd(&hashTable,5,(void *)david, 7,(Compare)integerKeyCompare);
  ali = dataCreate(3,"Ali");
  _hashMapAdd(&hashTable,3,(void *)ali, 7,(Compare)integerKeyCompare);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head->next);
  data = (Data *)(hashTable.list[7].head->next->data);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);
  free(david);
  free(ali);
}

void test__hashMapSearch_given_5_3_then_search_3_expected_3_return(void){
  Data *data,*david,*ali;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  david = dataCreate(5,"David");
  _hashMapAdd(&hashTable,5,(void *)david, 7,(Compare)integerKeyCompare);
  ali = dataCreate(3,"Ali");
  _hashMapAdd(&hashTable,3,(void *)ali, 7,(Compare)integerKeyCompare);


  data = (Data*)_hashMapSearch(&hashTable,3,7,(Compare)integerKeyCompare);
  TEST_ASSERT_NOT_NULL(data);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);
  free(david);
  free(ali);

}

void test__hashMapRemove_given_5_3_then_remove_3_expected_3_removed(void){
  Data *data,*david,*ali;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  david = dataCreate(5,"David");
  _hashMapAdd(&hashTable,5,(void *)david, 7,(Compare)integerKeyCompare);
  ali = dataCreate(3,"Ali");
  _hashMapAdd(&hashTable,3,(void *)ali, 7,(Compare)integerKeyCompare);

  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NOT_NULL(data);
  data = (Data*)_hashMapRemove(&hashTable,3,7,(Compare)integerKeyCompare);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);
  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NULL(data);
  free(david);
  free(ali);
}
