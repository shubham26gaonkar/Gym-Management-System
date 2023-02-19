#include "main.h"
//main menu
void main()
{
	int ch1 = 0;
	do{
		system("cls");
		printf("\n\n");
		printf("\t\t ---------------------\n");
		printf("\t\t|  Welcome  to  BeFit | \n");
		printf("\t\t ---------------------\n");
	
		printf("\t\tChoose who you are: \n");
		printf("\t\t1.Member\n");
		printf("\t\t2.Trainer\n");
		printf("\t\t3.Exit\n");
		printf("\t\t->>");
		scanf("%d", &ch1);
		switch(ch1)
		{
			case 1: 
				Member();//call member function and perform specific operations
				break;
			case 2: 
				Tariner();//call trainer funtion and perform specific operations
				break;
			case 3:
				break;
			default: 
				printf("Invalid choice\n");
		}
	}while(ch1 != 3);
}
