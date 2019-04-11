// MyString.h
// Declare a string which is similar to standard string
//*******************************************************************

#ifndef MY_STRING_H
#define MY_STRING_H

#include "ArrayAllocator.h"
#include <iostream>
#include <cassert>
#include "KMP.h"

using std::istream;
using std::ostream;

template<typename T>
class MyStringBase : public ArrayAllocator<T>
{
	// to make "abc" + MyString("aaa") valid
	template<typename T>
	friend MyStringBase<T> operator+(const T* arr, const MyStringBase<T>& str) { return MyStringBase<T>(arr) + str; }

	// input and output stream
	template<typename T>
	friend istream& operator>>(istream& is, MyStringBase<T>& str);
	template<typename T>
	friend ostream& operator<<(ostream& os, const MyStringBase<T>& str);
public:
	//-------------------------------------------------------
	//-------------------------------------------------------
	//-------------------- Constructors ---------------------
	//-------------------------------------------------------
	//-------------------------------------------------------
	// Most of constructors inherit from base class

	MyStringBase(); // Empty string
	explicit MyStringBase(size_t size) ; // Empty string which alloc memory in advance
	MyStringBase(const T& element, size_t count); // Create a string filled with character 'element' of count 'count'
	MyStringBase(const T* arr); // Create string from c-style string
	MyStringBase(const MyStringBase& str); // Create string from another string
	~MyStringBase(); // Default destructor

	//-------------------------------------------------------
	//-------------------------------------------------------
	//------------- Search substring in string --------------
	//-------------------------------------------------------
	//-------------------------------------------------------
	// Get the first indexe of the given element or substring
	// You can choose to and a starting index

	// Search single character
	int indexOf(const T& element) const { return indexOf(0, element); }
	int indexOf(size_t startIndex, const T& element) const;
	int lastIndexOf(const T& element) const { return lastIndexOf(this->size() - 1, element); }
	int lastIndexOf(size_t startIndex, const T& element) const;

	// Search substring
	// Use KMP to make the time complexity O(n + m)
	int indexOf(const MyStringBase& string) const { return indexOf(0, string); } 
	int indexOf(size_t startIndex, const MyStringBase& string) const; 
	// another name of indexOf()
	int strstr(const T& element) const { return indexOf(element); }
	int strstr(size_t startIndex, const T& element) const { return indexOf(startIndex, element); }
	int strstr(const MyStringBase& string) const { return indexOf(string); } 
	int strstr(size_t startIndex, const MyStringBase& string) const { return indexOf(startIndex, string); } 

	//-------------------------------------------------------
	//-------------------------------------------------------
	//------------------- Get substring ---------------------
	//-------------------------------------------------------
	//-------------------------------------------------------
	// Get the substring of current string
	MyStringBase mid(size_t l, size_t len) const;
	MyStringBase substr(size_t l, size_t len) const { return mid(l, len); } // another name of mid()

	//-------------------------------------------------------
	//-------------------------------------------------------
	//------------------- Append string ---------------------
	//-------------------------------------------------------
	//-------------------------------------------------------
	// Append the string by overloading the operators
	MyStringBase operator+(const T& element) const;
	MyStringBase operator+(const MyStringBase& str) const;
	MyStringBase& operator+=(const T& element);
	MyStringBase& operator+=(const MyStringBase& str);

	//-------------------------------------------------------
	//-------------------------------------------------------
	//----------------- Delete substring --------------------
	//-------------------------------------------------------
	//-------------------------------------------------------
	// Delete all the substring from current string by using KMP
	MyStringBase operator-(const MyStringBase& substr) const;
	MyStringBase& operator-=(const MyStringBase& substr);

	//-------------------------------------------------------
	//-------------------------------------------------------
	//------------------  String Compare --------------------
	//-------------------------------------------------------
	//-------------------------------------------------------
	int compare(const MyStringBase& str) const;
	bool operator==(const MyStringBase& str) const { return compare(str) == 0; }
	bool operator!=(const MyStringBase& str) const { return compare(str) != 0; }
	bool operator<(const MyStringBase& str) const { return compare(str) < 0; }
	bool operator<=(const MyStringBase& str) const { return compare(str) <= 0; }
	bool operator>(const MyStringBase& str) const { return compare(str) > 0; }
	bool operator>=(const MyStringBase& str) const { return compare(str) >= 0; }

