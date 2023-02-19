#include<stdio.h>

struct node//user defined data type sturct node
{
	int id;//to store member ID
	char name[20];//store member name
	unsigned long long int contact;//to store contact no of member
	char since[20];//date of joining
	char package[10];	
	struct node * prev;//pointter pointing to previous node(member)
	struct node * next;//pointer pointing to next node(member)
};
struct node *head = NULL, *tail = NULL;//glabal pointers pointing to struct node data type
struct node *current = NULL;
