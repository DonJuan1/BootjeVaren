#pragma once
#include <cstddef>
#include <iostream>

template <class T>
class Vector {

	T *_array;
	std::size_t _capacity;
	std::size_t _used;
public:
	Vector(std::size_t cap) : _array{ new T[cap] },
		_capacity{ cap },
		_used{ 0 } { };

	~Vector()
	{
		if (_array != nullptr)
			delete[] _array;
	}

	Vector(const Vector &v) : _array{ new T[v._capacity] },
		_capacity{ v._capacity },
		_used{ v._used }
	{
		for (std::size_t i = 0; i < _used; ++i) {
			_array[i] = v._array[i];
		}
	}

	Vector &operator=(const Vector &v)
	{
		if (&v == this) return *this;

		if (_array != nullptr)
			delete[] _array;

		_array = new T[v._capacity];
		_capacity = v._capacity;
		_used = v._used;

		return *this;
	}

	Vector(Vector &&v) : _array{ v._array },
		_capacity{ v._capacity },
		_used{ v._used }
	{
		v._array = nullptr;
		v._used = v._capacity = 0;
	}

	Vector &operator=(Vector &&v)
	{
		if (&v == this)
			return *this;

		if (_array != nullptr)
			delete[] _array;

		_array = v._array;
		_capacity = v._capacity;
		_used = v._used;

		v._array = nullptr;
		v._used = v._capacity = 0;

		return *this;
	}

	std::size_t capacity() const
	{
		return _capacity;
	}

	void push_back(T value)
	{
		_array[_used++] = value;
	}

	std::size_t size() const
	{
		return _used;
	}

	int get(std::size_t index) const
	{
		return _array[index];
	}
};