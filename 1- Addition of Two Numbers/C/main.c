#include <stdio.h>

int main() {
    printf("Please type two numbers you want to add:");
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    printf("The sum of %d and %d is %d", a, b, (a + b));

    return 0;
}
