#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_PALINDROME 100

char *getLongestPalindromicSubstring(const char *string, unsigned long length);

int main() {
    while (1) {
        printf("Enter your possible palindrome (0 to exit): ");

        char *palindrome = malloc(MAX_PALINDROME);
        fgets(palindrome, MAX_PALINDROME, stdin);

        unsigned long len = strlen(palindrome);
        if (len == 2 && palindrome[0] == '0') {
            break;
        }
        if (len > 0 && palindrome[len - 1] == '\n')
            palindrome[len - 1] = '\0';

        printf("len=%lu", len);
        printf("\nLongest Palindromic Substring: %s\n", getLongestPalindromicSubstring(palindrome, len));
        free(palindrome);
    }
    return 0;
}

char *getLongestPalindromicSubstring(const char *string, unsigned long length) {
    char *longestSubstring = (char *) malloc(sizeof(char) * length);
    char *current = (char *) malloc(sizeof(char) * length);

    int longestLength = 0, currentLength = 0;

    for (int i = 0; i < length / 2; ++i) {
        char currentChar = string[i];
        unsigned long reverseIndex = length - i - 2;
        if (currentChar == string[reverseIndex]) {
            strcat(current, &currentChar);
        } else {
            if (currentLength >= longestLength) {
                strcpy(longestSubstring, current);
                longestLength = currentLength;
            }
            currentLength = 0;

            for (int j = 0; j < strlen(current); ++j) {
                current[j] = 0;
            }
        }
        currentLength++;
    }
    return longestSubstring;
}
//abchlsadkjfhcba
