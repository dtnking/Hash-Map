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

/*    index
 *    [0]                     add key 1         [0]
 *    [1]--------- NULL      of value 5         [1]----------- 1
 *    [2]                    ---------->        [2]            \
 *                                                             5
 */
void test_hashMapAddInteger_given_empty_hash_table_add_value_5_expect_5_is_inserted(void){
  Data *data;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  hashMapAddInteger(&hashTable,1,5);
  TEST_ASSERT_NOT_NULL(hashTable.list[1].head);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].tail->data->name);
}


/*    index
 *    [0]                     add key 11        [0]
 *    [1]--------- 1          of value 2        [1]----------- 1 -------- 11
 *    [2]          \         ---------->        [2]            \           \
 *                 5                                           5           2
 */
void test_hashMapAddInteger_given_hash_table_5_add_value_2_expect_2_is_inserted(void){
  Data *data;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  hashMapAddInteger(&hashTable,1,5);
  hashMapAddInteger(&hashTable,11,2);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(hashTable.list[1].tail,hashTable.list[1].head->next);
  TEST_ASSERT_EQUAL(2,hashTable.list[1].tail->data->name);
}


/*    index
 *    [0]                     add key 1
 *    [1]--------- NULL       of value NULL
 *    [2]                     ---------->           Error Code = 1
 *
 */
void test_hashMapAddInteger_given_add_data_is_NULL_expected_error_Code_1(void){
  Data *data;
  HashTable hashTable;
  Try{
  hashMapInit(&hashTable,10);
  hashMapAddInteger(&hashTable,1,(intptr_t)NULL);

  }Catch(ex){
    TEST_ASSERT_EQUAL(1,ex->errorCode);
    dumpException(ex);
  }
}

/*    index
 *    [0]                           add key 11          [0]
 *    [1]--------- 1  ----- 11      of value 7          [1]----------- 1 --------- 11
 *    [2]          \        \       ---------->         [2]            \            \
 *                 5         2                                         5            7
 */
void test_hashMapAddInteger_given_same_key_expected_data_replaced_with_the_latest_one(void){
  Data *data;
  HashTable hashTable;
  hashMapInit(&hashTable,10);
  hashMapAddInteger(&hashTable,1,5);
  hashMapAddInteger(&hashTable,11,2);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(2,hashTable.list[1].tail->data->name);

  hashMapAddInteger(&hashTable,11,7) ;
  TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(7,hashTable.list[1].tail->data->name);
}

/*    index
 *    [0]
 *    [1]--------- 1  ----- 11 -----21       search key 1
 *    [2]          \        \        \        ---------->       return 5
 *                 5         3       9
 */
void test_hashMapSearchInteger_search_for_key_1_expected_return_5(void){
  HashTable hashTable;
  Data *data;
  hashMapInit(&hashTable,10);

  hashMapAddInteger(&hashTable,1,5);
  hashMapAddInteger(&hashTable,11,3);
  hashMapAddInteger(&hashTable,21,9);

  data = (Data*)hashMapSearchInteger(&hashTable,1);
  TEST_ASSERT_EQUAL(data->name,5);
}

/*    index
 *    [0]
 *    [1]--------- 1  ----- 11 -----21       search key 11
 *    [2]          \        \        \        ---------->       return 3
 *                 5         3       9
 */
void test_hashMapSearchInteger_search_for_key_11_expected_return_3(void){
  HashTable hashTable;
  Data *data;
  hashMapInit(&hashTable,10);

  hashMapAddInteger(&hashTable,1,5);
  hashMapAddInteger(&hashTable,11,3);
  hashMapAddInteger(&hashTable,21,9);

  data = (Data*)hashMapSearchInteger(&hashTable,11);
  TEST_ASSERT_EQUAL(data->name,3);

  data = (Data*)hashMapSearchInteger(&hashTable,21);
  TEST_ASSERT_EQUAL(data->name,9);
}

