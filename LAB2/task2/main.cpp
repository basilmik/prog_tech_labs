// lab 2 task 2
/*—оздать класс координат, содержащий x, y и z. 
ѕерегрузить оператор сложени€ как метод дл€ сложени€ с другим экземпл€ром класса или числом,
перегрузить  оператор вычитани€ как дружественную функцию дл€ вычитани€ с другим экземпл€ром класса и числом,
число - вводимыми пользователем с клавиатуры, 
при этом число может располагатьс€ как слева, так и справа от оператора; 
операторы ввода и вывода в поток; 
все операторы сравнени€ с другим экземпл€ром класса (сравнение должно происходить между соответствующими координатами). 
Ќа усмотрение  студента остаетс€ решение какой оператор какой перегрузки требует (метод или дружественна€ функци€).*/

#define _CRT_SECURE_NO_WARNINGS
#include "classPoint.h"

using namespace std;

void myScanf(int* _x)
{
	while (1)
	{
		if (scanf("%d", _x) != 0)
			break;
		printf("unvalid input, try again\n");
		if (getchar());
	}
}


int menu()
{
	Point p1, p2, pmemo;
	int take = 0, val;
	printf("there are two points: MAIN and ANOTHER\nthey have x y and z coordinates\n");
	printf("MENU\n-2 swap main point with another\n-1 set values  \n0 show this  \n1 add to another point  \n2 add to a value  \n3 sub another point  \n4 sub a val (obj - val)  \n5 (val - obj)\n");
	printf("\n6  ==  \n7 !=  \n8 <  \n9 <=  \n10 >  \n11 >=  \n\n100 exit\n\n");

	while (!take)
	{
		myScanf(&take);

		switch (take)
		{
		case 100:
			return 0;

		case -2:
			pmemo = p1;
			p1 = p2;
			p2 = pmemo;
			cout << "swapped!" << endl;
			break;

		case -1:
			printf("enter point values:\n");
			cin >> p1;
			break;

		case 0:
			cout << p1 << endl;
			break;

		case 1:
			p1 = p1 + p2;
			cout << "added!" << endl;
			break;

		case 2:
			cout << "value: ";
			myScanf(&val); 
			p1 = p1 + val;
			cout << "added!" << endl;
			break;

		case 3:
			p1 - p2;
			cout << "substracted!" << endl;
			break;

		case 4:
			cout << "value: ";
			myScanf(&val); 
			p1 - val;
			cout << "substracted!" << endl;
			break;

		case 5: 
			cout << "value: ";
			myScanf(&val); 
			val - p1; 
			cout << "substracted!" << endl;
			break;

		case 6:
			if (p1 == p2) 
				printf("p1 is equal to p2\n"); 
			else 
				printf("p1 is not equal to p2\n");
			break;

		case 7:
			if (p1 != p2) 
				printf("p1 is not equal to p2\n"); 
			else 
				printf("p1 is equal to p2\n");
			break;

		case 8:
			if (p1 > p2) 
				printf("p1 is greater than p2\n"); 
			else 
				printf("p1 is not greater than p2\n");
			break;

		case 9:
			if (p1 >= p2) 
				printf("p1 is egreater or equal to p2\n"); 
			else 
				printf("p1 is not greater or equal to p2\n");
			break;

		case 10:
			if (p1 < p2) 
				printf("p1 is less than p2\n");
			else 
				printf("p1 is not less than p2\n");
			break;

		case 11:
			if (p1 <= p2) 
				printf("p1 is less or equal than p2\n"); 
			else 
				printf("p1 is not less or equal than than p2\n");
			break;

		default:
			printf("unknown command, try again\n");
			take = 0;
			break;
		}
		take = 0;
	}
	return 0;
}

int main()
{
	menu();
	
	return 0;
}

// EOF