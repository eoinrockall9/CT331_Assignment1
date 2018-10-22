#include <stdio.h>

int i;
int* in;
long lng;
double* doub;
char** c;

int main(int arg, char* argc[]){
  printf("Hello assignment1.\n");

  printf("%d\n", sizeof(i));
  printf("%d\n", sizeof(in));
  printf("%d\n", sizeof(lng));
  printf("%d\n", sizeof(doub));
  printf("%d\n", sizeof(c));
  return 0;
}
