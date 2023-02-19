#include "struct.h"
#include "date.h"
#include "verification.h"
#include "membership.h"
#include<stdlib.h>


//declaration on functions

void Register();
void IdCheck();
int idcheck(int);
void AddMember();
void DeleteMember();
void DisplayAll();
void Member();
void Tariner();

//global variables
int c;
//char date[20];


void Register()
{
	system("cls");
	printf("\t\t1.Register........\n");

}
//to search member, by using ID 
//check if member exists or not
void IdCheck()
{
	if(head == NULL)
	{
		printf("\n");
		printf("\t\tList is empty.\n");
	}
	else
	{
		printf("\n");
		printf("\t\t -----------------------\n");
	    printf("\t\t|     Search Member     |\n");
	    printf("\t\t -----------------------\n");
	    int check;
	    int flag = 0;
	    printf("\t\tEnter Member ID to Check : ");
	    scanf("%d", &check);

	    struct node * temp;
	    temp = head;
	    while(temp != NULL)
	    {
	        if( temp->id == check)
	        {
	            flag = 1;
	            break;
	        }
	        temp = temp->next;
	    }
	    current = temp;
	    if(flag == 1)
	    {
	        printf("\t\tMember ID %d  found\n", current->id);
	        printf("\n\t\tCATEGORY  ===  ID  ====  NAME  =====   CONTACT   =====    MEMBERSHIP PLAN    ====  DATE OF JOINING");//feilds to be printed
			printf("\n\t\tMember  ===  %d  ====  %s  =====   %llu   =====    %s    ====     %s\n", current->id, current->name, current->contact, current->package, current->since);//data of member
	    }
	    else
	    {
	        printf("\t\tMember Not Found !!\n");
	    }
	}
}

//check id of member, if already exists then other member cannot use same ID
//ID is unique for each member
int idcheck(int srn)
{
	struct node *ptr = head;
	while(ptr != NULL)
	{
		if(ptr->id == srn)
		{
			printf("\n\t\tId already exist. Try new ID\n");
			//AddMember();
			//main(;
			return 1;
		}else
		{
			ptr=ptr->next;
		}		
	}
}

//to add member in list of gym member
//give admission to join gym
void AddMember()
{
	struct node *ptr, *temp;
	char item[20];
	int srn = 0;
	int data;
	unsigned long long int phn;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr == NULL)
	{
		printf("\nOVERFLOW");
	}
	else
	{
		int id;
		while(1){
			printf("\n\t\tEnter id: ");
			scanf("%d", &srn);
			id = idcheck(srn);
			if(id != 1)
			{
				break;
			}
		}
		
		printf("\n\t\tEnter name: ");
		scanf("%s", item);
		
		printf("\n\t\tEnter contact: ");
		scanf("%llu", &phn);
		
		//printf("\n\t\tEnter Package: ");
		//scanf("%s", pac)
		int data = pack();
		if(data == 1)
		{
			//char plan1 = "plus";
			strcpy(ptr->package, "PLUS");
		}
		else if(data == 2 )
		{
			//char plan2 = "Pro";
			strcpy(ptr->package, "PRO");
		}
		else if(data == 3)
		{
			//char plan3 = "Prime";
			strcpy(ptr->package, "PRIME");
		}
		ptr->id = srn;
		strcpy(ptr->name, item);
		ptr->contact = phn;
		dt();
		strcpy(ptr->since, date);
		
		ptr->next = NULL;
		ptr->prev = NULL;
		
		
		if(head == NULL)
		{
			head = tail = ptr;
		}
		else{
			ptr->prev = tail;
			tail->next = ptr;
			tail = ptr;
		}
	}
	printf("\n\t\tMember added\n");
}

