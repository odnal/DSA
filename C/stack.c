// simple array based stack with normal operations
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10

typedef struct Stack {
  char *content[STACK_SIZE];
  int top;
} stack_t;

void stack_init (stack_t *stack) {
  stack->top = -1;

  for (int i=0; i<STACK_SIZE; i++) {
    stack->content[i] = NULL;
  }
}

int size (stack_t *stack) {
  return stack->top+1;
}

int isFull (stack_t *stack) {
  if (size(stack)+1 <= STACK_SIZE)
    return 0;
  return 1;
}

int isEmpty (stack_t *stack) {
  if (size(stack) <= -1)
    return 1;
  return 0;
}

void push (stack_t *stack, char *stuff) {
  if (!isFull(stack)) {
    stack->top++;
    stack->content[stack->top] = stuff;
  } else {
    fprintf(stderr, "stack is full\n");
  }
}

void pop (stack_t *stack) {
  if (isEmpty(stack)) {
    fprintf(stderr, "stack is empty - cant pop from it\n");
    return;
  }
  stack->top--;
}

char *peek (stack_t *stack) {
  if (isEmpty(stack)) {
    fprintf(stderr, "stack is empty - cant peek\n");
    return NULL;
  }
  return stack->content[stack->top];
}

void print_stack (stack_t *stack) {
  if (stack->top == -1) {
    fprintf(stderr, "stack is empty\n");
    return;
  }

  printf("Stack Top\n");
  for (int i=stack->top; i>=0; --i) {
    if (stack->content[i] == NULL)
      printf("\t----\n");
    else
      printf("\t%s\n", stack->content[i]);
  }
  printf("Stack Bottom\n");
}

int main() {
  
  stack_t mystack;
  stack_init(&mystack);
  
  print_stack(&mystack);
  push(&mystack, "HelloWorld");
  push(&mystack, "ByeWorld !!");
  push(&mystack, "ByeWorld !!");
  print_stack(&mystack);
  printf("Stack size: %d\n", size(&mystack));
  pop(&mystack);
  print_stack(&mystack);
  printf("Stack size: %d\n", size(&mystack));
  printf("Peek gives: %s\n", peek(&mystack));

  return 0;
}
