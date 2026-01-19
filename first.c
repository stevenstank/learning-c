#include <stdio.h>

int main()
{
    int choice;
    float kilograms, pounds;

    printf("Weight Conversion Calculator\n");
    printf("1. Kilograms to Pounds\n");
    printf("2. Pounds to Kilograms\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Enter weight in Kilogram:");
        scanf("%f", &kilograms);
        printf("%f kg is equal to %.2f pounds\n", kilograms, kilograms * 2.20462);
    }
    else if (choice > 2)
    {
        printf("Invalid choice. Please select 1 or 2.\n");
    }
    else
    {
        printf("Enter the weight in pounds:");
        scanf("%f", &pounds);
        printf("%f lb is equal to %.2f kilograms\n", pounds, pounds / 2.20462);
    }
    return 0;
}