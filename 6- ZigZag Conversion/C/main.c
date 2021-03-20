#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main() {
    printf("Enter string to zigzag: ");

    char *functionString = malloc(200);

    fgets(functionString, 200, stdin);

    return 0;
}

char *convert(char *string, int numRows) {

}