//To remove member from gym
//cancel membership
void DeleteMember()
{
	int flag = 0;
	if(head == NULL)
	{
		printf("\n\t\tList of members is empty.\n");
	}
	else
	{
		
		int id;
		printf("\t\tEnter Id to delete member: ");
		scanf("%d", &id);
		struct node * temp = head;  
		
		while (temp != NULL)
		{
			if(head == temp)
	    	{
	        	if(temp->id == id)
	        	{
					head = head->next;//to remove first member
	            	head->prev = NULL;
	            		
	            	free(temp);
	            	flag = 1;
	            	printf("\t\tMember  has been removed.\n");	
	            	return;
				}	
	       	}
	       	//to remove any random member
			else if (temp->id == id)
			{
				if (temp->prev == NULL && temp->next == NULL)
				{
			        head = NULL;
			        free(temp);
				}
				else if (temp->prev == NULL)
				{		
			        temp->next = head;
			        head->prev = NULL;
			        free(temp);
				}
				else if (temp->next == NULL)
				{
			        temp->prev->next = NULL;
					free(temp);
				}
			    else
				{
			        temp->next->prev = temp->prev;
					temp->prev->next = temp->next;
					free(temp);
				}
				flag = 1;
				printf("\t\t Member  has been removed.\n");
				return;
			}
			temp = temp->next;
		}		
	}
	if(flag == 0)
	{
		printf("\n\t\tMember not found.\n");
	}
}

//Display list of all members registered in gym
void DisplayAll()
{
	int i=1;
	struct node *ptr = head;
	printf("\n\t\tMembers: list\n");
	printf("\nSr.No. CATEGORY  ===  ID  ====  NAME  =====   CONTACT   =====    MEMBERSHIP PLAN    ====    DATE OF JOINING \n");
	while(ptr != NULL)
	{
		printf("  %d. Member  ===   %d   ====   %s   =====    %llu    =====     %s    ====    %s\n",i,ptr->id,ptr->name,ptr->contact,ptr->package,ptr->since);
		ptr = ptr->next;
		i++;
	}
}

void checkPlans()
{
	system("cls");
	printf("\t\t -----------------------\n");
	printf("\t\t|    Available Plans    |\n");
	printf("\t\t -----------------------\n");
	printf("\t\t1. Plus - 3 months - Rs.2222/-\n");
	printf("\t\t2. Pro - 6 months - Rs.4000/-\n");
	printf("\t\t3. Prime - 12 months - Rs.7000/-\n");
}
//options for member to select particular operation
void Member()
{
	int ch1;
	do{
	//system("cls");
		printf("\n");
		printf("\t\t ----------------------\n");
		printf("\t\t|    BeFit   Member    |\n");
		printf("\t\t ----------------------\n");
		
		printf("\t\tNew member? Register now!!\n");
		printf("\t\t1.Register\n");
		printf("\t\t2.Check details\n");
		printf("\t\t3.Check Plans\n");
		printf("\t\t4.Go Back\n");
		printf("\t\t->>");
		scanf("%d", &ch1);
		switch(ch1)
		{
			case 1: 
				AddMember();
				break;
			case 2: 
				IdCheck();
				break;
			case 3: 
				checkPlans();
				break;
			case 4: 
				break;	
			default: 
				printf("Invalid choice\n");
				break;
		}
	}while(ch1 != 4);//when choice is 3 , exit the loop
}

//options for trainer to select particular operation
void Tariner()
{
	int ch1 = 0;
	verification();//call funtion to verify the password to enter the trainer page
	do{
	//system("clear");
		printf("\n");
		printf("\t\t ---------------------\n");
		printf("\t\t|  BeFit   Trainer    |\n");
		printf("\t\t ---------------------\n");
		
		printf("\t\tWhat you want to do: \n");
		printf("\t\t1.Add member\n");
		printf("\t\t2.Search member\n");
		printf("\t\t3.Delete member\n");
		printf("\t\t4.Check list\n");
		printf("\t\t5.Go Back\n");
		printf("\t\t->>");
		scanf("%d", &ch1);
		switch(ch1)
		{
			case 1: 
				AddMember();
				break;
			case 2: 
				IdCheck();
				break;
			case 3: 
				DeleteMember();
				break;
			case 4: 
				DisplayAll();
				break;
			case 5:
				break;
			default: 
				printf("Invalid choice\n");
				break;
		}
	}while(ch1 != 5);//when choice is 5, exit the loop
}
