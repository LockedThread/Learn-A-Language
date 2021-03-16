#include <stdio.h>
#include <stdlib.h>

float readFloat(char *buffer);

float ask(char *type);

int main() {
    printf("Area of Triangle. Enter base and height to receive the Area (0 to exit).\n");
    do {
        char *line = NULL;
        float base, height;

        base = ask("base");
        if (base == -1) {
            break;
        }
        height = ask("height");
        if (height == -1) {
            break;
        }
        free(line);
        float area = (base * height) * 1 / 2;
        printf("Base: %.2f, Height: %.2f, Area: %.2f\n", base, height, area);
    } while (1);
    return 0;
}

float ask(char *type) {
    float f;
    while (1) {
        char *buf = NULL;
        printf("Enter the %s: ", type);
        scanf("%s", buf);
        f = readFloat(buf);
        free(buf);
        if (f < 0) {
            printf("You must use positive real numbers.\n");
            continue;
        } else if (f == 0) {
            return -1;
        }
        break;
    }
    return f;
}

float readFloat(char *buffer) {
    size_t len;
    size_t read = getline(&buffer, &len, stdin);
    if (read == -1) {
        printf("No line read...\n");
    } else {
        return strtof(buffer, NULL);
    }
    return -1;
}