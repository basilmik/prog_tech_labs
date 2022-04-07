// lab 4 prog tech task 2
/*
Задание 2
Создать параметризованную очередь с перегруженным оператором потокового ввода/вывода и 
перегруженным оператором + для сложения двух очередей, ! для проверки на пустоту и 
– для вычитания двух очередей.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <istream>
#include <ostream>
#include "stdio.h"

#include "myio.h"
#include "Queue.h"

using namespace std;

template <typename T>
int func()
{
	Queue<T>* Q1 = new Queue<T>;
	Queue<T>* Q2 = new Queue<T>;
	Queue<T>* memo;
	
	printf("-1 exit   1 push   2 pop   3 isEmpty   4 swap A and B   5 A + B   6 A - B   7 show queue\n");

	int take = 0;
	while (!take)
	{
		myCin(take);
		try {
			switch (take)
			{
			case -1:
				return 0;
			case 1: // push
				cin >> Q1;
				break;

			case 2: // pop
				cout << Q1;
				break;

			case 3:
				if (!(*Q1))
					printf("is indeed empty!\n");
				else
					printf("not empty!\n");
				break;

			case 4: // swap
				memo = Q1;
				Q1 = Q2;
				Q2 = memo;
				printf("swaped!\n");
				break;

			case 5: // A + B
				*Q1 + *Q2;
				printf("+\n");
				break;

			case 6: // A- B
				*Q1 - *Q2;
				printf("-\n");
				break;

			case 7:
				Q1->show_q();
				break;

			default: printf("unknown command, try again\n");
			}
		}

		catch (...)
		{
			if (e.getExep())
				e.outExep();
			e.setExep(nullptr);

		}
		take = 0;
	}

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
			func<int>();
		}	break;

		case 2:
		{
			func<char>();
		}	break;

		case 3:
		{
			func<float>();
		}	break;

		case 4:
		{
			func<double>();
		}	break;

		case 5:
		{
			func<char*>();
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
	printf("TECH PROG LAB 4 TASK 2: template Queue with << >> + - ! overload\n\n");
	menu();
	return 0;
}

//EOF