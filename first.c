#include<stdio.h>

int main(){
char food[10];
float price;
int quantity;
printf("which item would yuu like to buy?: ");
scanf("%s", food);
printf("what is the price for each?:");
scanf("%f", &price);
printf("how many would you like to buy?:");
scanf("%d", &quantity);
printf("you have bought %d %s \n", quantity, food);
printf("the total is %f \n", price*quantity);
return 0;
}   