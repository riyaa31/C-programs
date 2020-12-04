#include <stdio.h>
#include<math.h>

int main()
{
   int x1, y1, x2, y2, x3, y3, distance1, distance2;
   printf("Enter first set of coordinates: ");
   scanf("%d%d", &x1, &y1);
   printf("Enter second set of coordinates: ");
   scanf("%d%d", &x2, &y2);
   printf("Enter third set of coordinates: ");
   scanf("%d%d", &x3, &y3);
   distance1 = sqrt(pow(x2 - x1, 2) +  pow(y2 - y1, 2) ); 
   distance2= sqrt(pow(x3 - x2, 2) +  pow(y3 - y2, 2) * 1.0); 
   
   printf("%d",x1);
   printf("%d", (x1-x2));
   printf("%d", x1);
   printf("%d", distance1);
   printf("%d",x2);
   printf("%d", (x2-x3));
   printf("%d", x2);
   printf("%d", distance2);
   
   printf("%d\n Total path: ", distance1+distance2);
}
