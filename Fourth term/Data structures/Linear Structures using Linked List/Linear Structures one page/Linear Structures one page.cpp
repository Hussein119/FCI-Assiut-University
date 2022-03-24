//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
template <class ListItemType>
// singly linked list implementation ____________________________________________________________________________
class Node {
public:
	ListItemType data;
	Node* next;
	Node() {
		data = NULL;
		next = NULL;
	}
	Node(ListItemType data) {
		this->data = data;
		this->next = NULL;
	}
};
template <class ListItemType>
class Linkedlist{
public:
	Node<ListItemType>* head;
	int listSize = 0;
	Linkedlist() { head = NULL; }
	// Methods 
	void pushFront(ListItemType newData) {
		Node<ListItemType>* newNode = new Node(newData);
		if (Empty()) {
			newNode->next = NULL;
			head = newNode;
		}
		else {
			newNode->next = head;
			head = newNode;
		}
		listSize++;
	} // add to first '
	ListItemType topFront() { return head; }
	void popfront() {
		head->next = head;
		delete head;
		listSize--;
	}
	void append(ListItemType it)
	{
		Node<ListItemType>* newNode = new Node(it);
		Node* curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = newNode;
		listSize++;
	} // add after last element 
	ListItemType topBack() {
		Node* curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		return curr;
	}
	void popBack() {
		Node* curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		delete curr;
		listSize--;
	}
	bool Find(ListItemType it) {
		Node* curr = head;
		while (curr->next != NULL) {
			return curr->data == it;
			curr = curr->next;
		}
	}
	void Erase(int position) {
		if (position == 0) {
			Node* curr = head->next;
			delete head;
			listSize--;
			head = curr;
			return head;
		}
		else {
			Node* curr = head;
			for (int i = 0; i < position - 1; i++) {
				curr = curr->next;
			}
			Node* temp = curr->next;
			curr->next = temp->next;
			delete temp;
			listSize--;
			return head;
		}
	}
	inline bool Empty() { return head == NULL; }
	void addBefore(Node<ListItemType>* nextNode, ListItemType it) {
		Node<ListItemType>* it = new Node(it);
		Node* curr = head;
		while (curr->next != nextNode) {
			curr = curr->next;
		}
		Node* pointTonextNode = nextNode;
		curr->next = it;
		it->next = pointTonextNode;
		listSize++;
	}
	void addAfter(Node<ListItemType>* prevNode, ListItemType newData) {
		if (prevNode == NULL) return;
		Node<ListItemType>* newNode = new Node(newData);   // Allocate new node  & Put in the data 
		newNode->next = prevNode->next;  // Make next of new node as next of prev_node
		prevNode->next = newNode;       // move the next of prev_node as new_node 
		listSize++;
	}// add after current element 
	int length() { return listSize; }    // Return list length 
	void print() {
		if (head == NULL) {
			return;
		}
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << "  ";
			curr = curr->next;
		}
	}
};
// doubly linked list implementation ______________________________________________________________________________
template <class ListItemType>
class DoublyLinkedListNode {
public:
	ListItemType data;
	DoublyLinkedListNode* next;
	DoublyLinkedListNode* prev;

