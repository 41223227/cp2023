#include<stdio.h>
int main()
{
    int x; // Declare variable x

    // Print header for table
    printf("x\tx+2\tx+4\tx+6\n\n");
    printf("---------------------------\n");

    // Loop to generate and print table values
    for(x=1; x<=15; x+=3)
        printf("%d\t%d\t%d\t%d\n", x, (x+2), (x+4), (x+6));    

    return 0; // Indicate successful program execution
}