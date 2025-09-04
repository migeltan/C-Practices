#include <stdio.h>
#include <conio.h>

int main()
{
int num;

printf("Enter a number to check \n");
scanf ("%d", &num);

if (num<0)
goto a;

else
goto b;

a: {
printf("Negative number");
goto end;
}

b: {
printf ("Positive Number");
}

end: getch();
	
}