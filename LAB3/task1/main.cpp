// lab3 programming technology
/* Создать абстрактный базовый класс с виртуальной функцией «Сумма прогрессии». 
Создать производные классы «Арифметическая прогрессия» и «Геометрическая прогрессия». 
Каждый класс имеет два поля типа double.
Первое – первый член прогрессии, второе – постоянная разность (для арифметической) и постоянное отношение (для геометрической). 
Определить функцию вычисления суммы, где параметром является количество элементов прогрессии.
Необходимо написать для каждого класса все необходимые и требуемые конструкторы, деструктор.

• В main необходимо реализовать массив типа базового класса.
Пользователь выбирает какой класс-наследника ему необходимо создать, также число наследников программно не ограничено.

• Реализуйте статическую переменную класса для подсчета количества объектов базового класса.

• Необходимо иметь возможность сохранить данные, которые хранятся в программе в выходной файл.

• Все параметры вводятся пользователем

• Должно быть представлено максимально возможное меню пользователя, в том числе 
	редактирование, 
	добавление или 
	удаление объектов.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "math.h"

#include "arithmetic.h"
#include "geometric.h"



progression** add_prorg(progression** _old, progression* add)
{
	progression** res = new progression * [progression::size];

	if (_old != nullptr)
	{
		for (int i = 0; i < progression::size; i++)
		{
			res[i] = _old[i];	
			_old[i] = nullptr;
		}
	}
	res[progression::size] = add;
	progression::size++;

	return res;
}


void myScanf(const char* _f, void* _x)
{
	while (1)
	{
		if (scanf(_f, _x) != 1)
			printf("intvalid input, try again\n");
		else
			break;
		if (getchar());
	}
}


int menu()
{
	printf("MENU:\n 0 exit\n1 add progression\n2 edit progression\n3 delete progression\n4 calculate sum\n5 output in a file\n6 print all progressions\n");
	
	int take = 0; 

	progression** arr = nullptr;

	while (take == 0)
	{
		myScanf("%d", &take);
		switch (take)
		{
		case 0:
			return 0;
		case 1: // add
		{
			printf("add progression -- choose type: 1 arithmetic, 2 geometric\n");
			int type = 0;
			while (type == 0)
			{
				myScanf("%d", &type);
				switch (type)
				{
				case 1:
				{	
					printf("enter arithmetic progression parameters:\n");
					double a1 = 0, d = 0;
					printf("a1: "); myScanf("%lf", &a1);
					printf("d: "); myScanf("%lf", &d);
						
					arr = add_prorg(arr, new arithmetic(a1, d));
				}
				break;

				case 2:
				{
					printf("enter geometric progression parameters:\n");
					double a1 = 0, q = 0;
					printf("a1: "); myScanf("%lf", &a1);
					printf("q: "); myScanf("%lf", &q);

					arr = add_prorg(arr, new geometric(a1, q));
				}
				break;

				default:
					printf("invalid input, try again\n");
					type = 0;
				}
			}
		}
			break;

		case 2: // edit
		{
			if (progression::size == 0)
			{
				printf("there are no progressions added\n");
				break;
			}
			printf("there are %d progressions\npick one to edit:\n", progression::size);
			int edit = -1;
			
			while (edit-1 < 0 || edit-1 > progression::size-1)
				myScanf("%d", &edit);
			edit--;
			
			printf("%d's has values: ", edit+1);
			arr[edit]->print_one();
			
			printf("enter new type:\n");
			int type = 0;			
			while (type <= 0 || type > 2)
				myScanf("%d", &type);

			printf("enter new values:\n");
			double a1 = 0, c = 0;
			printf("a1: "); myScanf("%lf", &a1);
			printf((type == 1) ? "d: " : "q: "); myScanf("%lf", &c);

			progression* memo = arr[edit];
			if (type == 1)
				arr[edit] = new arithmetic(a1, c);
			if (type == 2)
				arr[edit] = new geometric(a1, c);

			delete memo;
		}	
			break;

		case 3: //delete
		{
			if (progression::size == 0)
			{
				printf("there are no progressions added\n");
				break;
			}
			printf("there are %d progressions\npick one to delete:\n", progression::size);
			int edit = -1;
			while (edit - 1 < 0 || edit - 1 > progression::size - 1)
				myScanf("%d", &edit);
			edit--;

			progression* memo = arr[edit];

			delete memo;
			for (int i = edit; i < progression::size; i++)
			{
				arr[i] = arr[i + 1];
			}

			arr[progression::size] = nullptr;
			progression::size--;

			printf("deleted!\n");
		}
			break;

		case 4: //calc
		{	
			if (progression::size == 0)
			{
				printf("there are no progressions added\n");
				break;
			}
			printf("there are %d progressions; pick one to calculate sum of:\n", progression::size);
			int calc = -1;
			while (calc - 1 < 0 || calc - 1 > progression::size - 1)
				myScanf("%d", &calc);
			calc--;

			int n = -1;
			printf("enter of how many sum to calculate:\n");
			
			while(n < 0)
			{ 
				myScanf("%d", &n);
			}

			printf("sum is %lf\n", arr[calc]->sum(n));
		}
			break;

		case 5: // output to file
		{
			if (progression::size == 0)
			{
				printf("there are no progressions added\n");
				break;
			}
			char filename[512];
			printf("enter output file name:\n");
			myScanf("%s\n", filename);

			FILE* fp = fopen(filename, "w");

			for (int i = 0; i < progression::size; i++)
			{
				arr[i]->file_output(fp);
			}

			fclose(fp);
			printf("outputed!\n");
		}
			break;

		case 6: // print
		{
			if (progression::size == 0)
			{
				printf("there are no progressions added\n");
				break;
			}
			printf("there are %d progressions:\n", progression::size);
			for (int i = 0; i < progression::size; i++)
			{
				printf("%d) ", i + 1);
				arr[i]->print_one();
			}
		}
			break;

		default:
			take = 0;
		}

		take = 0;
	}

	delete[] arr;

	return 0;
}


int main()
{
	menu();
	return 0;
}

// EOF