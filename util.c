#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

LinkedList createList() {
	LinkedList *list;
	list = malloc(sizeof(LinkedList));
	list->count = 0;
	list->head = NULL;
	list->tail = NULL;
	return *list;
}

Node* create_node(void* data){
	Node *n; 
	n = malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	return n;
}

int add_to_list(LinkedList* list,Node* s) {
	if(!s)return 0;
	if(list->head==NULL){
		list->head = s;
	}
	else
		list->tail->next = s;
	list->tail = s;
	list->count++;
}

void *get_first_element(LinkedList list) {
	return list.head->data;	
}

void *get_last_element(LinkedList list) {
	return list.tail->data;	
}

void traverse(LinkedList list, void (*f)(void* data)) {
	Node* traverser;
	for(traverser = list.head;traverser!=NULL;traverser = traverser->next) {
		f(traverser->data);
	}
}

void *getElementAt(LinkedList list, int index) {
	Node* traverser;
	int count = 0;
	if(index > list.count || index<0) return NULL;
	for(traverser = list.head;traverser!=NULL;traverser = traverser->next,count++) {
		if(count == index)
			return traverser->data;
	}	
}

int indexOf(LinkedList list,void* data) {
	Node* traverser;
	int count = 0;
	for(traverser = list.head;traverser!=NULL;traverser = traverser->next,count++) {
		if(memcmp(traverser->data,data,sizeof((void*)data))==0)
			return count;
	}
	return -1;
}

void *deleteElementAt(LinkedList* list, int index) {
	Node *traverser;
	void *tmp;
	int count = 0;
	list->count-=1;
	if(list->count < index || index < 0)return NULL;
	for(traverser = list->head;traverser!=NULL;traverser = traverser->next,count++) {
		if(index == 0){
			tmp = list->head->data;
			list->head = list->head->next;
			traverser->next = NULL;
			return tmp;
		}
		if(count == list->count-1){
			tmp = traverser->next->data;
			traverser->next = NULL;
			list->tail = traverser;
			return tmp;
		}
		if(count == index-1) {
			tmp = traverser->next->data;
			traverser->next = traverser->next->next;
			return tmp;
		}
	}	
}

int asArray(LinkedList list, void** arr) {
	Node *traverser;
	int count = 0;
	for(traverser = list.head;traverser!=NULL;traverser = traverser->next,count++) {
		arr[count] = traverser->data;
	}
	return (!list.head) ? 0 : count;	
}

LinkedList *filter(LinkedList list, int (*f)(void *)) {
	Node *traverser,*n1;
	LinkedList *newList = calloc(sizeof(LinkedList),1);
	for(traverser = list.head;traverser!=NULL;traverser = traverser->next) {
		if(f(traverser->data)) {
			n1 = create_node(traverser->data);
			add_to_list(newList,n1);
		}
	}	
	return newList; 
}




