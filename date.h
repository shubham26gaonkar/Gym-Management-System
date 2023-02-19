#include<time.h>
#include<string.h>
int dt();//declaration

char date[20];//global variable

int dt()//funtion to store joining date of member
{

	char todayDateStr[100];
	time_t rawtime;
	struct tm *timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	strftime(todayDateStr, 18, "%d-%b-%Y %H:%M", timeinfo);
	
	
	strcpy(date, todayDateStr);
}

