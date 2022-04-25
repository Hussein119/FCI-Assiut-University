#include"StackType.h"
#include<iostream>
using namespace std; 
int main() {

	StackType <char> s;
	s.Push(5);
	s.Push(6);
	s.Push(4);
	s.Push(9);
	s.Push(7);
	cout << s.Top() << endl;


	return 0; 
}