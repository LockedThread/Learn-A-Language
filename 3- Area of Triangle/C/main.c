#include <stdio.h>

int main() {
    while (1) {
        printf("\nEnter the base and height of a triangle for the area (0 for exit): ");
        float base, height;
        int result = scanf("%f %f", &base, &height);

        //printf("%i %f %f\n", result, base, height);

        if (result == 0) {
            break;
        } else if (result == 1) {
            if (base == 0) {
                continue;
            }
        } else {
            float area = (base * height) * 1 / 2;
            printf("The area of that triangle is %.1f", area);
        }
    }

    return 0;
}