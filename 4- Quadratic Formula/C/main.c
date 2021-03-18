#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_FUNCTION_SIZE 255

void removeSpaces(char *s);

void getQuadraticFunctionVariables(char *sourceString, double *a, double *b, double *c);

double evaluateQuadraticFunction(int pos, double a, double b, double c);

int main() {
    printf("Quadratic Formula Calculator. Enter your Quadratic Function (0 to exit).\n");
    do {
        printf("\nEnter your Quadratic Function: ");

        char *functionString = malloc(MAX_FUNCTION_SIZE + 1);

        fgets(functionString, MAX_FUNCTION_SIZE, stdin);

        if (strcmp(functionString,"0") == 0) {
            // Exit
            break;
        }

        // Removes trailing
        unsigned long len = strlen(functionString);
        if (len > 0 && functionString[len - 1] == '\n')
            functionString[len - 1] = '\0';

        removeSpaces(functionString);
        double a, b, c;
        getQuadraticFunctionVariables(functionString, &a, &b, &c);
        free(functionString);
        double posRoot = evaluateQuadraticFunction(1, a, b, c), negRoot = evaluateQuadraticFunction(0, a, b, c);
        printf("\nposRoot=%f, negRoot=%f", posRoot, negRoot);
    } while (1);
}

void removeSpaces(char *s) {
    const char *d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while ((*s++ = *d++));
}

double evaluateQuadraticFunction(int pos, double a, double b, double c) {
    double sub = sqrt(b * b - 4 * (a * c));
    return (pos ? -b + sub : -b - sub) / (2 * a);
}

void getQuadraticFunctionVariables(char *sourceString, double *a, double *b, double *c) {
    char *copy = strdup(sourceString);
    char *delim = "+-";
    char *p = strtok(sourceString, delim);

    int count = 0;
    while (p != NULL) {
        char delimUsed = copy[p - sourceString - 1];

        char buffer[100];

        int counter = 0;
        if (delimUsed == '+' || delimUsed == '-') {
            buffer[0] = delimUsed;
            counter = 1;
        }
        for (int i = 0; i < strlen(p); i++) {
            char current = p[i];
            if (current != 'x') {

                buffer[counter++] = current;
            } else {
                break;
            }
        }
        double coefficient = strtod(buffer, NULL);
        memset(buffer, 0, strlen(buffer));

        switch (count) {
            case 0:
                *a = coefficient;
                break;
            case 1:
                *b = coefficient;
                break;
            case 2:
                *c = coefficient;
                break;
            default:
                // TODO: idk
                break;
        }
        count++;
        p = strtok(NULL, "+-");
    }
}
