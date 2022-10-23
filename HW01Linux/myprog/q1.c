#include <stdio.h>
#include <stdlib.h>
int f1(int n)
{
  return (2 * n);
}

int f2(int n)
{
  return f1(2 + n);
}

int f3(int n)
{
  return f2(n - 1);
}

int f4(int n)
{
  return f3(2 - n);
}

int main(int argc, char * * argv)
{
  int x = 4;
  x = f4(6);
  printf("x = %d\n", x);
  return EXIT_SUCCESS;
}
