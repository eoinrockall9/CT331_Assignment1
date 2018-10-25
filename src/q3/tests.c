#include <stdio.h>
#include "genericLinkedList.h"

void runTests(){
  printf("Tests running...\n\n");
  char c = 'c';
  listElement* l1 = createEl(&c, sizeof(char), &printChar);

  char string[]	 = "string";
  listElement* l2 = insertAfter(l1, &string, sizeof(string), &printString);
  
  int integer = 1;
  listElement* l3 = insertAfter(l2, &integer, sizeof(int), &printInt);
 
  float floating = 100.00;
  listElement* l4 = insertAfter(l3, &floating, sizeof(double), &printFloat);
  
  double doubleNo = 999.99;
  listElement* l5 = insertAfter(l4, &doubleNo, sizeof(double), &printDouble);

  long longNo = 1234;
  listElement* l6 = insertAfter(l5, &longNo, sizeof(long), &printLong);

  printf("testing insertAfter...\nlist is being traversed...\n");
  traverse(l1);
  printf("Length of List: %d\n", length(l1));

  printf("\ntesting deleteAfter...\nlist is being traversed...\n'string' should be removed\n");
  deleteAfter(l1);
  traverse(l1);
  printf("Length of List: %d\n", length(l1));

  printf("\ntesting dequeue...\nlist is being traversed...\n'1234' should be removed\n");
  dequeue(l1);
  traverse(l1);
  printf("Length of List: %d\n", length(l1));

  printf("\nTests complete.\n");
}
