//Riya Shah, 201817129
/* Yes, the output for the following four loops is exactly what I expected as it is a simple for loop, 
where variable i is given an initial value and an ending value and the condition for the increament or decreament of i */

#include<stdio.h>


int main ()
{
    int i;
printf("The output for first loop is: \n");
for(i = 0; i < 10; i = i + 2)
    printf("%d\n", i);
printf("The output for second loop is: \n");
for(i = 100; i >= 0; i = i - 7)
    printf("%d\n", i);
printf("The output for third loop is: \n");
for(i = 1; i <= 10; i = i + 1)
    printf("%d\n", i);
printf("The output for fourth loop is: \n");
for(i = 2; i < 100; i = i * 2)
     printf("%d\n", i);
}