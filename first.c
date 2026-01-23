#include <stdio.h>

int main()
{
    char operator ='\0';
    float num1 = 0.0;
    float num2 = 0.0;
    float result = 0.0;

    printf("Enter the first numberr: ");
    scanf("%f", &num1);
    printf("Enter an operatorr (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter the second number: ");
    scanf("%f", &num2);

    switch (operator)
        {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break; 
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0){
                    result = num1 / num2;
                } else {
                    printf("Thora chutiya hai kya\n");
                    
                }
                break;
            default:
                printf("Invalid operator\n");
        }
            printf("Result: %.2f\n", result);
    return 0;
}