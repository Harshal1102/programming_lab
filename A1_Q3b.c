#include <stdio.h>
#include <stdbool.h>
#include<math.h>

#define LIMIT 28123

int sum_of_divisors(int n) {
    int sum = 1; 
    int rem=0;
for(int i = 2; i <=n/2; i++)  
                     {  
                              rem = n % i;  
                             if (rem == 0)  
                                        {  
                                               sum = sum + i;  
                                         }
                     }
    return sum;
}
void find_abundant_numbers(int limit, bool abundant[]) {
    for (int i = 12; i <= limit; i++) {
        if (sum_of_divisors(i) > i) {
            abundant[i] = true;
        }
    }
}

void mark_abundant_sums(int limit, bool abundant[], bool can_be_written_as_sum[]) {
    for (int i = 12; i <= limit; i++) {
      //here we start from 12 as 12 is the first abundent number 
        if (abundant[i]) {
            for (int j = i; j <= limit; j++) {
                if (abundant[j] && i + j <= limit) {
                    can_be_written_as_sum[i + j] = true;
                }
            }
        }
    }
}


int main() {
  //declaration of boolean variables
    bool abundant[LIMIT + 1] = { false };
    bool can_be_written_as_sum[LIMIT + 1] = { false };
    
    find_abundant_numbers(LIMIT, abundant);
    mark_abundant_sums(LIMIT, abundant, can_be_written_as_sum);
    
    int total_sum = 0;
    for (int i = 1; i <= LIMIT; i++) {
        if (!can_be_written_as_sum[i]) {
            total_sum += i;
        }
   }
    printf("The sum of all positive integers which cannot be written as the sum of two abundant numbers is %d\n", total_sum);
    return 0;
}