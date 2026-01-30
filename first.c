#include <stdio.h>

int main()
{
  int arr[5] = {10, 20, 30, 40, 50};
  int (*ptr)[5] = &arr;
  printf("%p\n", *ptr);
    return 0;

}