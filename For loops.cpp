/* For loops - executes a statement repeatedly until it remains true.
- structure consists of 3 parts:
1. Variable initialization
2. Condition
3. Variable update

for (vi; con; vu)
{
statements;
} */

/* #include<stdio.h>
int main()
{
	int i;
		for(i=1; i<=10; i++){
		if (i % 2 != 0){
			printf("Odds are = %d \n", i);
		}
	}
} */

#include<stdio.h>
int main()
{
	int i, a=2, prod;
	
	for(i=1; i<=100; i++){
		prod=i*a;
		printf("%d * %d = %d\n",i, a, prod);
		
	}
}