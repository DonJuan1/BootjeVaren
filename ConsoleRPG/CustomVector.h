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

	void push_back(const T&);
	void push_back(T&&);
	void pop_index(int index);

	int size() const;
	T& operator[](int) const;
	CustomVector<T>& operator=(const CustomVector<T>&);
	T& at(int) const;

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
void CustomVector<T>::push_back(const T& i)
{
	if (vsize + 1 > maxsize)
	{
		alloc_new();
	}

	array[vsize] = i;
	vsize++;
}

template<class T>
void CustomVector<T>::push_back(T&& i)
{
	if (vsize + 1 > maxsize)
	{
		alloc_new();
	}

	array[vsize] = i;
	vsize++;
}

template<class T>
void CustomVector<T>::pop_index(int index)
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
T& CustomVector<T>::operator[](int i) const
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
	}

	return *this;
}

template<class T>
T& CustomVector<T>::at(int i) const
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
int CustomVector<T>::size() const
{
	return vsize;
}
