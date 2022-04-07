// lab 4 prog tech task 1

#include <iostream>

template <typename T, typename T2 = T, typename T3 = int>
void sort(T& _arr, T2& _memo, T3 _size)
{
	int i = 0;
	T2 memo;

	while (i < _size - 1)
	{
		if (compar(_arr[i], _arr[i + 1]) >= 0)
			i++;
		else
		{
			memo = _arr[i];
			_arr[i] = _arr[i + 1];
			_arr[i + 1] = memo;
			i = 0;
		}
	}
}

template <typename T, typename T2 = int>
void is_sorted(T& _arr, T2 _size)
{
	int i = 0;
	while (i != _size - 1)
	{
		//if (_arr[i] <= _arr[i + 1])
		if (compar(_arr[i], _arr[i + 1]) >= 0)
			i++;
		else
		{
			e.setExep((char*)"not sorted!");
			throw e;
		}
	}
}

// EOF