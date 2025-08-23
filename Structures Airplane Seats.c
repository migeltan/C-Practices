//Activity #2

#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 4


struct Seat {
    int row;
    char column;
    int assigned; // 0 for unassigned, 1 for assigned
};


void initializeSeats(struct Seat seats[ROWS][COLS]) {
    char cols[] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j].row = i + 1;
            seats[i][j].column = cols[j];
            seats[i][j].assigned = 0;
        }
    }
}


void displaySeats(struct Seat seats[ROWS][COLS]) {
    printf("\nCurrent Seat Assignments:\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j].assigned)
                printf("X\t");
            else
                printf("%c\t", seats[i][j].column);
        }
        printf("\n");
    }
}


int assignSeat(struct Seat seats[ROWS][COLS], int row, char column) {
    if (row < 1 || row > ROWS || column < 'A' || column > 'D') {
        printf("Invalid seat. Try again.\n");
        return 0;
    }

    int colIndex = column - 'A';
    if (seats[row - 1][colIndex].assigned) {
        printf("Seat %d%c is already occupied.\n", row, column);
        return 0;
    }

    seats[row - 1][colIndex].assigned = 1;
    printf("Seat %d%c assigned successfully.\n", row, column);
    return 1;
}


int main() {
    struct Seat seats[ROWS][COLS];
    initializeSeats(seats);

    int totalSeats = ROWS * COLS;
    int assignedCount = 0;
    char input[10];

    while (assignedCount < totalSeats) {
        displaySeats(seats);
        printf("\nEnter seat to assign (e.g., 2B), or type 'exit' to quit: ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        int row;
        char column;
        if (sscanf(input, "%d%c", &row, &column) == 2) {
            if (assignSeat(seats, row, column)) {
                assignedCount++;
            }
        } else {
            printf("Invalid input format. Use format like 3C.\n");
        }
    }

    printf("\nFinal seating:\n");
    displaySeats(seats);
    printf("Program ended.\n");

    return 0;
}