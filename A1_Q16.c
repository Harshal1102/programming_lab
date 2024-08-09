#include <stdio.h>

// Function to compute factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 1000000 - 1;  // Zero-based index
    int result[10];
    int n = 10;

    for (int i = 0; i < n; i++) {
        int fact = factorial(n - 1 - i);
        int index = target / fact;
        result[i] = digits[index];

        // Shift the digits array to remove the used digit
        for (int j = index; j < n - 1 - i; j++) {
            digits[j] = digits[j + 1];
        }
        target %= fact;
    }

    // Print the result
    printf("Millionth lexicographic permutation: ");
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    return 0;
}