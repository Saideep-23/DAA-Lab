#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 256

// Function to preprocess the pattern for the Horspool algorithm
void preprocessPattern(char* pattern, int patternLength, int badCharacterTable[ALPHABET_SIZE]) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        badCharacterTable[i] = patternLength;
    }

    for (int i = 0; i < patternLength - 1; ++i) {
        badCharacterTable[(int)pattern[i]] = patternLength - 1 - i;
    }
}

// Function to perform string searching using Horspool algorithm
void searchHorspool(char* text, char* pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    int badCharacterTable[ALPHABET_SIZE];
    preprocessPattern(pattern, patternLength, badCharacterTable);

    int shift = 0;
    while (shift <= textLength - patternLength) {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            printf("Pattern found at index %d\n", shift);
            shift += badCharacterTable[(int)text[shift + patternLength - 1]];
        } else {
            shift += badCharacterTable[(int)text[shift + patternLength - 1]];
        }
    }
}

int main() {
    char text[1000];
    char pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    searchHorspool(text, pattern);

    return 0;
}

