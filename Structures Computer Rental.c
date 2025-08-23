//Activity #1 for Structures

#include <stdio.h>

// defines a structure to store computer usage information
struct ComputerUsage { //used a structure
    int computer_ID; //para sa id
    int time_in;   // in 24-hour format, e.g., 9 for 9AM, 14 for 2PM
    int time_out;  // in 24-hour format
};

int main() {
	
    struct ComputerUsage usage; //initialize nung structure def
    //usage para sa variable type sa pagstore ng int input
    int hours_spent;
    float amount_to_pay;
    const float RPH = 12.0; //rate is constant

    // the input selection
    printf("\nEnter Computer ID: "); //kahit ano naman ilagay ni user
    scanf("%d", &usage.computer_ID); //goes to the structure and is stored

    printf("\nEnter Time-IN (24-hour format, e.g., 9 for 9AM, 14 for 2PM): ");
    scanf("%d", &usage.time_in); // same in this

    printf("\nEnter Time-OUT (24-hour format): ");
    scanf("%d", &usage.time_out); // as well as this

    // user vlidation dapat indi mas mataas timeout kay yimein, time in less 0, and timout 
    //being greater than 24 hrs timeline
    if (usage.time_out < usage.time_in || usage.time_in < 0 || usage.time_out > 24) {
        printf("\nInvalid time input. Time-OUT must be greater than Time-IN and within 0 to 24.\n");
        return 1; // exit with error
    }

    // computation section
    hours_spent = usage.time_out - usage.time_in; //compute nito yung time ng gamit sa pc
    amount_to_pay = hours_spent * RPH; //then multiplies sa rate para pambayad

    // this is for da output section
    printf("\nABC Computer Center Daily Monitoring Report\n\n");
    printf("Computer ID: %d\n", usage.computer_ID);
    printf("Time-IN: %d:00\n", usage.time_in);
    printf("Time-OUT: %d:00\n", usage.time_out);
    printf("Number of hours used: %d\n", hours_spent);
    printf("Amount to be paid: %.2f PHP\n", amount_to_pay);

    return 0;
}
