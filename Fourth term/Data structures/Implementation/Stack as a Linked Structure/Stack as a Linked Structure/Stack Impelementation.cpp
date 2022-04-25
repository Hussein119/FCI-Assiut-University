#include<iostream>
#include"NodeType.h"
#include"StackType.h"
template <class ItemType>
StackType<ItemType>::StackType() {
	length = 0;
	top = NULL;
}
template <class ItemType>
bool StackType<ItemType>::IsEmpty() { 
	return (top == NULL);
}
template <class ItemType>
void StackType<ItemType> :: Push(ItemType item) {
	NodeType<ItemType>* newitem;
	newitem->data = item;
	newitem->next = top;
	top = newitem;
	length++;
}
template <class ItemType>
void StackType<ItemType> :: Pop() {
	if (IsEmpty()) throw EmptyStack();
	NodeType<ItemType>* temp = top;
	ItemType item = temp->data;
	top = top->next;
	delete temp;
	length--;
}
template <class ItemType>
ItemType StackType<ItemType>::Top(){ 
	if (IsEmpty()) throw EmptyStack();
		return (top->data); 
}
