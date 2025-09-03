/* Functions - provides modularity to program's structure, makes code reusable.
- a section of a program which performs a specific task. The task assigned
to a function is performed whenever C encounters the function name.
- A function is actually a subprogram that is, a function performs a task 
within a program and is written in a form similar to C main program. 
- Smaller, complete, and independent subprograms.
- For a special purpose. Each sub program is called a module or a function.
- Modularization (Dividing to smaller programs)

2 functions:
- User-defined functions and Library Functions


syntax:
type function_name (parameter list)
{
declaration > local variables
statement;
}
*/

/*#include<stdio.h>


double add(double x, double y);

int main (void)
{
	printf("%f\n", add (10.5,5.9));
}


double add(double x, double y)
{
	double result = x+y;
	return result;
} */

/* #include<stdio.h>
void f(int a[]) {
	int i;

	for (i = 0; i < 3; i++)
		a[i]++;
}
main() {
	int i, a[] = {10, 20, 30};
	
	f(a);
	for(i = 0; i < 3; ++i)
		printf("%d", a[i]);
}*/

#include<stdio.h>
void print_two(float a, float b);

int main (void)
{
	float x= 2.5, y=4.2;
	print_two(x,y);
}

void print_two(float a, float b)
{
	printf ("%f\n%f\n", a,b);
}
