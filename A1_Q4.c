#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int checkAmicable(int sum1, int sum2, int number1, int number2){
    if(sum1 == number2 && sum2 == number1){
        return 0;
    }
    else
        return 1;
}

int sumDivisors(int number)
{
    int sum = 0;
    
    for(int i=1; i<=sqrt(number); i++){
        if(number % i == 0){
            sum += i;

            if(number / i != i && number / i != number){
                sum += number/i;
            }
        }
        
    }

    return sum;
}

int main(){
    
    int number1;
    int number2;
    
    printf("Enter number1:");
    scanf("%d", &number1);
    
    printf("Enter number2:");
    scanf("%d", &number2);
    
    int number1_divisor_sum = sumDivisors(number1);
    int number2_divisor_sum = sumDivisors(number2);
    
    if(checkAmicable(number1_divisor_sum, number2_divisor_sum, number1, number2) == 0){
        printf("The numbers are amicable");
    }
    else{
        printf("The numbers are not amicable");
    }
    
}