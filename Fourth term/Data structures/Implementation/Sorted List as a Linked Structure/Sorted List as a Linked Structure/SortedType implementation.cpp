#include<iostream>
#include"SortedType.h"
#include"NodeType.h"
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item,
	bool& found)
{
	bool moreToSearch;
	NodeType<ItemType>* location;
	location = listData;
	found = false;
	moreToSearch = (location != NULL);
	while (moreToSearch && !found)
	{
		if (location->info < item)
		{
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else if (item == location->info)
		{
			found = true;
			item = location->info;
		}
		else
			moreToSearch = false;
	}
}
template <class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
	NodeType<ItemType>* newNode; // Pointer to node being inserted.
	NodeType<ItemType>* predLoc; // Trailing pointer.
	NodeType<ItemType>* location; // Traveling pointer.
	bool moreToSearch;
	location = listData;
	predLoc = NULL;
	moreToSearch = (location != NULL);
	// Find insertion point.
	while (moreToSearch)
	{
		if (location->info < item)
		{
			predLoc = location;
			location = location->next;
			moreToSearch = (location != NULL);
		}
		else
			moreToSearch = false;
	}
	// Prepare node for insertion.
	newNode = new NodeType<ItemType>;
	newNode->info = item;
	// Insert node into list.
	if (predLoc == NULL) // Insert as first.
	{
		newNode->next = listData;
		listData = newNode;
	}
	else
	{
		newNode->next = location;
		predLoc->next = newNode;
	}
	length++;
}
template <class ItemType>
SortedType<ItemType>::SortedType() // Class constructor.
{
	length = 0;
	listData = NULL;
}
template<class ItemType>
bool SortedType<ItemType>::IsFull() const
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
int SortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
	return length;
}
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
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
void SortedType<ItemType>::DeleteItem(ItemType item)
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
void SortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
	currentPos = NULL;
}
template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
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