#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* program to show array use */
int main()
{
 int arr1[8];/* define an array of 8 integers */
 int i;
 printf("enter 8 integer numbers\n");
 for (i = 0;i < 8;i++)
 {
 scanf("%d", &arr1[i]);/* read into arr1[i] */
 }
 printf("Your 8 numbers are \n");
 for (i = 0;i < 8;i++)
 {
 printf("%d ", arr1[i]);
 }
 printf("\n");
}