//#include<stdio.h>
#include<string.h>
void verification();//declaration of funtion
//funtion to verify, and allow trainer to perform different operations
//if pin is wrong enter again
//if pin is correct , ger access to perform operation
void verification()
{
	//int pass, 
	int x = 1, setpass = 1234;
	int i;
	char ch;
	char pwd[5];
	system("cls");
	printf("\t\t -------------------- \n");
	printf("\t\t|    Verification    |\n");
	printf("\t\t -------------------- \n");
	while(x != 0)
	{
		printf("\t\t Enter pin: ");
		//scanf("%d", &pass);
		while( i < 4)
		{
			ch = _getch();
			pwd[i] = ch;
			i++;
			printf("*");
		}
		pwd[i] = '\0';
		
		if(strcmp(pwd, "1234") == 0)
		{
			printf("\n\t\tpin matched!!");
			x = 0;
		}
		else
		{
			printf("\n\t\t\aWarning!! \n\t\tIncorrect pin\n");
			i = 0;
		}
		printf("\n");
	}
	//system("cls");
}
