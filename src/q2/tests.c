#include <stdio.h>
#include "tests.h"
#include "linkedList.h"


void runTests(){
  printf("Tests running...\n");
  listElement* l = createEl("Test String (1).", 30);
  //printf("%s\n%p\n", l->data, l->next);
  //Test create and traverse
  traverse(l);
  printf("\n");

  //Test insert after
  listElement* l2 = insertAfter(l, "another string (2)", 30);
  insertAfter(l2, "a final string (3)", 30);
  traverse(l);
  printf("\n");

  // Test delete after
  deleteAfter(l);
  traverse(l);
  printf("\n");

  printf("Length: %d\n\n", length(l));

  printf("Stack Test\n");
  listElement* stack = NULL;   //create stack
  printf("testing push function...\npushing 3 new elements...\n");
  push(&stack, "\tNumber 1", 30);  
  push(&stack, "\tNumber 2", 30);
  push(&stack, "\tNumber 3", 30);
  printf("Traversal of Stack\n");
  traverse(stack);
  printf("Length: %d\n", length(stack)); // should print 3
  printf("testing pop function...\npopping from stack...\n");
  pop(&stack); // removes latest push onto stack, should remove "Number 3"
  printf("Traversal of Stack\n");
  traverse(stack); // should print "Number 1" and "Number 2"
  printf("Length: %d\n\n", length(stack)); // should print 2
  
  printf("Queue Test\n");
  listElement* queue = NULL; // create queue
  printf("testing enqueue...\nenqueuing 3 new elements...\n");
  enqueue(&queue, "\tNumber 1", 30);
  enqueue(&queue, "\tNumber 2", 30);
  enqueue(&queue, "\tNumber 3", 30);
  printf("Traversal of Queue\n");
  traverse(queue);
  printf("Length: %d\n", length(queue));
  printf("teesting dequeue...\ndequeuing from queue...\n");
  dequeue(queue);
  traverse(queue);
  printf("Length: %d\n\n", length(queue));

  printf("\nTests complete.\n");
}
