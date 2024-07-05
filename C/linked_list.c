#include <stdio.h>
#include <stdlib.h>

// singly linked list
typedef struct Node {
  int data;
  struct Node *next;
} node_t;

node_t *createNode (int value) {
  node_t *result = malloc(sizeof(node_t));
  result->data = value;
  result->next = NULL; 
  return result;
}

node_t *insert_at_head (node_t **head, node_t *node_to_insert) {
  node_to_insert->next = *head;
  *head = node_to_insert;
  return node_to_insert;
}

node_t *insert_at_tail (node_t *head, node_t *node_to_insert) {
  if (head == NULL) return NULL;

  node_t *tmp = head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  tmp->next = node_to_insert;
  return tmp;
}

node_t *insert_at_index (node_t *head, int index, node_t *node_to_insert) {
  if (head == NULL) return NULL;

  int position = 0; 
  node_t *tmp = head;

  while (tmp->next != NULL && position != index) {
    tmp = tmp->next;
    position++;
  }
  node_to_insert->next = tmp->next;
  tmp->next = node_to_insert;
  return tmp;
}

node_t *find_node (node_t *head, int value) {
  if (head == NULL) return 0;

  node_t *tmp = head;
  while (tmp != NULL) {
    if (tmp->data == value) {
      return tmp; // true
    }
    tmp = tmp->next;
  }

  return 0; // false
}

node_t *deleteNode (node_t **head, node_t *node_to_remove) {
  if (*head == node_to_remove) {
    *head = node_to_remove->next;
  }

  node_t *tmp = *head;
  while (tmp != NULL && tmp->next != node_to_remove) {
    tmp = tmp->next; 
  }
  if (tmp == NULL) return NULL;
  tmp->next = node_to_remove->next;
  node_to_remove = NULL;
  return tmp;
}

int sizeofLL (node_t *head) {
  if (head) {
    int size = 0;
    node_t *tmp = head;
    while (tmp != NULL) {
      size++;
      tmp = tmp->next;
    }
    return size;
  } else {
      return 0;
  }
}

// recursive method
node_t *reverse_LL (node_t *head) {
  node_t *tmp = head;
  if (tmp == NULL || tmp->next == NULL) return tmp;
  node_t *reverse = reverse_LL(tmp->next);
  tmp->next->next = tmp;
  tmp->next = NULL;
  return reverse;
}

// iterative method
node_t *reverse_LL_2 (node_t **head) {
  node_t *tmp = *head;
  if (tmp == NULL) return NULL;
  node_t *prev = NULL;
  node_t *next = NULL;
  while (tmp != NULL) {
    next = tmp->next; // store next
    tmp->next = prev;  // reverse tmp's next pointer
    // move pointers one position ahead
    prev = tmp;
    tmp = next;
  }
  *head = prev;
}

void print_LL (node_t *head) {
  if (head == NULL) return;
  node_t *tmp = head;
  while (tmp != NULL) {
    printf("%d", tmp->data);
    if (tmp->next != NULL)
      printf(" -> ");
    tmp = tmp->next;
  }
  printf("\n");
}

int main() {

  node_t *head = NULL; // init a head node to NULL

    
  insert_at_head(&head, createNode(5));
  insert_at_head(&head, createNode(6));
  insert_at_head(&head, createNode(7));
  insert_at_tail(head, createNode(9));
  insert_at_tail(head, createNode(10));
  insert_at_index(head, 2, createNode(8));

  print_LL(head);
  node_t *tmp = reverse_LL(head);
  print_LL(tmp);
  node_t *tmp2 = reverse_LL(tmp);
  print_LL(tmp2);
  reverse_LL_2(&tmp2);
  print_LL(tmp2);
  //if (find_node(head, 6)) {
  //  printf("Found\n");
  //} else {
  //  printf("Not found\n");
  //}

  //deleteNode(&head, find_node(head, 6));
  //print_LL(head);

  //if (find_node(head, 6)) {
  //  printf("Found\n");
  //} else {
  //  printf("Not found\n");
  //}

  return 0;
}
