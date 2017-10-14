#pragma once

#include <stdexcept> 

using namespace std;

class CustomVector
{
public:
	CustomVector();
	CustomVector(int);
	~CustomVector();

	void push_back(int);
	int size();
	int operator[](int);
	int at(int);


private:
	int vsize;
	int maxsize;
	int* array;

	void alloc_new();

};
