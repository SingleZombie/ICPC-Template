// KMP.h
// Declare KMP algorithm which can do string match in O(n + m)
//***************************************************************
#ifndef K_M_P_H
#define K_M_P_H

// T : the type of string
// ARR_LEN : the length of string
template <typename T>
class KMP
{
public:
	KMP() {};
	int operator()(const T& target, size_t targetLength, // The description of target
		const T& pattern, size_t patternLength, // The description of pattern
		int startIndex = 0, // Start in which location of target
		bool needCalNext = true); // Whether calculate the next array
private:
	int* _next;
	void calNext(const T& pattern, size_t m);
};

template <typename T>
int KMP<T>::operator()(const T& target, size_t n, // The description of target
	const T& pattern, size_t m, // The description of pattern
	int startIndex, // Start in which location of target
	bool needCalNext) // Whether calculate the next array
{
	int i = startIndex, j = 0;
	if (needCalNext)
	{
		calNext(pattern, m);
	}
	while (i < n && j < m)
	{
		if (target[i] == pattern[j])
		{
			i++, j++;
		}
		else
		{
			if (j == 0)
			{
				i++;
			}
			else
			{
				j = _next[j - 1];
			}
		}
	}
	if (j == m)
	{
		return i - m;
	}
	else
	{
		return -1;
	}
}

template <typename T>
void KMP<T>::calNext(const T& pattern, size_t m)
{
	_next = new int[m + 2];

	int i = 1, k = 0;
	_next[0] = 0;
	while (i < m)
	{
		if (pattern[i] == pattern[k])
		{
			_next[i++] = ++k;
		}
		else
		{
			if (k == 0)
			{
				_next[i++] = 0;
			}
			else
			{
				k = _next[k - 1];
			}
		}
	}
}

#endif