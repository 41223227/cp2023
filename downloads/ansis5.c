#include <stdio.h>
int main() {
    float S = 0;
    int i;

    // Loop to calculate the sum
    for(i=1; i<=50; i++) {
        S += (float)1/i;
    }

    // Print the result
    printf("Value of S: %.2f\n", S);

    return 0;
}