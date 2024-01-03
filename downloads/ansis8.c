#include<stdio.h>
int main()
{
    // Define a string containing lowercase and uppercase letters
    char* letters = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n;

    // Print header
    printf("List of integer equivalents of letters (a-z, A-Z).\n");
    printf("==================================================\n");

    // Loop through each character and print its integer equivalent
    for(n=0; n<53; n++) {
        printf("%d\t", letters[n]);

        // Add a newline every 6 characters for better formatting
        if((n+1) % 6 == 0)
             printf("\n");
    }

    return 0;
}