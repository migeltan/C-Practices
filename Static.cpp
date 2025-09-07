#include<stdio.h>
#include<conio.h>

int a=100; int b=200; //external variable
int funct2(int x);
int funct1(int y);

int main(){
	int count, B;
	//int funct1(int y);
	
	for(count=1; count <=5; ++count)
	{
		B=funct1(count); 		//1. tinawag niya si funct1
		printf("\nValue of B%d= %d\t",count, B);
		printf("\n");
		
		getch();
		
	}
	return 1;
}

funct1(int y){ 					/*2. since tinawag to ni main, ang value ni parameter y
								will be the count, which ia currently 1.*/
	int c, d;
	//int fuct2(int x);
	c=funct2(y); 				//3. Then tinawag ni funct1 si funct2,
								//6. c is now equal to prod, which is 1. 
	//ternary operator, basically an if-else statement
	//if (c<100){ a+c;} else { b;}
	d=(c<100) ? (a+c) : b;	
	return d;
	}

funct2(int x){ 					/*4. Since tinawag to ni funct1, execute lang below.
								ang prod since static, magiging 1, then ang x based sa value from the
								function na tumawag sakaniya, will be 1, dahil 1 ang value nung 1
								na nanggaling sa main, which is count, from the iteration.*/
	static int prod = 1; 		/*static variables, meaning when the value changes from a 
								previous run, itll retain the value until the next execution of this function.*/
	prod *= x;
	//funct3(prod);
	return prod; 				/*5. prod will now return sa tumawag na function, 
								which is funct2*/
}

/*funct3(int prod){
	printf("\nProduct=%d", prod);
}*/