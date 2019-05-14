#include <stdio.h>

void main(){
    /**
     * @brief initialization
     */
    int int_integer = 0;
    short short_integer = 0;
    long long_integer = 0;

    float float_real_number = 0.0;
    double double_real_number = 0.0;

    char character = NULL;

    int_integer = 1;
    short_integer = 2;
    long_integer = 3;
    float_real_number = 4.5;
    double_real_number = 6.7;
    character = '8';

    printf("values \n");
    printf("int_integer : %d \n", int_integer);
    printf("short_integer : %d \n", short_integer);
    printf("long_integer : %ld \n", long_integer);
    printf("float_real_number : %f \n", float_real_number);
    printf("double_real_number : %lf \n", double_real_number);
    printf("character : %c \n", character);

    printf("\n\nsizes\n");
    /**
     * @brief Normally sizeof used with %d
     */
    printf("size_int_integer : %ld \n", sizeof(int));
    printf("size_short_integer : %ld \n", sizeof(short));
    printf("size_long_integer : %ld \n", sizeof(long));
    printf("size_float_real_number : %ld \n", sizeof(float));
    printf("size_double_real_number : %ld \n", sizeof(double));
    printf("size_character : %ld \n", sizeof(char));
}
