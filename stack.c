#include "stack.h"
#include <stdio.h>

Stack createStack(void) {
	LinkedList*  list= calloc(sizeof(LinkedList),1);
	Stack stack = {list,&list->tail};
	return stack;
}

int push(Stack stack, void* data) {
	Node* element = create_node(data);
	if(!element) return -1;
	add_to_list(stack.stack,element);
	return stack.stack->count;
}
	
void* pop(Stack stack) {
	return deleteElementAt(stack.stack,stack.stack->count-1);
}