/* =========================
輸入一個整數
========================= */
#include <stdio.h>
int main()
{
int i;
printf("Input an integer:");
scanf( "%d", &i ); /* ch 前面加個 &(位址運算元) */
printf( "the number is %d", i );
return 0;
}
