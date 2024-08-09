#include <stdio.h>
#include<math.h>

double calculateSeriesSum(double x, int n) {
    double sum = 0.0;
    double term;
    int sign = 1;  // Alternates between 1 and -1

    for (int i = 1; i <= n; i++) {
        term = sign * (pow(x, i) / i);
        sum += term;
        sign = -sign;  // Alternate the sign
    }

    return sum;
}
int main() {
    double x;
    int n;

    // Input for x and n
    printf("Enter a value for x (-1 < x <= 1): ");
    scanf("%lf", &x);

    // Ensuring x is within the required range
    if (x <= -1 || x > 1) {
        printf("Error: x must be in the range -1 < x <= 1\n");
        return 1;
    }

    printf("Enter a value for n (n > 100): ");
    scanf("%d", &n);

    // Ensuring n is greater than 100
    if (n <= 100) {
        printf("Error: n must be greater than 100\n");
        return 1;
    }

    // Calculate and display the series sum
    double sum = calculateSeriesSum(x, n);
    printf("The sum of the series is: %lf\n", sum);

    return 0;
}


