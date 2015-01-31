#include "Stack.h"
#include "expr_assert.h"
#include <stdio.h>
#include <stdlib.h>

#define log(test_description) int log = printf("**  Description->%s\n\n", test_description)

void test_createStack_001() {
	log("creates an empty stack");
	Stack stack = createStack();
	LinkedList tmp = {NULL,NULL,0};
	assertEqual(stack.stack->head,tmp.head);
	assertEqual(stack.stack->count,tmp.count);
	assertEqual(stack.stack->tail,tmp.tail);
	assertEqual(*(stack.top),NULL);
	free(stack.stack);
	stack.top = NULL;
}

void test_push_001() {
	log("Pushes an integer element to a stack");
	Stack stack = createStack();
	int data = 24,data1 = 23,res;
	res = push(stack,&data);
	assertEqual(res,1);
	assertEqual(*((int *)(*(stack.top))->data),24);
	res = push(stack,&data1);
	assertEqual(res,2);
	assertEqual(*((int *)(*(stack.top))->data),23);
	free(stack.stack);
	stack.top = NULL;
}

void test_push_002() {
	log("Returns -1 for empty node");
	Stack stack = createStack();
	int data = NULL,res;
	res = push(stack,&data);
	assertEqual(res,-1);
	free(stack.stack);
	stack.top = NULL;
}

void test_pop_001() {
	log("Pops an integer element from the top of a stack");
	Stack stack = createStack();
	int data = 24,data1 = 23,res;
	void* result;
	res = push(stack,&data);
	assertEqual(res,1);
	assertEqual(*((int *)(*(stack.top))->data),24);
	res = push(stack,&data1);
	assertEqual(res,2);
	assertEqual(*((int *)(*(stack.top))->data),23);
	result = pop(stack);
	assertEqual(stack.stack->count,1);
	assertEqual(*((int *)(*(stack.top))->data),24);
	free(stack.stack);
	stack.top = NULL;
}

void test_pop_002() {
	log("Pop gives NULL for empty stack");
	Stack stack = createStack();
	void* res;
	res = pop(stack);
	assertEqual(res,NULL);
}



