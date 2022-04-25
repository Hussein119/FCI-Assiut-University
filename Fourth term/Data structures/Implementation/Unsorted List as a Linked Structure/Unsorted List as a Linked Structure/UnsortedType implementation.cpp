#include<iostream>
#include"UnsortedType.h"
#include"NodeType.h"
template <class ItemType>
UnsortedType<ItemType>::UnsortedType() // Class constructor.
{
	length = 0;
	listData = NULL;
}
template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
// Returns true if there is no room for another NodeType object
// on the free store and false otherwise.
{
	NodeType<ItemType>* location;
	try
	{
		location = new NodeType<ItemType>;
		delete location;
		return false;
	}
	catch (std::bad_alloc exception)
	{
		return true;
	}
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
	return length;
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
	NodeType<ItemType>* tempPtr;
	while (listData != NULL)
	{
		tempPtr = listData;
		listData = listData->next;
		delete tempPtr;
	}
	length = 0;
}
template <class ItemType>
void UnsortedType<ItemType>::RetrieveItem(ItemType& item,
	bool& found)
	// Pre: Key member(s) of item is initialized.
	// Post: If found, item's key matches an element's key in the
	// list and a copy of that element has been stored in item;
	// otherwise, item is unchanged.
{
	bool moreToSearch;
	NodeType<ItemType>* location;
	location = listData;
	found = false;
	moreToSearch = (location != NULL);
	while (moreToSearch && !found)
	{
		if (item == location->info)
		{
			found = true;
			item = location->info;
		}
		else
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
	}
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
// item is in the list; length has been incremented.
{
	NodeType<ItemType>* location;
	location = new NodeType<ItemType>;
	location->info = item;
	location->next = listData;
	listData = location;
	length++;
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
// Pre: item's key has been initialized.
// An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
	NodeType<ItemType>* location = listData;
	NodeType<ItemType>* tempLocation;
	// Locate node to be deleted.
	if (item == listData->info)
	{
		tempLocation = location;
		listData = listData->next; // Delete first node.
	}
	else
	{
		while (!(item == (location->next)->info))
			location = location->next;
		// Delete node at location->next.
		tempLocation = location->next;
		location->next = (location->next)->next;
	}
	delete tempLocation;
	length--;
}
template <class ItemType>
void UnsortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
	currentPos = NULL;
}
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
// Pre: List has not been changed since last call.
// Post: A copy of the next item in the list is returned.
// When the end of the list is reached, currentPos
// is reset to begin again.
{
	if (currentPos == NULL)
		currentPos = listData;
	else
		currentPos = currentPos->next;
	item = currentPos->info;
}