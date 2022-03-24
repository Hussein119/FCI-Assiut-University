#include <bits/stdc++.h>
using namespace std; 
// Define the default capacity of the stack
#define SIZEStack 10
// Define the default capacity of a queue
#define SIZEQueue 1000
template <class ListItemType>
// Array-based list implementation
class AList {
    ListItemType* listArray;            // ( pointer ) Array holding list elements
    static const int DEFAULT_SIZE = 10; // Default size
    int maxSize;                        // Maximum size of list
    int listSize;                       // Current # of list items
    int curr;                           // Position of current element
public:
    // Constructors
    // Create a new list object with maximum size "size"
    AList(int size = DEFAULT_SIZE) : listSize(0), curr(0) {
        maxSize = size;
        listArray = new ListItemType[size];         // Create listArray
    }
    ~AList() { delete[] listArray; }      // destructor to remove array
    // Reinitialize the list
    void clear() { listSize = curr = 0; }  // Simply reinitialize values
    // Insert "it" at current position
    bool insert(const ListItemType& it) {
        if (listSize >= maxSize) return false;
        for (int i = listSize; i > curr; i--)  // Shift elements up
            listArray[i] = listArray[i - 1];       // to make room
        listArray[curr] = it;
        listSize++;                            // Increment list size
        return true;
    }
    // Append "it" to list
    bool append(const ListItemType& it) {
        if (listSize >= maxSize) return false;
        listArray[listSize++] = it;
        return true;
    }
    // Remove and return the current element
    ListItemType remove() {
        if ((curr < 0) || (curr >= listSize)) // No current element
            throw std::out_of_range("remove() in AList has current of " + to_string(curr) + " and size of "
                + to_string(listSize) + " that is not a a valid element");
        ListItemType it = listArray[curr];     // Copy the element
        for (int i = curr; i < listSize - 1; i++) // Shift them down
            listArray[i] = listArray[i + 1];
        listSize--;                            // Decrement size
        return it;
    }
    void moveToStart() { curr = 0; }       // Set to front
    void moveToEnd() { curr = listSize; }  // Set at end
    void prev() { if (curr != 0) curr--; } // Move left
    void next() { if (curr < listSize) curr++; } // Move right
    int length() { return listSize; }      // Return list size
    int currPos() { return curr; }         // Return current position
    // Set current list position to "pos"
    bool moveToPos(int pos) {
        if ((pos < 0) || (pos > listSize)) return false;
        curr = pos;
        return true;
    }
    // Return true if current position is at end of the list
    bool isAtEnd() { return curr == listSize; }
    // Return the current element
    ListItemType getValue() {
        if ((curr < 0) || (curr >= listSize)) // No current element
            throw std::out_of_range("getvalue() in AList has current of " + to_string(curr) + +" and size of "
                + to_string(listSize) + " that is not a a valid element");
        return listArray[curr];
    }
    // Check if the list is empty
    bool isEmpty() { return listSize == 0; }
};
template <class ListItemType>
// A class to represent a stack 
class Stack {
    ListItemType* arr;
    ListItemType top; 
    int Stackcapacity;
public : 
    Stack(int Stacksize) {
        arr = new ListItemType[Stacksize];
        Stackcapacity = Stacksize;
        top = -1; 
    }
    ~Stack() {
        delete[] arr; 
    }
    void push(ListItemType it) {
        if (isFull()) {
            cout << " Overflow \n ";
            return; 
        }
        cout << "Inserting : " << it << endl;
        arr[++top] = it; 
    }
    int pop() {
        if (isEmpty()) {
            cout << " Underflow \n";
            return 0; 
        }
        cout << " Removing " << peek() << endl;
        return arr[top--]; 
    }
    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        return 0; 
    }
    int size() {
        return top + 1;  // Zero based 
    }
    bool isEmpty() {
        return size() == 0; 
    }
    bool isFull() {
        return size() == Stackcapacity;
    }
};
template <class ListItemType>
// A class to store a queue
class Queue {
    ListItemType* arr; 
    int Queuecapacity;
    int head; 
    int tail; 
    int count; 
public : 
    Queue(int Queuesize ) {
        arr = new ListItemType[Queuesize];
        Queuecapacity = Queuesize; 
        head = 0; 
        tail = -1;
        count = 0; 
    }
    ~Queue() {
        delete[] arr; 
    }
    void enqueue(ListItemType it ) {
        if (isFull()) {
            cout << "Overflow \n ";
            return; 
        }
        //cout << "Inserting : " << it << endl; 
        tail = (tail + 1) % Queuecapacity; 
        arr[tail] = it; 
        count++; 
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Underflow" << endl; 
            return 0; 
        }
        ListItemType temp = arr[head];
       // cout << "Removing " << temp << endl;
        head = (head + 1) % Queuecapacity; 
        count--; 
        return temp; 
    }
    int peek() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return 0; 
        }
        return arr[head]; 
    }
    int size() {
        return count; 
    }
    bool isEmpty() {
        return size() == 0; 
    }
    bool isFull() {
        return size() == Queuecapacity;
    }
};
int main()
{

   
    



    return 0; 
}

