#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void characterStuffing(char* input, int inputSize, char* output) {
    int i, j = 0;
    char escapeChar = 'd';

    output[j++] = 'd';
    output[j++] = 'l';
    output[j++] = 'e';
    output[j++] = 's';
    output[j++] = 't';
    output[j++] = 'x';

    for (i = 0; i < inputSize; i++) {
        if (input[i] == escapeChar) {
            output[j++] = escapeChar;
            output[j++] = 'd';
            output[j++] = 'l';
            output[j++] = 'e';
            output[j++] = escapeChar;
            output[j++] = 'd';
            output[j++] = 'l';
            output[j++] = 'e';
        } else {
            output[j++] = input[i];
        }
    }

    output[j++] = escapeChar;
    output[j++] = 'd';
    output[j++] = 'l';
    output[j++] = 'e';
    output[j++] = 'e';
    output[j++] = 't';
    output[j++] = 'x';
    output[j] = '\0';
}

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH * 2]; // Assuming maximum output size as twice the input size

    printf("Enter string: ");
    scanf("%s", input);

    int inputSize = strlen(input);

    printf("Frame after stuffing:\n");

    characterStuffing(input, inputSize, output);

    printf("%s\n", output);

    return 0;
}