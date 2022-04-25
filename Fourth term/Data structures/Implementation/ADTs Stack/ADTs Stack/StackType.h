#pragma once
class FullStack
	// Exception class used by Push when stack is full.
{};
class EmptyStack
	// Exception class used by Pop and Top when stack is empty.
{};
template<class ItemType>
class StackType
{
public:
	StackType(int size);
	StackType();
	~StackType();
	bool IsEmpty() const;
	bool IsFull() const;
	void Push(ItemType item);
	void Pop();
	ItemType Top() const;
private:
	int top;
	int MAX_ITEMS  = 500;
	ItemType* items;
};