#include <stdio.h>
#include <string.h>

// Function prototypes
void convert_to_words(int, char[]);
void convert_hundreds(int, char[]);
void convert_tens(int, char[]);
void convert_units(int, char[]);

int main() {
    int number;
    char result[500] = "";

    // Input the currency value
    printf("Enter a currency value: ");
    scanf("%d", &number);

    // Convert the number to words
    convert_to_words(number, result);

    // Output the result
    printf("Currency in words: %s\n", result);

    return 0;
}

// Function to convert number to words
void convert_to_words(int num, char result[]) {
    if (num == 0) {
        strcpy(result, "zero");
        return;
    }

    if (num / 1000 > 0) {
        convert_hundreds(num / 1000, result);
        strcat(result, " thousand ");
        num %= 1000;
    }
    if (num / 100 > 0) {
        convert_hundreds(num / 100, result + strlen(result));
        strcat(result, " hundred ");
        num %= 100;
    }
    if (num > 0) {
        strcat(result, "and ");
        convert_tens(num, result + strlen(result));
    }
}

// Function to convert hundreds place
void convert_hundreds(int num, char result[]) {
    convert_units(num, result);
}

// Function to convert tens and units place
void convert_tens(int num, char result[]) {
    const char *ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    const char *teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    const char *tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    if (num < 10) {
        convert_units(num, result);
    } else if (num < 20) {
        strcat(result, teens[num - 10]);
    } else {
        strcat(result, tens[num / 10]);
        if (num % 10 > 0) {
            strcat(result, "-");
            convert_units(num % 10, result + strlen(result));
        }
    }
}

// Function to convert units place
void convert_units(int num, char result[]) {
    const char *ones[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    if (num > 0) {
        strcat(result, ones[num]);
    }
}