#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
/* Illustration of the common trigonometric functions */
int main()
{
#define PI 3.14159265
 double angle, radianno, answer;
 /* The cosine function */
 printf("cosine function:\n ");
 printf("Please enter angle in degrees:\n ");
 scanf("%lf", &angle);
 printf("You entered %lf\n", angle);
 radianno = angle * (2 * PI / 360);
 answer = cos(radianno);
 printf("cos of %lf is %lf\n", angle, answer);
 /* The sine function */
 printf("sine function:\n ");
 printf("Please enter angle in degrees:\n ");
 scanf("%lf", &angle);
 printf("You entered %lf\n", angle);
 radianno = angle * (2 * PI / 360);
 answer = sin(radianno);
 printf("sin of %lf is %lf\n", angle, answer);
 /* The tangent function */
 printf("tangent function:\n ");
 printf("Please enter angle in degrees:\n ");
 scanf("%lf", &angle);
 printf("You entered %lf\n", angle);
 radianno = angle * (2 * PI / 360);
 answer = tan(radianno);
 printf("tan of %lf is %lf\n", angle, answer);
 return 0;
}