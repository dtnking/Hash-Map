#include "Data.h"
#include <malloc.h>
#include <stdint.h>
#include <stdio.h>

Data *dataCreate(uint32_t key,void *name){
  Data *data = (Data *)malloc(sizeof(Data));
  data->key = key;
  data->name = name;
  return data;
}
