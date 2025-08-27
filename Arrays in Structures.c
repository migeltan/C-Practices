//Arrays of structures in C

/*
struct Student {
    int roll_no;    //Structure member
    char name[50];
    float marks;
};

struct Student s[60]; // Array of structures

To access:
s[0].roll_no - accesses the roll number of 1st student

Note:
1. Use loops of course to access the array of structures.

*/


//Array of structures in C Basic Program
#include<stdio.h>

struct Student{
    int pupsis;
    char name[50];
    float grades;
};

struct Student pup[60];

int main(){
    // struct Student pup[60]; // Already declared globally, can be removed

    int choice; // Declare choice before the loop

    do {

    printf("\nEnter your PUPSIS number, name, and grade for the 1st semester:\n");
    for (int i=0; i<60; i++){
        printf("\nPUPSIS number: ");
        scanf("%d", &pup[i].pupsis);
        printf("Name: ");
        scanf(" %[^\n]", pup[i].name);
        printf("Grade: ");
        scanf("%f", &pup[i].grades);
        printf("\n");

        if (pup[i].grades <=3.0){
            printf("PUPSIS: %d, Name: %s\n", pup[i].pupsis, pup[i].name);
            printf("\nYour grade: %.2f is a passing grade.\n", pup[i].grades);
        }else if (pup[i].grades > 3.0){
            printf("PUPSIS: %d, Name: %s\n", pup[i].pupsis, pup[i].name);
            printf("\nYour grade: %.2f is a failing grade.\n", pup[i].grades);
        }
    }
    
    printf("\nDo you want to enter another student's data? (1 for Yes, 0 for No): ");
    scanf("%d", &choice);

    if (choice == 0){
        break;
    }

}while(choice == 1);
    
    
return 0;
} 

//Another Example of Array of Structures in C

/*
Create a template for a structure of student record consisting of five fields:
Student ID(int), first name(string), last name(string), total units completed(int), and
accumulated grade point average(float).

//Answer:

#include <stdio.h>

struct stud_rec{

    int student_id;  // Structure member
    char first_name[50];
    char last_name[50];
    int total_units;
    float gpa;

};

*/




