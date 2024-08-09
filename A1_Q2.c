#include <stdio.h>

int main() {
    int num,sum=0,temp;
    printf("Enter a number : ");
    scanf("%d",&num);
    temp=num;
    while(num)
    {
        int k=num%10;
        sum=sum+(k*k*k);
        num=num/10;
    }
    if(temp==sum)
        printf("\nArmstong number");
    else
        printf("\nNot Armstrong number");
    return 0;
}