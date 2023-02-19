int pack();//declaration of funtion
int plus = 3,pro = 2, prime = 3; //membership plans limit
int pack()
{
	int flag = 1;
	int ch = 1; //plus = 3,pro = 2, prime = 3;
	do{
		printf("\n");
		printf("\t\tChoose membership pack: \n");
		
		printf("\t\t1. Plus - 3 months\n");
		printf("\t\t2. Pro - 6 months\n");
		printf("\t\t3. Prime - 12 months\n");
		printf("\t\tDefault is 3 months\n");
		printf("\t\t->> ");
		scanf("%d", &ch);
		//printf("\n");
		if(ch == 1)//for PLUS plan
		{
			if(plus == 0)
			{
				printf("\t\tSlots are booked. Please choose another Plan\n");
			}
			else
			{
				printf("\t\t ----PLUS---- \n");
				printf("\t\t---3 months---\n");
				printf("\t\t-- Rs.2222/- --");
				plus--;
				return 1;
			}
			
		}
		else if(ch == 2)//for PRO plan
		{
			if(pro == 0)
			{
				printf("\t\tSlots are booked. Please choose another Plan\n");
			}
			else
			{
				printf("\t\t ----PRO---- \n");
				printf("\t\t---6 months---\n");
				printf("\t\t-- Rs.4000/- --\n");
				pro--;
				return 2;
			}
		}
		else if(ch == 3)//for PRIME plan
		{
			if(prime == 0)
			{
				printf("\t\tSlots are booked. Please choose another Plan\n");
			}
			else
			{
				printf("\t\t ----PRIME ---- \n");
				printf("\t\t---12 months---\n");
				printf("\t\t-- Rs.7000/- --\n");
				prime--;
				return 3;
			}	
		}
		else
		{
			printf("\t\tInvalid Choice\n");
		}
	}while(flag == 1);
}
