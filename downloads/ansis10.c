#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
int main(void) {
    // Display title
    printf("Size of C data types:\n\n");
    // Display column headers
    printf("%-20s %-20s\n", "Type", "Bytes");
    // Display separator line
    printf("--------------------------------\n");
    // Print size of various data types
    printf("%-20s %lu\n", "char", sizeof(char));
    printf("%-20s %lu\n", "int8_t", sizeof(int8_t));
    printf("%-20s %lu\n", "unsigned char", sizeof(unsigned char));
    printf("%-20s %lu\n", "uint8_t", sizeof(uint8_t));
    printf("%-20s %lu\n", "short", sizeof(short));
    printf("%-20s %lu\n", "int16_t", sizeof(int16_t));
    printf("%-20s %lu\n", "uint16_t", sizeof(uint16_t));
    printf("%-20s %lu\n", "int", sizeof(int));
    printf("%-20s %lu\n", "unsigned", sizeof(unsigned));
    printf("%-20s %lu\n", "long", sizeof(long));
    printf("%-20s %lu\n", "unsigned long", sizeof(unsigned long));
    printf("%-20s %lu\n", "int32_t", sizeof(int32_t));
    printf("%-20s %lu\n", "uint32_t", sizeof(uint32_t));
    printf("%-20s %lu\n", "long long", sizeof(long long));
    printf("%-20s %lu\n", "int64_t", sizeof(int64_t));
    printf("%-20s %lu\n", "unsigned long long", sizeof(unsigned long long));
    printf("%-20s %lu\n", "uint64_t", sizeof(uint64_t));
    printf("%-20s %lu\n", "float", sizeof(float));
    printf("%-20s %lu\n", "double", sizeof(double));
    printf("%-20s %lu\n", "long double", sizeof(long double));
    printf("%-20s %lu\n", "bool", sizeof(bool));
    // Add a newline for better output formatting
    printf("\n");
    // Indicate successful execution of the program
    return 0;
}