#include "stack.h"
#include <stdio.h>

Stack createStack(void) {
	LinkedList*  list= calloc(sizeof(LinkedList),1);
	Stack stack = {list,&list->tail};
	return stack;
}

int push(Stack stack, void* data) {
	Node* element = create_node(data);
	int task = add_to_list(stack.stack,element);
	stack.top = stack.stack->tail;
	return (task) ? stack.stack->count : -1;
}
	
void* pop(Stack stack) {
	void* result = deleteElementAt(stack.stack,stack.stack->count-1);
	stack.top = stack.stack->tail;
	return result;	
}