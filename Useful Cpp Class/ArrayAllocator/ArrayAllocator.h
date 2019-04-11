// ArrayAllocator.h
// Declare a container which save data in array
// When the space is not enough, the allocator will alloc memory and substitude old memory
// The element behind the last element of array will be alloced, but user can't get it
// ******************************************************************************************

#ifndef ARRAY_ALLOCATOR_H
#define ARRAY_ALLOCATOR_H

template <typename T>
class ArrayAllocator
{
public:
	ArrayAllocator();
	ArrayAllocator(size_t size);
	ArrayAllocator(const T* arr);
	ArrayAllocator(const ArrayAllocator& aAlloc);
	virtual ~ArrayAllocator();

	// overload [] operator to make the class similar to array
	virtual T& operator[](size_t index);
	virtual const T& operator[](size_t index) const;

	// overload assign operator to make copy conveniently
	virtual ArrayAllocator& operator=(const ArrayAllocator& aAlloc);

	size_t size() const { return _size; }
	size_t cpacity() const { return _capacity; }
	bool empty() const { return _ptr == nullptr; }
	operator bool() const { return _ptr != nullptr; }
protected:
	// check whether the index in operator[] is valid
	// if the index is not correct, return false
	bool checkValidIndex(size_t index) const ;

	// Add new item to the array
	// We can add just one item, or append the array with another array
	bool addItem(const T& item);
	bool addItem(const ArrayAllocator& aAlloc);

	// Copy the data
	// Called by constructor and operator=
	// return false means space is not enough
	bool copy(const ArrayAllocator& aAlloc);
	T* _ptr;
private:
	size_t _size;
	size_t _capacity;

	// Define the method to calculate the capacity depend on size
	// We make the capacity always be the power of 2
	size_t calProperCapacity(size_t size) const;

	// Set the variable size
	// If the size is too large or too small, capacity will change and array needs to alloc new memory 
	// If clear == false, old data will be hold
	bool setSize(size_t size, bool clear = true);


	// Release old memory and alloc new memory
	// Return true means alloc memory successfully
	bool allocNewMemory(size_t newCapacity);
	bool allocNewMemoryAndHoldData(size_t newCapacity);
};

#include <cstring>

template <typename T>
ArrayAllocator<T>::ArrayAllocator() : _size(0), _capacity(1), _ptr(nullptr)
{

}

template <typename T>
ArrayAllocator<T>::ArrayAllocator(size_t size) : _size(0), _capacity(1), _ptr(nullptr)
{
	setSize(size);
}

template <typename T>
ArrayAllocator<T>::ArrayAllocator(const T* arr) : _size(0), _capacity(1), _ptr(nullptr)
{
	int size = 0;
	while (arr[size])
	{
		size++;
	}
	if (setSize(size))
	{
		for (int i = 0; i < size; i++)
		{
			_ptr[i] = arr[i];
		}
	}
	else
	{
		// throw exception
	}
}

template <typename T>
ArrayAllocator<T>::ArrayAllocator(const ArrayAllocator<T>& aAlloc) : _size(0), _capacity(1), _ptr(nullptr)
{
	if (!copy(aAlloc))
	{
		// throw exception
	}
}

template <typename T>
bool ArrayAllocator<T>::copy(const ArrayAllocator<T>& aAlloc)
{
	if (aAlloc.empty())
	{
		if (_ptr)
		{
			delete[] _ptr;
			_ptr = nullptr;
		}
		return true;
	}
	if (setSize(aAlloc.size()))
	{
		memcpy(_ptr, aAlloc._ptr, sizeof(T) * _capacity);
		return true;
	}
	return false;
}

template <typename T>
ArrayAllocator<T>::~ArrayAllocator()
{
	if (_ptr)
	{
		delete[] _ptr;
		_ptr = nullptr;
	}
}

template <typename T>
T& ArrayAllocator<T>::operator[](size_t index)
{
	if (!checkValidIndex(index))
	{
		// Throw exception
	}
	return _ptr[index];
}

template <typename T>
const T& ArrayAllocator<T>::operator[](size_t index) const
{
	if (!checkValidIndex(index))
	{
		// Throw exception
	}
	return _ptr[index];
}

template <typename T>
ArrayAllocator<T>& ArrayAllocator<T>::operator=(const ArrayAllocator<T>& aAlloc)
{
	copy(aAlloc);
	return *this;
}

template <typename T>
bool ArrayAllocator<T>::checkValidIndex(size_t index) const
{
	if (index > size())
	{
		return false;
	}
	return true;
}

template <typename T>
bool ArrayAllocator<T>::addItem(const T& item)
{
	// Try to set the size to old size + 1
	// Then put the item to the right position
	if (setSize(_size + 1, false))
	{
		ptr[_size - 1] = item;
		return true;
	}
	return false;
}

template <typename T>
bool ArrayAllocator<T>::addItem(const ArrayAllocator<T>& aAlloc)
{
	// Try to set the size to the sum of two array
	// Then copy the new items one by one
	size_t tmp = _size;
	if (setSize(_size + aAlloc._size, false))
	{
		for (int i = tmp; i < _size; i++)
		{
			_ptr[i] = aAlloc._ptr[i - tmp];
		}
		return true;
	}
	return false;
}

template <typename T>
size_t ArrayAllocator<T>::calProperCapacity(size_t size) const
{
	// the capacity expands twice every time
	size_t res = 1;
	while (res <= size)
	{
		res <<= 1;
	}
	return res;
}

template <typename T>
bool ArrayAllocator<T>::setSize(size_t size, bool clear)
{
	if (size == 0)
	{
		if (_ptr)
		{
			delete[] _ptr;
			_ptr = nullptr;
		}
		return true;
	}

	// Calculate the proper capacity
	int capacity = calProperCapacity(size);

	// If current capacity is not proper, we should alloc new memroy
	if (capacity != _capacity)
	{
		if (clear)
		{
			if (!allocNewMemory(capacity))
			{
				return false;
			}
		}
		else
		{
			if (!allocNewMemoryAndHoldData(capacity))
			{
				return false;
			}
		}

		_capacity = capacity;
	}
	_ptr[size] = 0;
	_size = size;
	return true;
}

template <typename T>
bool ArrayAllocator<T>::allocNewMemory(size_t newCapacity)
{
	// Release old memeory
	if (_ptr)
	{
		delete[] _ptr;
		_ptr = nullptr;
	}

	// Try to alloc new memory
	_ptr = new T[newCapacity];
	if (_ptr == nullptr)
	{
		// Memory is not enough, error
		return false;
	}
	memset(_ptr, 0, sizeof(T) * newCapacity);

	return true;
}

template <typename T>
bool ArrayAllocator<T>::allocNewMemoryAndHoldData(size_t newCapacity)
{
	// Old data must exist
	if (_ptr == nullptr)
	{
		return false;
	}

	// Try to alloc new memory
	T* newPtr = new T[newCapacity];
	if (newPtr == nullptr)
	{
		// Memory is not enough, error
		return false;
	}
	memset(newPtr, 0, sizeof(T) * newCapacity);

	// Copy old data
	int minCapacity = _capacity < newCapacity ? _capacity : newCapacity;
	for (int i = 0; i < minCapacity; i++)
	{
		newPtr[i] = _ptr[i];
	}

	// Set new pointer
	delete[] _ptr;
	_ptr = newPtr;


	return true;
}

#endif