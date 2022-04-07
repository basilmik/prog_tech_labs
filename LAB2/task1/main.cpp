// lab 2 task 1
/* —оздать класс УќчередьФ. 
перегрузить : оператор постфиксного инкрементировани€ как метод дл€ добавлени€ элемента в очередь, значение с клавиатуры; 
оператор постфиксного декрементировани€ как метод дл€ извлечени€ элемента из очереди; 
оператор префиксного инкрементировани€ как дружественную функцию дл€ увеличени€ всех чисел в очереди на единицу; 
оператор префиксного декрементировани€ как дружественную функцию дл€ уменьшени€ всех чисел в очереди на единицу; 
оператор ! как метод дл€ проверки очереди на пустоту.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "classQueue.h"


int menu()
{
	int take = 0;
	Queue Q;
	printf("0 exit   1 push   2 pop    3 +1All    4 -1All   5 show all  6 isEmpty\n");
	
	while (!take)
	{
		while (1)
		{
			if (scanf("%d", &take) != 0)
				break;
			printf("unvalid input, try again\n");
			if (getchar());
		}

		switch (take)
		{
		case 0:
			return 0;
		case 1: Q++; break;
		case 2: Q--; break;
		case 3: ++Q; break;
		case 4: --Q; break;
		case 5: Q.show_all(); break;
		case 6: 
			if (!Q)
				printf("empty\n");
			else
				printf("not empty\n");
			break;

		default:
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