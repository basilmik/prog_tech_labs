// lab 1 tech prog

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include "pub_menu.h"
#include "pro_menu.h"
#include "pri_menu.h"



int main_menu()
{
	int mode = 0;
	printf("choose type 1 -- public, 2 -- protected, 3 -- private\n");

	while (!mode) {
		while (1) {
			if (scanf("%d", &mode) == 0)
				printf("invalid input, try again\n");
			else
				break;
			getchar();
		}

		switch (mode)
		{
		case 1:
			menu1(); return 0;
		case 2:
			menu2(); return 0;
		case 3:
			menu3(); return 0;
		default:
			printf("unknown type, try again\n"); break;
		}

		mode = 0;
	}
}


int main()
{
	main_menu();
	
	return 0;
}

// EOF