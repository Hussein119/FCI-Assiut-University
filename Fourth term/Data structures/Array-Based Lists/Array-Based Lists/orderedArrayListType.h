#pragma once
#include "arrayListType.h"
template <class ListItemType>
class orderedArrayListType : public arrayListType <ListItemType> {
public:
	void removeAt(int location);
	void remove(ListItemType removeItem);
	orderedArrayListType(int size = 100);
};
template <class ListItemType>
orderedArrayListType<ListItemType> ::orderedArrayListType(int size) {
	if (size <= 0)
	{
		cout << "The array size must be positive. Creating an array of the size 100." << endl;
		maxSize = 100;
	}
	else
		maxSize = size;
	length = 0;
	list = new ListItemType[maxSize];
} //end constructor
template <class ListItemType>
void orderedArrayListType<ListItemType>::remove(ListItemType removeItem)
{
	int loc;
	if (isEmpty())
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		loc = seqSearch(removeItem);
		if (loc != -1)
			removeAt(loc);
		else
			cout << "The item to be deleted is not in the list." << endl;
	}
} //end remove
template <class ListItemType>
void orderedArrayListType<ListItemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cout << "The location of the item to be removed "
		<< "is out of range." << endl;
	else
	{
		for (int i = location; i < length - 1; i++)
			list[i] = list[i + 1];
		length--;
	}
} //end removeAt


