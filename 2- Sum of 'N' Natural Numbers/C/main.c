#include<stdio.h>

int main() {
    while (1) {
        printf("Enter the number of natural numbers you would like to be summed (0 to exit): ");
        int n;
        int r = scanf("%d", &n);
        if (r == 1) {
            if (n < 0) {
                printf("\nError: %d is a non-positive number", n);
            } else if (n == 0) {
                break;
            } else {
                int total = 0;
                for (int i = 1; i <= n; ++i) {
                    total += i;
                }
                printf("The total of 0 - %d numbers is %d\n", n, total);
            }
        } else {
            printf("\nYou must input a positive integer.");
        }
    }
    return 0;
}
