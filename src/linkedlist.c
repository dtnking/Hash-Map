#include <stdio.h>
#include "linkedlist.h"

#include <string.h>

void listInit(LinkedList *list){
	list->head=NULL;
	list->tail=NULL;
	list->len=0;
	}


void listAdd(LinkedList *list,Item *item,uint32_t key,Compare compareFunc){
	Item *temp;
	for(temp = list->head; temp!=NULL;temp = temp->next){
		if(compareFunc((void *)key,(void *)&(((Data *)(temp->data))->key))!=NULL)
			((Data *)(temp->data))->name =((Data *)(item->data))->name;
		}

		if(list->len==0){
			list->head=item;
			list->tail=item;
			list->len=1;
			item->next=NULL;
		}
		else{
			list->tail->next=item;
			list->len+=1;
			list->tail=item;
			item->next=NULL;
	}
}


void *listSearch(LinkedList *list,uint32_t key,Compare compareFunc){
	Item *temp;
	for(temp = list->head; temp!=NULL;temp = temp->next)
		if(compareFunc((void *)key,(void *)&(((Data *)(temp->data))->key)))
			return temp->data;
}

void *listRemove(LinkedList *list,uint32_t key,Compare compareFunc){
	Item *cur = list->head;
	Item *prev = NULL;

	if(list->head==NULL)
		return NULL;

	else{
		while(compareFunc((void *)key,(void *)&(((Data *)(cur->data))->key))!=NULL){
			prev = cur;
			cur = cur->next;
			}

	/*
	 * remove the first data...
	 */
			if(cur==list->head){
				if(list->head==list->tail){		// if only one data...
					listInit(list);
				}
				else{							// more than one data..
					cur = cur->next;
					list->head = cur;
					list->len--;
					}
			}

	/*
	 * remove the last data...
	 */
			else if(cur == list->tail){
				list->tail=prev;
				prev->next=NULL;
				list->len--;
				}

	/*
	* remove the middle data...
	*/
			else{
				prev->next=cur->next;
				list->len--;
				}
			return cur->data;
		}
}



void createNew(Item *item,void *data,Item *next){
	item->data = data;
	item->next = next;
}
