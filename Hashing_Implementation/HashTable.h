#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
using namespace std;
#include "Student.h"

class HashTable
{
private:
	Students *Data;
public:
	HashTable();
	~HashTable();
	void Insert(string, string);
	string Retrieve(string);
};

#endif HASHTABLE_H