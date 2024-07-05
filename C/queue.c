// suboptimal implementation of queue with loose constructs
#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 10

typedef struct Queue {
  char *content[QUEUE_SIZE];
  int front;
  int back;
} queue_t;

void queue_init (queue_t *q) {
  q->front = -1;
  q->back = -1;

  for (int i=0; i<QUEUE_SIZE; i++) {
    q->content[i] = NULL; 
  }
}

int size (queue_t *q) {
  return q->back+1;
}

int isFull (queue_t *q) {
  if (size(q)+1 <= QUEUE_SIZE) {
    return 0;
  }
  return 1;
}

int isEmpty (queue_t *q) {
  if (size(q) <= -1)
    return 1;
  return 0;
}

void enqueue (queue_t *q, char *stuff) {
  if (!isFull(q)) {
    q->front = 0;
    q->back++;
    q->content[q->back] = stuff;
  } else {
    fprintf(stderr, "can't enqueue - queue is full\n");
    return;
  }
}

void dequeue (queue_t *q) {
  if (isEmpty(q)) {
    fprintf(stderr, "can't dequeue - queue is empty\n");
    return;
  } 
  q->front++;
  if (q->front > q->back)
    q->front = q->back = -1;
}

void print_queue (queue_t *q) {
  if (q->back == -1) {
    fprintf(stderr, "queue is empty\n");
    return;
  }

  printf("Queue Front\n");
  for (int i = q->front; i <= q->back; i++) {
    printf("\t%s\n", q->content[i]);
  }
  printf("Queue Back\n");
}

char *get_front (queue_t *q) {
  if (q->front != -1)
    return q->content[q->front];
  return NULL;
}

char *get_back (queue_t *q) {
  if (q->back != -1)
    return q->content[q->back];
  return NULL;
}

int main () {
  queue_t myqueue;

  queue_init(&myqueue);
  print_queue(&myqueue);

  enqueue(&myqueue, "Hello");
  enqueue(&myqueue, "World");
  print_queue(&myqueue);

  printf("Front: %s\n", get_front(&myqueue));
  printf("Back: %s\n", get_back(&myqueue));

  dequeue(&myqueue);
  print_queue(&myqueue);
  printf("Front: %s\n", get_front(&myqueue));
  printf("Back: %s\n", get_back(&myqueue));

  return 0;
}
