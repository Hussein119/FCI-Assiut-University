#pragma once
#include "arrayListType.h"
template <class ListItemType>
class unorderedArrayListType : public arrayListType <ListItemType> {
public:
	void removeAt(int location);
	void remove(ListItemType removeItem);
	unorderedArrayListType(int size = 100);
};
template <class ListItemType>
unorderedArrayListType <ListItemType> :: unorderedArrayListType(int size) {
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
void unorderedArrayListType<ListItemType>::remove(ListItemType removeItem)
{
	int loc;
	if (length == 0)
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
void unorderedArrayListType<ListItemType>::removeAt(int location)
{
	if (location < 0 || location >= length)
		cout << "The location of the item to be removed "
		<< "is out of range." << endl;
	else
	{
		list[location] = list[length - 1];
		length--;
	}
} //end removeAt


