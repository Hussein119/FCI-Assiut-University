#pragma once
// The following declarations and definitions go into file ItemType.h.
#include <fstream>
const int MAX_ITEMS = 5;
enum RelationType { LESS, GREATER, EQUAL };
class ItemType
{
public:
	ItemType();
	RelationType ComparedTo(ItemType) const;
	void Print(std::ofstream&) const;
	void Initialize(int number);
private:
	int value;
};
