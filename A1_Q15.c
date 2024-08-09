#include <stdio.h>
#include <math.h>

// Function to count the number of divisors of a given number
int count_divisors(int num) {
    int count = 0;
int sqrt_num = (int) sqrt(num);
    
for (int i = 1; i <= sqrt_num; i++) {
        if (num % i == 0) {
            if (i == num / i) {
                count++; // Perfect square
            } else {
                count += 2; // Pair of divisors
            }
        }
}
    return count;
}
int main() {
    int n = 1;
    int triangle_number;
    int divisors_count;
    
    while (1) {
        // Calculate the nth triangular number
        triangle_number = n * (n + 1) / 2;
        
        // Count the number of divisors of the triangular number
        divisors_count = count_divisors(triangle_number);
        
        // Check if the number of divisors is greater than 500
        if (divisors_count > 500) {
            break;
        }
        
        n++;
    }
    
    printf("The first triangular number with over 500 divisors is %d (Triangular number %d)\n", triangle_number, n);
    
    return 0;
}