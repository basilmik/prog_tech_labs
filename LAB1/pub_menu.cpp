#include "pub_menu.h"

int menu1()
{
	pubQ* Q = new pubQ;

	printf("\n MENU\n-1 exit \n1 show all q's \n2 pick a q \n3 show current q \n4 push \n5 pop \n6 calculate \n7 copy q \n8 emerge 2q's\n\n");
	int take = 0;
	while (!take)
	{
		while (1)
		{
			if (scanf("%d", &take) == 0)

				printf("invalid input!\n");
			else
				break;
			getchar();
		}

		switch (take)
		{
		case -1: return 0;

		case 1: // show all q's
			Q->show_list(); break;

		case 2: // pick a q
			Q = (pubQ*)Q->pickQ(); break;

		case 3: // show cur q
			Q->printQ(); break;

		case  4: // push		
			Q->pub_push(); break;

		case 5: //pop
			if (*(Q->get_QSIZE_PTR()) != 0)
			{
				if ((Q = Q->pub_pop()) == NULL)
					return 0;
			}
			else
				printf("cant do that with an empty q\n");
			break;
		case 6: // calc
			if (*(Q->get_QSIZE_PTR()) != 0)
				Q->pub_calc();
			else
				printf("cant do that with an empty q\n");
			break;

		case 7:// copy
			if (*(Q->get_QSIZE_PTR()) != 0)
			{ pubQ* cpyQ; cpyQ = new pubQ; Q->copyQ(cpyQ); Q = cpyQ; }
			else
				printf("cant do that with an empty q\n");
			break;

		case 8:// emerge
			if (*(Q->get_QSIZE_PTR()) != 0)
			{ pubQ* emQ; emQ = new pubQ; Q->emergeQ(emQ); Q = emQ; }
			else
				printf("cant do that with an empty q\n");
			break;

		default: printf("unknown command, try again\n"); break;

		}

		take = 0;
	}

	return 0;
}
