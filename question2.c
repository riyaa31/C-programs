#include <stdio.h>

void function(int i)  
{

    for (int i = 1; i <= 200; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            printf(" threefive\n");
        else if (i % 3 == 0)
            printf(" three\n");
        else if (i % 5 == 0)
            printf(" five\n");
        else
            printf("%d\n", i);
    }
}
   int main(void)  
{
    int x;
    function(x);
    return (0);
} 

