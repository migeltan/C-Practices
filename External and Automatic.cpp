#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

extern int a=3; //external variable
main(){
	int count; //auto variable
	int funct1(int b);
	printf("\nValue \t|%d|\n", a);
	for (count=1; count<=5; count++){
		a=funct1(count); //call by value
		/*since ang ginawa mo is funct1(count), ang logic niyan is
		magstatstart sa first iteration, so funct(1), and then it will
		perform the solution sa function, which will be 1+3=4.
		1 being the now value of b from count, and 
		3 which will do a++, the external variable */
		printf("Value of count and a in main \t|%d| |%d|\n", count, a);
		//funct1 returns 4 and a is upgraded= to 4 again in main
		//this happens since a is a global variable, it upgrades
		//and count iterates the value since it is local to main function
		getch();
	}
	
	getchar();
	return 0;

}

int funct1 (int b){
	int count;
	count=b+a++;
	printf("Value of count and a in funct1 \t|%d| |%d|\n", count, a);
	return count; //nanggaling dito ang bagong value ni a sa main
}