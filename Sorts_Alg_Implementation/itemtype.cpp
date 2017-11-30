#include <iostream>
#include <string>
using namespace std;
#include "itemtype.h"

void ItemType::operator= (const ItemType& right)
{
	this->Number = right.Number;
	this->Section = right.Section;
}