	DoublyLinkedListNode(ListItemType node_data) {
		this->data = node_data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};
template <class ListItemType>
class DoublyLinkedList : public DoublyLinkedListNode<ListItemType>  {
public:
	DoublyLinkedListNode<ListItemType>* head;
	DoublyLinkedListNode<ListItemType>* tail;
	int listSize = 0;
	DoublyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}
	void pushFront(ListItemType it)
	{
		DoublyLinkedListNode* newNode = GetNewNode(it);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		listSize++;
	}
	ListItemType topFront() { return head; }
	void popfront() {
		head->next = head;
		delete head;
		listSize--;
	}
	void append(ListItemType it) {
		DoublyLinkedListNode<ListItemType>* newNode = DoublyLinkedListNode<ListItemType>(it);
		if ( head == NULL && tail == NULL) {
			head = tail = newNode; 
			newNode->prev = NULL;
			listSize++;
		}
		else{
			tail->next = newNode; 
			newNode->prev = tail; 
			tail = newNode; 
			listSize++;
		}
	}
	ListItemType topBack() { return tail;  }
	void popBack() {
		tail->prev = tail; 
		delete tail; 
		tail = tail->prev;
	}
	bool Find(ListItemType it) {
		Node* curr = head;
		while (curr != NULL ) {
			return curr->data == it;
			curr = curr->next;
		}
	}
	void Erase(int position) {
		if (position == 0) {
			Node* curr = head->next;
			delete head;
			head = curr;
			listSize--;
			return head;
		}
		else {
			Node* curr = head;
			for (int i = 0; i < position - 1; i++) {
				curr = curr->next;
			}
			Node* temp = curr->next;
			curr->next = temp->next;
			delete temp;
			listSize--;
			return head;
		}
	}
	inline bool Empty() { return (head == NULL && tail == NULL); }
	void addBefore(DoublyLinkedListNode<ListItemType>* nextNode, ListItemType it){
		DoublyLinkedListNode* newNode = new DoublyLinkedListNode(it); 
		if (Empty()) {
			head = tail = newNode; 
		}
		if ( nextNode == head) {
			pushFront();
		}
		DoublyLinkedListNode* temp; 
		temp = nextNode->prev; 
		nextNode->prev = newNode; 
		temp->next = newNode; 
		listSize++;
	}
	void addAfter(Node<ListItemType>* prevNode, ListItemType it) {
		DoublyLinkedListNode<ListItemType>* newNode = new DoublyLinkedListNode(it);
		if (Empty()) {
			head = tail = newNode;
		}
		if (prevNode == tail) {
			append();
		}
		DoublyLinkedListNode* temp;
		temp = prevNode->next;
		prevNode->next = newNode; 
		temp->prev = newNode; 
		listSize++;
	}
	void print() {
		if (head == NULL && tail == NULL ) {
			cout << " The list is Empty \n";
		}
		Node* curr = head;
		while (curr != NULL) {
			cout << curr->data << "  ";
			curr = curr->next;
		}
	}
	int length() { return listSize; }    // Return list length 
	void print_reverse()
	{
		DoublyLinkedListNode* t = head;
		while (t->next != NULL)
		{
			t = t->next;
		}
		//reverse
		cout << "reverse: ";
		while (t != NULL)
		{
			cout << t->data << " ";
			t = t->prev;
		}
		cout << "\n";
	}
};
// Stack implementation_____________________________________________________________________________________________ 
template <class ListItemType>
class Stack {
	Node<ListItemType>* top;
	int stacksize = 0; 
public:
	void push(ListItemType it) {
		Node* it = new Node(it);
		it->next = top;
		top = it;
		stacksize++; 
	}
	int peek() {
		if (isEmpty()) return 0;
		return top->data;
	}
	int pop() {
		if (isEmpty()) return 0;
		Node* temp = top;
		ListItemType item = temp->data;
		top = top->next;
		delete temp;
		stacksize--;
		return item;
	}
	bool  isEmpty() { return top == NULL; }
	void display() {
		Node* temp = top;
		for (int i = 0; i < stacksize; i++) {
			cout << temp->data << "  ";
			temp = temp->next;
		}
		cout << endl;
	}
	int length() { return stacksize;  }
	
	
};
// Queues implementation_____________________________________________________________________________________________
template <class ListItemType>
class Queues {
public : 
	Node<ListItemType>* head;
	Node<ListItemType>* tail;
	int Queuesize = 0;
public : 
	Queues() {
		head = tail = NULL; 
	}
	void Enqueue(ListItemType data) {
		Node* it = new Node(data);
		if (isEmpty()) {
			head = it; 
			tail = it; 
			Queuesize++;
		}
		tail->next = it; 
		tail = it; 
		Queuesize++; 
	}
	void Dequeue() {
		if (isEmpty()) { return; }
		if (head == tail) {
			delete head; 
			head = tail = NULL;
			Queuesize--;
		}
		Node* temp = head; 
		head = head->next; 
		delete temp; 
		Queuesize--;
	}
	bool isEmpty() { return (head == NULL && tail == NULL); }
	ListItemType peek() { return head->data; }
	int length() { return Queuesize;  }
	void clear() {
		if (isEmpty()) { return; }
		while (!isEmpty()) {
			Dequeue();
		}
	} 
	void print() {
		if (isEmpty()) { cout << "Queue is empty  \n"; }
		Node* curr = head; 
		while (curr != NULL) {
			cout << curr->data << "  ";
			curr = curr->next; 
		}
		cout << endl; 
	}
};
int main()
{
	
	



    return 0; 
}

