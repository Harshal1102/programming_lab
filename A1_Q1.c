#include<stdio.h>
#include<stdbool.h>

//function to compute GCD
int gcd(int a, int b)
{
    int temp;
    while(b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
//Function to check numbers are co-prime or not
bool coprime(int a, int b)
{
    int flag=gcd(a,b);
    if(flag==1)
    return true;
    else
    return false;
}

int main()
{
    int num1,num2;
    printf("Enter two numbers :- ");
    scanf("%d %d",&num1,&num2);

    if(coprime(num1,num2))
    printf("Given two numbers %d and %d are co-prime. \n",num1,num2);
    else
    printf("Given two numbers %d and %d are not co-prime. \n",num1,num2);
    return 0;
}