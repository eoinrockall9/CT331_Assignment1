#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;
typedef void (*pf)(void* data);
typedef struct listElementStruct{
  void* data;
  size_t size;
  pf printFunction;
  struct listElementStruct* next;
} listElement;

// various print types
void printChar(void* data);
void printString(void* data);
void printInt(void* data);
void printFloat(void* data);
void printDouble(void* data);
void printLong(void* data);

//Creates element with data, size and type of print function as it's parameters
listElement* createEl(void* data, size_t size, void* printFunction);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts new element after given element "after" 
listElement* insertAfter(listElement* after, void* data, size_t size, void* printFunction);

//Delete the element after the given element "after"
void deleteAfter(listElement* after);

//Returns the number of elements in the list
int length(listElement* list);

//Pushes new element onto list 
void push(listElement** list, void* data, size_t size, void* printFunction);

//Removes the head element on the list
listElement* pop(listElement** list);

//Removes the tail element on the list
listElement* dequeue(listElement* list);

//Adds new element to the head of the list
void enqueue(listElement** list, void* data, size_t size, void* printFunction);

#endif
