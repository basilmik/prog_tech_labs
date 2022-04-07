// lab 4 prog tech task 1

/*Задание 1
Написать функцию-шаблон двоичного поиска.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "stdio.h"
#include "myio.h"
#include "bins.h"
#include "myarr.h"


template <typename T>
int func(myArr<T>* _arrObj)
{
	int take = 0;
	while (!take)
	{
		printf("-1  back to setting array ---- 1 find something ---- 2 sort array ---- 3 show array\n");
		myCin(take);
		switch (take)
		{
		case -1:
			return 0;
		case 1:
		{
			printf("enter value to find:\n");
			T* key = new T;
			myCin(*key);
			try 
			{
				T* arr = _arrObj->get_arr();
				binary_search(arr, *key, _arrObj->get_size());
			}
			catch (...)
			{
				if (e.getExep())
					e.outExep();
				e.setExep(nullptr);
			}
		}
		break;

		case 2:
		{
			T* arr = _arrObj->get_arr();
			sort(arr, arr[0], _arrObj->get_size());
		}
		break;

		case 3:
		{
			T* arr = _arrObj->get_arr();
			show(arr, _arrObj->get_size());
		}
		break;

		default: 
			printf("unknown command\n");
			//getchar();
		}

		take = 0;
		printf("\n");
	}
	return 0;
}

int func(myArr<char*>* _arrObj)
{
	int take = 0;
	while (!take)
	{
		printf("-1  back to setting array ---- 1 find something ---- 2 sort array ---- 3 show array\n");
		myCin(take);
		switch (take)
		{
		case -1:
			return 0;
		case 1:
		{
			printf("enter value to find:\n");
			char* key = nullptr;
			myCin(&key);
			try
			{
				binary_search(_arrObj->get_arr(), key, _arrObj->get_size());
			}
			catch (...)
			{
				if (e.getExep())
					e.outExep();
				e.setExep(nullptr);
			}
		}
		break;

		case 2:
		{
			char** arr = _arrObj->get_arr();
			sort(arr, arr[0], _arrObj->get_size());
		}
		break;

		case 3:
		{
			show(_arrObj->get_arr(), _arrObj->get_size());
		}
		break;

		default:
			printf("unknown command\n");
			//getchar();
		}

		take = 0;
		printf("\n");
	}
	return 0;
}


int menu()
{
	int type = -1;
	while (type < 0)
	{
		printf("-1 exit ----   choose type: 1 int, 2 char, 3 float, 4 double, 5 char*\n");

		myCin(type);
		int size = 0;

		switch (type)
		{
		case -1:
			return 0;

		case 1:
		{
			while (size <= 0) { printf("enter size of new array\n"); myCin(size); }
			myArr<int> Arr(size);
			func(&Arr);
		}	break;

		case 2:
		{	
			while (size <= 0) { printf("enter size of new array\n"); myCin(size); }
			myArr<char> Arr(size);
			func(&Arr);
		}	break;

		case 3:
		{	
			while (size <= 0) { printf("enter size of new array\n"); myCin(size); }
			myArr<float> Arr(size);
			func(&Arr);
		}	break;

		case 4:
		{	
			while (size <= 0) { printf("enter size of new array\n"); myCin(size); }
			myArr<double> Arr(size);
			func(&Arr);
		}	break;

		case 5:
		{
			while (size <= 0) { printf("enter size of new array\n"); myCin(size); }
			myArr<char*> Arr(size);
			func(&Arr);
		}	break;


		default:
			printf("unknown type, try again\n");
			type = 0;
		}
		type = -1;
	}

	return -1;
}

int main()
{
	printf("TECH PROG LAB 4 TASK 1: template function of binary search\n\n");
	menu();

	return 0;
}

// EOF