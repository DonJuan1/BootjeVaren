#include "CustomVector.h"

CustomVector::CustomVector()
{
	maxsize = 16;
	array = new int[maxsize];
	vsize = 0;
}

CustomVector::CustomVector(int i)
{
	maxsize = i;
	array = new int[maxsize];
	vsize = 0;
}

CustomVector::~CustomVector()
{
	delete[] array;
}

void CustomVector::push_back(int i)
{
	if (vsize + 1 > maxsize)
	{
		alloc_new();
	}

	array[vsize] = i;
	vsize++;
}

int CustomVector::operator[](int i)
{
	return array[i];
}


int CustomVector::at(int i)
{
	if (i < vsize)
	{
		return array[i];
	}

	throw std::out_of_range("CustomVector::at() : index is out of range");
}

void CustomVector::alloc_new()
{
	maxsize = vsize * 2;
	int* temp = new int[maxsize];
	for (int i = 0; i < vsize; i++)
	{
		temp[i] = array[i];
	}

	delete[] array;
	array = temp;
}

int CustomVector::size()
{
	return vsize;
}
