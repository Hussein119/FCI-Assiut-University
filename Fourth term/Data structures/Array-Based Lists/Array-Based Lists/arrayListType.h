#pragma once
template <class ListItemType>
class arrayListType {
public : 
	/*const arrayListType<ListItemType>&
		operator=(const arrayListType<ListItemType>&);*/
	//Overloads the assignment operator
	bool isEmpty() const;                        
	 //Function to determine whether the list is empty
    //Postcondition: Returns true if the list is empty;
    // otherwise, returns false.
	bool isFull() const;    
	//Function to determine whether the list is full
	//Postcondition: Returns true if the list is full;
	// otherwise, returns false.
	ListItemType listSize() const;
	//Function to determine the number of elements in the list.
	//Postcondition: Returns the value of length.
	ListItemType maxListSize() const;
	//Function to determine the maximum size of the list
	//Postcondition: Returns the value of maxSize.
	void print() const;
	//Function to output the elements of the list
	//Postcondition: Elements of the list are output on the standard output device.
	bool isItemAtEqual(int location, ListItemType item) const;
	//Function to determine whether item is the same as
	//the item in the list at the position specified
	//by location.
	//Postcondition: Returns true if list[location]
	//               is the same as item; otherwise,
	//               returns false.
	//               If location is out of range, an
	//               appropriate message is displayed.
	void insertAt(int location, ListItemType insertItem) ;
	//Function to insert insertItem in the list at the
	//position specified by location.
	//Note that this is an abstract function.
	//Postcondition: Starting at location, the elements of
	// the list are shifted down,
	// list[location] = insertItem; length++;
	// If the list is full or location is
	// out of range, an appropriate message
	// is displayed.
	void insert(ListItemType insertItem);
	// insert Item at current location 
    void insertEnd(ListItemType insertItem);
	//Function to insert insertItem at the end of
	//the list. Note that this is an abstract function.
	//Postcondition: list[length] = insertItem; and length++;
	// If the list is full, an appropriate
	// message is displayed.
	void retrieveAt(int location, ListItemType& retItem) const;
	//Function to retrieve the element from the list
	//at the position specified by location
	//Postcondition: retItem = list[location]
	// If location is out of range, an
	// appropriate message is displayed.
    void replaceAt(int location, ListItemType repItem) ;
	//Function to replace the elements in the list
	//at the position specified by location.
	//Note that this is an abstract function.
	//Postcondition: list[location] = repItem
	// If location is out of range, an
	// appropriate message is displayed.
	void clearList();
	//Function to remove all the elements from the list
	//After this operation, the size of the list is zero.
	//Postcondition: length = 0;
	ListItemType seqSearch(ListItemType searchItem) const ;
	//Function to search the list for searchItem.
	//Note that this is an abstract function.
	//Postcondition: If the item is found, returns the
	// location in the array where the item
	// is found; otherwise, returns –1.
	arrayListType(int size = 100);
	//Constructor
	//Creates an array of the size specified by the
	//parameter size. The default array size is 100.
	//Postcondition: The list points to the array,
	// length = 0, and maxSize = size;
	arrayListType(const arrayListType<ListItemType>& otherList);
	//Copy constructor
	virtual ~arrayListType();
	//Destructor
	//Deallocate the memory occupied by the array.
//protected:
	ListItemType* list; //array to hold the list elements
	int length; //variable to store the length of the list
	int maxSize; //variable to store the maximum
	//size of the list
};
using namespace std;
template <class ListItemType>
arrayListType<ListItemType>::arrayListType(int size) : length(0)
{
	if (size <= 0)
	{
		cout << "The array size must be positive. Creating an array of the size 100." << endl;
		maxSize = 100;
	}
	else
		maxSize = size;
	list = new ListItemType[maxSize];
} //end constructor
template <class ListItemType>
arrayListType<ListItemType>::~arrayListType()
{
	delete[] list;
} //end destructor
template <class ListItemType>
arrayListType<ListItemType>::arrayListType(const arrayListType<ListItemType>& otherList)
{
	maxSize = otherList.maxSize;
	length = otherList.length;
	list = new ListItemType[maxSize]; //create the array
	for (int j = 0; j < length; j++) //copy otherList
		list[j] = otherList.list[j];
}//end copy constructor
template <class ListItemType>
inline bool arrayListType<ListItemType>::isEmpty() const
{
	return (length == 0);
} //end isEmpty
template <class ListItemType>
inline bool arrayListType<ListItemType>::isFull() const
{
	return (length == maxSize);
} //end isFull
template <class ListItemType>
inline ListItemType arrayListType<ListItemType>::listSize() const
{
	return length;
}   //end listSize
template <class ListItemType>
inline ListItemType arrayListType<ListItemType>::maxListSize() const
{
	return maxSize;
} //end maxListSize
template <class ListItemType>
void arrayListType<ListItemType>::print() const
{
	for (int i = 0; i < length; i++)
		cout << list[i] << " ";
	cout << endl;
} //end print
template <class ListItemType>
bool arrayListType<ListItemType>::isItemAtEqual(int location, ListItemType item) const
{
	if ((location < 0 || location >= length))
	{
		cout << "The location of the item to be removed is out of range." << endl;
		return false;
	}
	else
		return (list[location] == item);
} //end isItemAtEqual
template <class ListItemType>
void arrayListType<ListItemType>::retrieveAt(int location, ListItemType& retItem) const
{
	if (location < 0 || location >= length)
		cout << "The location of the item to be retrieved is "
		<< "out of range" << endl;
	else
		retItem = list[location];
} //end retrieveAt
template <class ListItemType>
void arrayListType<ListItemType>::replaceAt(int location, ListItemType repItem)
{
	if (location < 0 || location >= length)
		cout << "The location of the item to be "
		<< "replaced is out of range." << endl;
	else
		list[location] = repItem;
} //end replaceAt
template <class ListItemType>
void arrayListType<ListItemType>::insertEnd(ListItemType insertItem)
{
	if (isFull()) //the list is full
		cout << "Cannot insert in a full list." << endl;
	else
	{
		list[length] = insertItem; //insert the item at the end
		length++; //increment the length
	}
} //end insertEnd
template <class ListItemType>
void arrayListType<ListItemType>::insertAt(int location, ListItemType insertItem)
{
	if (location < 0 || location >= maxSize)
		cout << "The position of the item to be inserted "
		<< "is out of range." << endl;
	else if (isFull())   //list is full
		cout << "Cannot insert in a full list. " << endl;
	else
	{
		for (int i = length; i > location; i--)
			list[i] = list[i - 1]; //move the elements down
		list[location] = insertItem; //insert the item at the specified position
		length++; //increment the length
	}
} //end insertAt
template <class ListItemType>
void arrayListType<ListItemType>::insert(ListItemType insertItem)
{
	if (length == 0) //list is empty
		list[length++] = insertItem;//insert insertItem
		//and increment length
	else if (length == maxSize)
		cout << "Cannot insert in a full list." << endl;
	else
	{
		//Find the location in the list where to insert
		//insertItem.
		int loc;
		bool found = false;
		for (loc = 0; loc < length; loc++)
		{
			if (list[loc] == insertItem)
			{
				found = true;
				break;
			}
		}
		for (int i = length; i = loc; i--)
			list[i] = list[i - 1];//move the elements down
		list[loc] = insertItem;//insert insertItem
		length++; //increment the length
	}
} //end insert
template <class ListItemType>
void arrayListType<ListItemType>::clearList()
{
	length = 0;
} //end clearList
template <class ListItemType>
ListItemType arrayListType<ListItemType>::seqSearch(ListItemType searchItem) const
{
	int loc;
	bool found = false;
	loc = 0;
	while (loc < length && !found)
		if (list[loc] == searchItem)
			found = true;
		else
			loc++;
	if (found)
		return loc;
	else
		return -1;
} //end seqSearch

