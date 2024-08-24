#include <stdio.h>

int main() {
    int num, original_num, sum = 0;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    original_num = num;
    
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    
    if (original_num % sum == 0) {
        printf("%d is a Harshad number.\n", original_num);
    } else {
        printf("%d is not a Harshad number.\n", original_num);
    }
    
    return 0;
}
