#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_PALINDROME 100

int isPalindrome(const char *string, unsigned long length);

int main() {
    while (1) {
        printf("Enter your possible palindrome (0 to exit): ");

        char *palindrome = malloc(MAX_PALINDROME);
        fgets(palindrome, MAX_PALINDROME, stdin);

        unsigned long len = strlen(palindrome);
        if (len == 2 && palindrome[0] == '0') {
            break;
        }

        printf("Palindrome: %s\n", isPalindrome(palindrome, len) == 1 ? "True" : "False");
        free(palindrome);
    }
    return 0;
}

int isPalindrome(const char *string, unsigned long length) {
    for (int i = 0; i < length / 2; ++i) {
        unsigned long reverseIndex = length - i - 2;
        if (string[i] != string[reverseIndex]) {
            return 0;
        }
    }
    return 1;
}
