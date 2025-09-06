#include <stdio.h>
#include <string.h>

int main() {
    int i, j, n = 10;
    char date[6];

    printf("Hi Jaya, M/D format (e.g., 1/8): ");
    scanf("%s", date);

    printf("\n");
    for (i = n / 2; i <= n; i += 2) {
        for (j = 1; j < n - i; j += 2) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = n; i >= 1; i--) {
        for (j = i; j < n; j++) {
            printf(" ");
        }
        for (j = 1; j <= (i * 2) - 1; j++) {
            if (i == n / 2 && strcmp(date, "1/25") == 0 && j >= n / 2 - 2 && j <= n / 2 + 2) {
                printf("*");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }

    if (strcmp(date, "1/25") == 0) {
        printf("\n\e[1mHappy Birthday, Jaya[0m\n");
    }

    return 0;
}
