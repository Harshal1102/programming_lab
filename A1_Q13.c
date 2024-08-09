#include<stdio.h>

int frequency=0;
int getfrequency(int array[],int n)
{
    int maxelement,count,i,j,max=0;
    for(i=0;i<n;i++)
    {
        count=1;
        
        for(j=i+1;j<n;j++)
        {
            if(array[i]==array[j])
            {
                count++;
                if(count>max)
                {
                    max=count;
                    maxelement=array[j];
                    frequency=count;
                }
            }
        }
    }
    return maxelement;
}
int main()
{
    int n;
    printf("Enter number of elements:- ");
    scanf("%d",&n);
    int array[n];
    printf("Enter araay elements:- ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    int maxelement=getfrequency(array,n);
    printf("Frequency: %d",frequency);
    printf("\n Element: %d",maxelement);

    return 0;
    
}