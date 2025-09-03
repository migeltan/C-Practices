//Arrays to a function
/*
#include<stdio.h>
void add_one (int array[], int length);

int main(void)
{
	int a[]={2,4,9,1,3,5};
	add_one(a,6);
	for (int i=0; i<6;i++){
		printf("a[%d]=%d\n", i, a[i]);
		
	}
}
	
void add_one(int array[], int length)
{
	for (int i = 0; i<length; i++) array[i] +=1;
}
*/

#include<stdio.h>
int main()
{
	int num=20;
	
	for (int i=0;i<=num;i++)
	{
		printf ("%d", &num);
	}
	
}