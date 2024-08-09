#include <stdio.h>
int main ()
{
    int n = 0, i = 0, first = 0, second = 0, temp = 0;
 
    printf ("Enter the size of the array\n");
    scanf ("%d", &n);
    int array[n];
    printf ("Enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf ("%d", &array[i]);
    }
    first = array[0];
    second= array[1];
 
    if (first < second)
     {
        temp = first;
        first = second;
        second = temp;
    }
 
    for (int i = 2; i < n; i++)
    {
        if (array[i] > first)
        {
           second= first;
           first = array[i];
        }
        else if (array[i] > second && array[i] != first)
        {
            second = array[i];
        }
    }
 
    printf ("The first largest element is = %d\n", first);
    printf ("The second largest element is  = %d\n",second);
 
    return 0;
}