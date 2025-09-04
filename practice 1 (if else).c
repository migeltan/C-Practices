#include <stdio.h>
int main ()
{
	int num;
	
	printf("Enter a positive value: \n");
	scanf("%d", &num);
	
	if (num%2==0)
	{
		printf("Value is even");
	} else
	{
		printf ("Value is odd");
	} 
	
	
	return 0;
}