#include <stdio.h>

int i;
int* in;
long lng;
double* doub;
char** c;

int main(int arg, char* argc[]){
  printf("Hello assignment1.\n");

  printf("%lu\n", sizeof(i));
  printf("%lu\n", sizeof(in));
  printf("%lu\n", sizeof(lng));
  printf("%lu\n", sizeof(doub));
  printf("%lu\n", sizeof(c));
  return 0;
}
