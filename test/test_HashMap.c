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

CEXCEPTION_T ex;

void test__hashMapAdd_given_index_larger_than_table_size_expected_error_Code_0(void){
  Data *data;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  data =dataCreate(5,"David");

  Try{
  _hashMapAdd(&hashTable,5,(void *)data, 11,(Compare)integerKeyCompare);
  }Catch(ex){
    dumpException(ex);
    TEST_ASSERT_EQUAL(0,ex->errorCode);
  }

}

void test__hashMapAdd_given_empty_hash_table_and_value_5_is_addded_expect_5_is_inserted(void){
  Data *data;
  HashTable hashTable;
  hashMapInit(&hashTable,10);

  data = dataCreate(5,"David");
  Try{
  _hashMapAdd(&hashTable,5,(void *)data, 7,(Compare)integerKeyCompare);
  }Catch(ex){
    dumpException(ex);
  }
  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);
  free(data);

}

void test__hashMapAdd_given_add_data_is_NULL_expected_error_Code_1(void){
  Data *data;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  data = NULL;

  Try{
  _hashMapAdd(&hashTable,5,(void *)data, 7,(Compare)integerKeyCompare);
  }Catch(ex){
    dumpException(ex);
    TEST_ASSERT_EQUAL(1,ex->errorCode);
  }

}

/*
*     index  ------
*            |    |
*            |    |
*       7    |  * | -->5->3
*            |    |
*            |    |
*/
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

/*    index
 *    [0]                                               [0]
 *    [1]                                               [1]
 *     .                                                 .
 *     .                                                 .
 *    [7]--------- 5  ----- 3        remove key 3       [7]    -----------5
 *    [8]          \        \        ---------->        [8]                \
 *             "David"     "Ali"                                         "David"
 *
 */
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

/*    index
 *    [0]                                               [0]
 *    [1]                                               [1]
 *     .                                                 .
 *     .                                                 .
 *    [7]--------- 5  ----- 3        remove key 5       [7]    -----------3
 *    [8]          \        \        ---------->        [8]                \
 *             "David"     "Ali"                                         "Ali"
 *
 */
void test__hashMapRemove_given_5_3_then_remove_5_expected_5_removed(void){
  Data *data,*david,*ali;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  david = dataCreate(5,"David");
  _hashMapAdd(&hashTable,5,(void *)david, 7,(Compare)integerKeyCompare);
  ali = dataCreate(3,"Ali");
  _hashMapAdd(&hashTable,3,(void *)ali, 7,(Compare)integerKeyCompare);

  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NOT_NULL(data);
  data = (Data*)_hashMapRemove(&hashTable,5,7,(Compare)integerKeyCompare);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);
  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NULL(data);
  TEST_ASSERT_EQUAL_STRING("Ali",hashTable.list[7].head->data->name);
  free(david);
  free(ali);
}

/*    index
 *    [0]                                                        [0]
 *    [1]                                                        [1]
 *     .                                                          .
 *     .                                                          .
 *    [7]--------- 5  ----- 3 ------ 2        remove key 5       [7]    ----------- 5---------2
 *    [8]          \        \        \        ---------->        [8]                \          \
 *             "David"     "Ali"    "Abu"                                         "David"     "Abu"
 *
 */
void test__hashMapRemove_given_5_3_2_then_remove_3_expected_3_removed(void){
  Data *data,*david,*ali,*abu;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  david = dataCreate(5,"David");
  _hashMapAdd(&hashTable,5,(void *)david, 7,(Compare)integerKeyCompare);
  ali = dataCreate(3,"Ali");
  _hashMapAdd(&hashTable,3,(void *)ali, 7,(Compare)integerKeyCompare);
  abu = dataCreate(2,"Abu");
  _hashMapAdd(&hashTable,2,(void *)abu, 7,(Compare)integerKeyCompare);

  data =  (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NOT_NULL(data);
  data = (Data*)_hashMapRemove(&hashTable,3,7,(Compare)integerKeyCompare);
  TEST_ASSERT_EQUAL(3,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  TEST_ASSERT_EQUAL_STRING("David",hashTable.list[7].head->data->name);
  TEST_ASSERT_EQUAL_STRING("Abu",hashTable.list[7].head->next->data->name);
  TEST_ASSERT_EQUAL_STRING("Abu",hashTable.list[7].tail->data->name);
  free(david);
  free(ali);
}
