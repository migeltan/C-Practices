/* Passing Structure to Functions 

- When a structure is passed to a function, it is 
passed by value by default.
- Call by value.
- Type of the argument in the function 
  definition must match the type of the parameter.

  Note:
  1. Make the structure initialized globally.
*/

//Basic Structure to Functions Example in C

/*
#include <stdio.h>

struct Record{ //Global template
    char name[20];
    int age;
};

void funct(struct Record parameterrec){ //function that prints
    printf("%d\n", parameterrec.age);
}

int main(){

    struct Record argumentrec; //Initialize a structure variable
    
    argumentrec.age=19;
    funct(argumentrec); // Call by value

    getchar();
    return 0;
}
    */

//Another Example of Structure to Functions in C

#include <stdio.h>

struct record{
    char name[20];
    int PUPSISID;
    float final_average;
};

void laude(struct record student){
    if (student.final_average <= 1.15){
    printf ("%s, Congratulations!\nYou graduate as a Summa Cum Laude!\n", student.name);
    } else if (student.final_average <=1.30){
    printf ("%s, Congratulations!\nYou graduate as a Magna Cum Laude!\n", student.name);
    } else if (student.final_average <= 1.66){
    printf ("%s, Congratulations!\nYou graduate as a Cum Laude!\n", student.name);
    } else if (student.final_average <= 3.00){
    printf ("%s, Congratulations!\nYou are eligible for graduation!\n", student.name);
    } else {
}
}

int main(){

    struct record honors;

    printf("Welcome to the PUP Graduation Honors Program!\n");
    printf("Please enter the following details:\n\n");
     
    printf("Enter your name: ");
    scanf("%[^\n]", honors.name);

    printf("Enter your PUPSIS ID: ");
    scanf("%d", &honors.PUPSISID);

    printf("\nEnter your final average: ");
    scanf("%f", &honors.final_average);

    laude(honors); // Call by value
    return 0;

}


//Another Example of Structure to Functions in C
/*
#include <stdio.h>

struct product{
    char product_name[30];
    int qty;
    float bill, price;
};

struct record{
    char customer_name[30];
    struct product one[2]; // Array of structures to hold multiple products
    //Asks two products
};

void funct(struct record two[], int customer_count){
    int a, b;
    float tbill;

    for (a = 0; a < customer_count; a++) {
        tbill = 0.0;
        printf("----------------------\n");
        printf("\nCustomer name: %s\n", two[a].customer_name);

        printf("\nValues of the records are:\n");
        for (b = 0; b < 2; b++) {
            printf("|%s|\t|%d|\t|%.2f|\t|%.2f|\n",
                two[a].one[b].product_name,
                two[a].one[b].qty,
                two[a].one[b].price,
                two[a].one[b].bill);
            tbill += two[a].one[b].bill;
        }
        printf("\nTotal bill: |%.2f|\n", tbill);
    }
}

int main(){
    struct record customer[1];
    int a, b;

    printf("This program computes the total bill of two products.\n");
    printf("Please enter the following information:\n");

    for (a = 0; a < 1; a++) {
        printf("\nEnter customer name: ");
        scanf(" %[^\n]", customer[a].customer_name);
        for (b = 0; b < 2; b++) {
            printf("\nEnter product name: ");
            scanf(" %[^\n]", customer[a].one[b].product_name);
            printf("Enter number: ");
            scanf("%d", &customer[a].one[b].qty);
            printf("Enter price: ");
            scanf("%f", &customer[a].one[b].price);
            customer[a].one[b].bill = customer[a].one[b].qty * customer[a].one[b].price;
        }
    }
    funct(customer, 1); // Pass the number of customers
    return 0;
}
*/