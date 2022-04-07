// lab 4 prog tech task 1

#include <iostream>
#include "myio.h"
#include "sort.h"

template <typename T1, typename T2, typename T3 = int>
int binary_search(T1& _arr, T2& _key, T3 _size)
{
	try
	{
		if (_size <= 0)
			e.setExep((char*)"array size is <= zero");

		// if not sorted throw
		is_sorted(_arr, _size);

		// if bigger or smaller than range than throw
		if (compar(_key, _arr[0]) > 0)
		{
			std::cout << _key << "  " << _arr[0] << std::endl;
			e.setExep((char*)"key is not in the array: smaller");
		}
		if (compar(_key, _arr[_size - 1]) < 0)
		{
			std::cout << _key << "  " << _arr[_size - 1] << std::endl;
			e.setExep((char*)"key is not in the array: bigger");
		}

		if (e.getExep())
			throw e;
		e.setExep(nullptr);
	}

	catch (...)
	{
		throw e;
	}

	std::cout << "key is  '" << _key << "'" << std::endl;

	int range = _size;
	int mid = 0;
	int left = 0, right = range;
	int mid0flag = 0;
	while (right - left > 0)
	{
		mid = (right - left) / 2;
		if (mid == 0)
			mid0flag++;
		if (mid0flag == 2 && mid == 0)
		{
			e.setExep((char*)"key is not in the array: not found");
			throw e;
		}
		if (compar(_arr[left + mid], _key) == 0)
		{
			printf("found! x = %d\n", left + mid);
			return left + mid;
		}
		else
			if (compar(_arr[left + mid], _key) > 0)
			{
				//printf("key is bigger\n");
				left += mid;
			}
			else
				if (compar(_arr[left + mid], _key) < 0)
				{
					//printf("key is smaller\n");
					right -= mid;
				}
	}

	e.setExep((char*)"key is not in the array: not found");
	throw e;
}

int binary_search(char** _arr, char* _key, int _size)
{
	try
	{
		if (_size <= 0)
			e.setExep((char*)"array size is <= zero");

		// if not sorted throw
		is_sorted(_arr, _size);

		// if bigger or smaller than range than throw
		if (compar(_key, _arr[0]) > 0)
		{
			std::cout << _key << "  " << _arr[0] << std::endl;
			e.setExep((char*)"key is not in the array: smaller");
		}
		if (compar(_key, _arr[_size - 1]) < 0)
		{
			std::cout << _key << "  " << _arr[_size - 1] << std::endl;
			e.setExep((char*)"key is not in the array: bigger");
		}

		if (e.getExep())
			throw e;
		e.setExep(nullptr);
	}

	catch (...)
	{
		throw e;
	}

	std::cout << "key is  '" << _key << "'" << std::endl;

	int range = _size;
	int mid = 0;
	int left = 0, right = range;
	int mid0flag = 0;
	while (right - left > 0)
	{
		mid = (right - left) / 2;
		if ( mid == 0)
			mid0flag ++;
		if (mid0flag == 2 && mid == 0)
		{
			e.setExep((char*)"key is not in the array: not found");
			throw e;
		}

		if (compar(_arr[left + mid], _key) == 0)
		{
			cout << "found! x = " << left + mid << endl;
			return left + mid;
		}
		else
			if (compar(_arr[left + mid], _key) > 0)
			{
				//printf("key is bigger\n");
				left += mid;
			}
			else
				if (compar(_arr[left + mid], _key) < 0)
				{
					//printf("key is smaller\n");
					right -= mid;
				}
	}
	if (compar(_arr[left], _key) == 0)
	{
		cout << "found! x = " << left + mid << endl;
		return left + mid;
	}
	e.setExep((char*)"key is not in the array: not found!");
	throw e;
}

// EOF