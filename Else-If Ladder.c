#include <stdio.h>

int main ()
{
	int grades;
	
	printf("Please enter your grade, don't include a percent sign: \n");
	scanf("%d", &grades);
	
	if (grades>=90)
	{
		printf ("Your grade is classified with honors, congrats!");
	}
	else if (grades>=80)
	{
		printf ("Your grade is classified as passed, good job.");
	}
	else if (grades>=75)
	{
		printf ("Your grade is classified as a passing grade.");
	}
	else if (grades<=74)
	{
		printf ("Your grade is a failing grade, consult with your professor.");
	}
	else
	{
		printf ("Error");
	}
}