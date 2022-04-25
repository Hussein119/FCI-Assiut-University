#include"StackType.h"
template<class ItemType>
StackType<ItemType>::StackType(int size){
	items = new ItemType[size];
	Stackcapacity = size;
	top = -1;
}
template<class ItemType>
StackType<ItemType>::StackType(){
	items = new ItemType[MAX_ITEMS];
	Stackcapacity = MAX_ITEMS;
	top = -1;
}
template<class ItemType>
StackType<ItemType>::~StackType(){
	delete[] items;
}
template<class ItemType>
bool StackType<ItemType>::IsEmpty() const{
	return (top == -1);
}
template<class ItemType>
bool StackType<ItemType>::IsFull() const{
	return (top == MAX_ITEMS - 1);
}
template<class ItemType>
void StackType<ItemType>::Push(ItemType newItem){
	if (IsFull())
		throw FullStack();
	top++;
	items[top] = newItem;
}
template<class ItemType>
void StackType<ItemType>::Pop(){
	if (IsEmpty())
		throw EmptyStack();
	top--;
}
template<class ItemType>
ItemType StackType<ItemType>::Top() const{
	if (IsEmpty())
	   throw EmptyStack();
	return items[top];
}