	//-------------------------------------------------------
	//-------------------------------------------------------
	//----------------------  Sundry ------------------------
	//-------------------------------------------------------
	//-------------------------------------------------------
	size_t length() const { return size(); } // another name of size();bool empty() const { return _ptr == nullptr; }
};

using MyString = MyStringBase<char>;

template <typename T>
MyStringBase<T>::MyStringBase() : ArrayAllocator<T>()
{

}

template <typename T>
MyStringBase<T>::MyStringBase(size_t size) : ArrayAllocator<T>(size)
{

}

template <typename T>
MyStringBase<T>::MyStringBase(const T* arr) : ArrayAllocator<T>(arr)
{

}

template <typename T>
MyStringBase<T>::MyStringBase(const MyStringBase& str) : ArrayAllocator<T>(str)
{

}

template <typename T>
MyStringBase<T>::~MyStringBase()
{

}

template <typename T>
istream& operator>>(istream& is, MyStringBase<T>& str)
{
	return is << str._ptr;
}

template <typename T>
ostream& operator<<(ostream& os, const MyStringBase<T>& str)
{
	for (int i = 0; i < str.size(); i++)
	{
		os << str[i];
	}
	return os;
}

template <typename T>
MyStringBase<T>::MyStringBase(const T& element, size_t count) : ArrayAllocator(count)
{
	if (size() != 0)
	{
		// Create count elements
		for (int i = 0; i < size(); i++)
		{
			(*this)[i] = element;
		}
	}
}

template <typename T>
int MyStringBase<T>::lastIndexOf(size_t startIndex, const T& element) const
{
	int res = -1;
	// Traverse the string to find the element
	for (int i = startIndex; i >= 0; i--)
	{
		if ((*this)[i] == element)
		{
			res = i;
			break;
		}
	}
	return res;
}

template <typename T>
int MyStringBase<T>::indexOf(size_t startIndex, const T& element) const
{
	int res = -1;
	// Traverse the string to find the element
	for (int i = startIndex; i < this->size(); i++)
	{
		if ((*this)[i] == element)
		{
			res = i;
			break;
		}
	}
	return res;
}

template <typename T>
int MyStringBase<T>::indexOf(size_t startIndex, const MyStringBase<T>& str) const
{
	// Call kmp algorithm
	KMP<MyStringBase<T>> kmp;
	return kmp(*this, this->size(), str, str.size(), startIndex);
}

template <typename T>
MyStringBase<T> MyStringBase<T>::mid(size_t l, size_t len) const
{
	size_t r = l + len - 1;
	assert(r >= l);

	// Calculate the size of result and create string
	MyStringBase<T> res(r - l + 1);

	// Copy each element
	for (int i = l; i <= r; i++)
	{
		res[i - l] = (*this)[i];
	}
	return res;
}

// The operator+ functions call addItem of base class
template <typename T>
MyStringBase<T> MyStringBase<T>::operator+(const T& element) const
{
	MyStringBase res(*this);
	res.addItem(element);
	return res;
}
template <typename T>
MyStringBase<T> MyStringBase<T>::operator+(const MyStringBase& str) const
{
	MyStringBase res(*this);
	res.addItem(str);
	return res;
}
template <typename T>
MyStringBase<T>& MyStringBase<T>::operator+=(const T& element)
{
	addItem(element);
}
template <typename T>
MyStringBase<T>& MyStringBase<T>::operator+=(const MyStringBase& str)
{
	addItem(str);
}

template <typename T>
MyStringBase<T> MyStringBase<T>::operator-(const MyStringBase& substr) const
{
	MyStringBase<T> res;
	KMP kmp;

	// Every time, we copy substr(l, r) to new string
	// We filter all input string
	int l = 0;
	int r = kmp(*this, size(), substr, substr.size()) - 1;
	while (r != -1)
	{
		res += substr(l, r);
		l = r + substr.size();
		r = kmp(*this, size(), substr, substr().size(), l, false) - 1;
	}
	res += substr(l, r);
	return res;
}
template <typename T>
MyStringBase<T>& MyStringBase<T>::operator-=(const MyStringBase& substr)
{
	MyStringBase<T> tmp = (*this) - substr;
	return *this = tmp;
}

template <typename T>
int MyStringBase<T>::compare(const MyStringBase<T>& str) const
{
	int sz = this->size() < str.size() ? this->size() : str.size();

	// Compare each element of two strings
	for (int i = 0; i <= sz; i++)
	{
		if ((*this)[i] != str[i])
		{
			return (*this)[i] - str[i];
		}
	}
	// If all the elments are equal, they are equal
	return 0;
}

#endif