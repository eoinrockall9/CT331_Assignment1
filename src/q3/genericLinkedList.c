#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, void* printFunction){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  void* dataPointer = malloc(size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  memmove(dataPointer, data, size);
  e->data = dataPointer;
  e->size = size;
  e->printFunction = printFunction;
  e->next = NULL;
  return e;
}

void printChar(void* data){
  printf("%c\n", *(char*)data);
}

void printString(void* data){
  printf("%s\n", (char*)data);
}

void printInt(void* data){
  printf("%d\n", *(int*) data);
}

void printFloat(void* data){
  printf("%f\n", *(float*) data);
}

void printDouble(void* data){
  printf("%lf\n", *((double*)data));
}

void printLong(void* data){
  printf("%ld\n", *(long*)data);
}

void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    current->printFunction(current->data);
    current = current->next;
  }
}

listElement* insertAfter(listElement* el, void* data, size_t size, void* printFunction){
  listElement* newEl = createEl(data, size, printFunction);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}

void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

int length(listElement* list){
  if(list == NULL){
	  return 0;
  }
  int counter;
  counter = 0;
  listElement* current = list;
  while(current != NULL){
    current = current -> next;
    counter++;
  }             
  return counter;
} 

void push(listElement** list, void* data, size_t size, void* printFunction){
  listElement* temp = createEl(data, size, printFunction);
  temp->next = *list;
  *list = temp;
}

listElement* pop(listElement** list){
  // make sure not empty	
  if(length(*list) == 0){
	  return *list;
  }
  // set temp pointer to pointer of first ElementStruct
  listElement* temp = *list;
  if(temp){
    *list = temp->next;
  }
  return temp;
}

void enqueue(listElement** list, void* data, size_t size, void* printFunction){
  listElement* temp = createEl(data, size, printFunction);
  temp->next = *list;
  *list = temp;
}

listElement* dequeue(listElement* list){
  // make sure not null	
  if(list == NULL){
    return list;
  }
  listElement* current = list;
  while(current->next->next != NULL){
    current = current -> next;
  }  
  listElement* temp = current -> next;
  current -> next = NULL;
  return temp;
}