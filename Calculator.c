#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add()
{
    int num1;
    int num2;
    int num3;
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter a second number: ");
    scanf("%d", &num2);
    num3 = num1 + num2;
    printf("The answer is: %d", num3);

};

void mul()
{
    int num1;
    int num2;
    int num3;
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter a second number: ");
    scanf("%d", &num2);
    num3 = num1 * num2;
    printf("The answer is: %d", num3);


};

void divide()
{
    float num1;
    float num2;
    float num3;
    printf("Enter a number: ");
    scanf("%f", &num1);
    printf("Enter a second number: ");
    scanf("%f", &num2);
    num3 = num1/num2;
    printf("The answer is: %f", num3);

};

void sub()
{
    int num1;
    int num2;
    int num3;
    printf("Enter a number: ");
    scanf("%d", &num1);
    printf("Enter a second number: ");
    scanf("%d", &num2);
    num3 = num1 - num2;
    printf("The answer is: %d", num3);
};

void square()
{
    int num1;
    int num3;
    printf("Enter a number: ");
    scanf("%d", &num1);
    num3 = num1 * num1;
    printf("The answer is: %d", num3);
}

void root()
{
    double num, num1;
    printf("Enter a number: ");
    scanf("%lf", &num);
    num1 = sqrt(num);
    printf("The answer is: %lf", num1);
}

int main()
{
    char option;
    char operator;
    printf("Enter operation: \n");
    printf("+ for addition \n- for subtraction \n* for multiplication \n/ for division  \ns for squared\nr for square root\n");
    scanf("%c", &operator);
    switch (operator)
    {
        case '+':
            add();
            break;

        case '-':
            sub();
            break;

        case '*':
            mul();
            break;

         case '/':
            divide();
            break;

         case 's':
            square();
            break;

         case 'r':
            root();
            break;

         default:
            printf("The operator you entered is invalid");
    }

    return 0;
}


