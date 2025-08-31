#include <stdio.h>

int FIBO(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return FIBO(n - 1) + FIBO(n - 2);
}

int main() {
    int months = 12;
    int RABBITS[months];

    for (int i = 0; i < months; i++) {
        RABBITS[i] = FIBO(i + 1);
    }

    printf("Rabbits per month:\n");
    for (int i = 0; i < months; i++) {
        printf("Month %d: %d pairs of rabbits\n", i + 1, RABBITS[i]);
    }

    int total = RABBITS[months - 1];

    printf("\nThe total number of \e[1mrabbits at the end of the year\e[0m is: %d pairs\n", total);

    return 0;
}