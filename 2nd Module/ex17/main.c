#include <stdio.h>
#include "calculator.h"

int num1 = 0, num2 = 0;
int main(void) {

   // A + B
   num1 = 10;
   num2 = 5;
   printf("Sum: %d + %d = %d\n", num1, num2, sum());

   // A - B
   num1 = 10;
   num2 = 50;
   printf("Subtract: %d - %d = %d\n", num1, num2, subtraction());

   // A * B
   num1 = 10;
   num2 = 5;
   printf("Multiply: %d * %d = %d\n", num1, num2, multiplication());

   // A / B
   num1 = 10;
   num2 = 6;
   printf("Division: %d / %d = %d\n", num1, num2, division());

   // A % B
   num1 = 10;
   num2 = 3;
   printf("Modulus: %d %% %d = %d\n", num1, num2, modulus());
   
   // A ^ 2
   num1 = 10;
   printf("Power of 2: %d ^ 2 = %d\n", num1, powerOfTwo());
   
   // A ^ 3
   num1 = -2;
   printf("Power of 3: %d ^ 3 = %d\n", num1, powerOfThree());
   
   return 0;
}