/*    index
 *    [0]
 *    [1]--------- 1  ----- 11 -----21       search key 21
 *    [2]          \        \        \        ---------->       return 9
 *                 5         3       9
 */
void test_hashMapSearchInteger_search_for_key_21_expected_return_9(void){
  HashTable hashTable;
  Data *data;
  hashMapInit(&hashTable,10);

  hashMapAddInteger(&hashTable,1,5);
  hashMapAddInteger(&hashTable,11,3);
  hashMapAddInteger(&hashTable,21,9);

  data = (Data*)hashMapSearchInteger(&hashTable,21);
  TEST_ASSERT_EQUAL(data->name,9);
}

/*    index
 *    [0]
 *    [1]--------- 1  ----- 11 -----21       search key 30
 *    [2]          \        \        \        ---------->       Exception code 3
 *                 5         3       9
 */
void test_hashMapSearchInteger_search_for_NULL_expected_error_code_3(void){
  HashTable hashTable;
  Data *data;
  hashMapInit(&hashTable,10);

  Try{
    hashMapAddInteger(&hashTable,1,5);
    hashMapAddInteger(&hashTable,11,3);
    hashMapAddInteger(&hashTable,21,9);
    data = (Data*)hashMapSearchInteger(&hashTable,30);
   }Catch(ex){
     TEST_ASSERT_EQUAL(3,ex->errorCode);
     dumpException(ex);
   }
}

/*    index
 *    [0]                                                       [0]
 *    [1]--------- 1  ----- 11 -----21       remove key 1       [1]-----------11-------21
 *    [2]          \        \        \        ---------->       [2]           \         \
 *                 5         3       9                                        3         9
 */
void test_hashMapRemoveInteger_given_key1_11_21_remove_key_1(void){
  HashTable hashTable;
  Data *data;
  hashMapInit(&hashTable,10);

  hashMapAddInteger(&hashTable,1,5);
  hashMapAddInteger(&hashTable,11,3);
  hashMapAddInteger(&hashTable,21,9);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(9,hashTable.list[1].tail->data->name);

  hashMapRemoveInteger(&hashTable,1);
  TEST_ASSERT_EQUAL(3,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(9,hashTable.list[1].tail->data->name);
}

/*    index
 *    [0]                                                       [0]
 *    [1]--------- 1  ----- 11 -----21       remove key 11      [1]-----------1-------21
 *    [2]          \        \        \        ---------->       [2]           \         \
 *                 5         3       9                                        5         9
 */
void test_hashMapRemoveInteger_given_key1_11_21_remove_key_11(void){
  HashTable hashTable;
  Data *data;
  hashMapInit(&hashTable,10);

  hashMapAddInteger(&hashTable,1,5);
  hashMapAddInteger(&hashTable,11,3);
  hashMapAddInteger(&hashTable,21,9);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(9,hashTable.list[1].tail->data->name);

  hashMapRemoveInteger(&hashTable,11);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(9,hashTable.list[1].tail->data->name);
}

/*    index
 *    [0]                                                       [0]
 *    [1]--------- 1  ----- 11 -----21       remove key 21      [1]-----------1-------11
 *    [2]          \        \        \        ---------->       [2]           \         \
 *                 5         3       9                                        5         3
 */
void test_hashMapRemoveInteger_given_key1_11_21_remove_key_21(void){
  HashTable hashTable;
  Data *data;
  hashMapInit(&hashTable,10);

  hashMapAddInteger(&hashTable,1,5);
  hashMapAddInteger(&hashTable,11,3);
  hashMapAddInteger(&hashTable,21,9);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(9,hashTable.list[1].tail->data->name);

  hashMapRemoveInteger(&hashTable,21);
  TEST_ASSERT_EQUAL(5,hashTable.list[1].head->data->name);
  TEST_ASSERT_EQUAL(3,hashTable.list[1].tail->data->name);
}
