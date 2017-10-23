#pragma once

#include <stdexcept> 

using namespace std;

template<class T>
class CustomPointerVector
{
public:
	CustomPointerVector();
	CustomPointerVector(int);
	CustomPointerVector(const CustomVector<T>&);
	~CustomPointerVector();

	void push_back(T);
	void pop_index(int index);

	int size() const;
	T& operator[](int);
	CustomPointerVector<T>& operator=(const CustomPointerVector<T>&);
	T& at(int) const;

private:
	int vsize;
	int maxsize;
	T* array;

	void alloc_new();

};

template<class T>
CustomPointerVector<T>::CustomPointerVector()
{
	maxsize = 16;
	array = new T[maxsize];
	vsize = 0;
}

template<class T>
CustomPointerVector<T>::CustomPointerVector(int i)
{
	maxsize = i;
	array = new T[maxsize];
	vsize = 0;
}

template<class T>
CustomPointerVector<T>::CustomPointerVector(const CustomVector<T>& v)
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
CustomPointerVector<T>::~CustomPointerVector()
{
	for (int i = 0; i < vsize; i++)
	{
		delete array[i];
	}

	delete[] array;
}

template<class T>
void CustomPointerVector<T>::push_back(T i)
{
	if (vsize + 1 > maxsize)
	{
		alloc_new();
	}

	array[vsize] = i;
	vsize++;
}

template<class T>
void CustomPointerVector<T>::pop_index(int index)
{
	if (vsize == 0)
		return;

	int newSize = vsize - 1;
	T* temp = new T[newSize];
	vsize--;
	maxsize = vsize;

	int y = 0;

	for (int i = 0; i < newSize; i++)
	{
		if (i == index)
		{
			y++;
		}
		temp[i] = array[y];

		y++;
	}

	delete[] array;
	array = temp;

	return;
}

template<class T>
T& CustomPointerVector<T>::operator[](int i)
{
	return array[i];
}

template<class T>
CustomPointerVector<T>& CustomPointerVector<T>::operator=(const CustomPointerVector<T>& v)
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
	}

	return *this;
}

template<class T>
T& CustomPointerVector<T>::at(int i) const
{
	if (i < vsize)
	{
		return array[i];
	}

	throw std::out_of_range("CustomVector::at() : index is out of range");
}

template<class T>
void CustomPointerVector<T>::alloc_new()
{
	int tempInt = vsize;

	if (vsize == 0) {
		tempInt = 1;
	}

	maxsize = tempInt * 2;
	T* temp = new T[maxsize];
	for (int i = 0; i < vsize; i++)
	{
		temp[i] = array[i];
	}

	delete[] array;
	array = temp;
}

template<class T>
int CustomPointerVector<T>::size() const
{
	return vsize;
}
