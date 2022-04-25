#pragma once
#include"NodeType.h"
class EmptyStack
	// Exception class used by Pop and Top when stack is empty.
{};
template<class ItemType>
class StackType
{
public:
	StackType();
	bool IsEmpty();
	void Push(ItemType item);
	void Pop();
	ItemType Top();
private:
	NodeType<ItemType>* top;
	int length;
};