#pragma once

#include <stdexcept> 

using namespace std;

template<class T>
class CustomVector
{
public:
	CustomVector();
	CustomVector(int);
	CustomVector(const CustomVector<T>&);
	~CustomVector();

	void push_back(T&);

	int size();
	T& operator[](int);
	CustomVector<T>& operator=(const CustomVector<T>&);
	T& at(int);

private:
	int vsize;
	int maxsize;
	T* array;

	void alloc_new();

};

template<class T>
CustomVector<T>::CustomVector()
{
	maxsize = 16;
	array = new T[maxsize];
	vsize = 0;
}

template<class T>
CustomVector<T>::CustomVector(int i)
{
	maxsize = i;
	array = new T[maxsize];
	vsize = 0;
}

template<class T>
CustomVector<T>::CustomVector(const CustomVector<T>& v)
{
	if (this != &v)
	{
		delete[] array;

		maxsize = v.maxsize;
		vsize = v.vsize;
		array = new T[maxsize];

		std::memcpy(array, v.array, maxsize);

		return *this;
	}

	return *this;
}

template<class T>
CustomVector<T>::~CustomVector()
{
	delete[] array;
}

template<class T>
void CustomVector<T>::push_back(T& i)
{
	if (vsize + 1 > maxsize)
	{
		alloc_new();
	}

	array[vsize] = i;
	vsize++;
}

template<class T>
T& CustomVector<T>::operator[](int i)
{
	return array[i];
}

template<class T>
CustomVector<T>& CustomVector<T>::operator=(const CustomVector<T>& v)
{
	if (this != &v)
	{
		delete[] array;

		maxsize = v.maxsize;
		vsize = v.vsize;
		array = new T[maxsize];

		for (size_t i = 0; i < v.vsize; i++)
		{
			array[i] = v.array[i];
		}

		return *this;
	}
}

template<class T>
T& CustomVector<T>::at(int i)
{
	if (i < vsize)
	{
		return array[i];
	}

	throw std::out_of_range("CustomVector::at() : index is out of range");
}

template<class T>
void CustomVector<T>::alloc_new()
{
	if (vsize == 0) {
		vsize = 1;
	}

	maxsize = vsize * 2;
	T* temp = new T[maxsize];
	for (int i = 0; i < vsize; i++)
	{
		temp[i] = array[i];
	}

	delete[] array;
	array = temp;
}

template<class T>
int CustomVector<T>::size()
{
	return vsize;
}
