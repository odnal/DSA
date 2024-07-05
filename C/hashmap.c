// simple hashmap with normal suboptimal operations
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define MAX_KEY 256

// hashmap where keys are strings and values are integers
typedef struct MyHashMap {
  char *key ;
  int val; 
} hashmap_t;

hashmap_t *hash_table[TABLE_SIZE];

void init_hash_map() {
  for (int i=0; i<TABLE_SIZE; i++) {
    hash_table[i] = NULL;
  } 
}

void print_hash_table() {
  printf("Start\n");
  for (int i=0; i<TABLE_SIZE; i++) {
    if (hash_table[i] == NULL) {
      printf("\t-----\n");
    } else {
      printf("\t{%s: %d}\n", hash_table[i]->key, hash_table[i]->val);
    }
  } 
  printf("End\n");
}

int hash(char *key) {
  if (key == NULL) return -1;
  int len = strnlen(key, MAX_KEY);
  unsigned int hash_val = 0;
  for (int i=0; i<len; i++) {
    hash_val += key[i];
    hash_val = (hash_val*1023) % TABLE_SIZE;
  }
  return hash_val;
}

hashmap_t *hash_insert (hashmap_t *data) {
  if (data == NULL) return NULL;
  int index = hash(data->key);
  for (int i=0; i<TABLE_SIZE; i++) {
    int try = (index+i) % TABLE_SIZE;
    if (hash_table[try] == NULL)
      hash_table[try] = data;
    return hash_table[try];
  }
  return NULL;
}

hashmap_t *hash_delete (char *key) {
  if (key == NULL) return NULL;
  int index = hash(key);
  for (int i=0; i<TABLE_SIZE; i++) {
    int try = (index+i) % TABLE_SIZE;
    if (hash_table[try] != NULL && strncmp(hash_table[try]->key, key, MAX_KEY) == 0)
      hash_table[try] = NULL;
    return hash_table[try];
  }
  return NULL;
}

hashmap_t *hash_lookup(char *key) {
  if (key == NULL) return NULL;
  int index = hash(key);
  for (int i=0; i<TABLE_SIZE; i++) {
    int try = (index+i) % TABLE_SIZE;
    if (hash_table[try] != NULL && strncmp(hash_table[try]->key, key, MAX_KEY) == 0)
      hash_table[try] = NULL;
    return hash_table[try];
  }
  return NULL;
}


int main() {

  init_hash_map(); 
  print_hash_table();
  
  hashmap_t jake = {.key="jake", .val=5}; 
  hashmap_t bonnie = {.key="bonnie", .val=90}; 
  hashmap_t clyde = {.key="clyde", .val=15}; 
  hash_insert(&jake);
  hash_insert(&jake);
  hash_insert(&bonnie);
  hash_insert(&clyde);
  print_hash_table();
  hash_delete(clyde.key);
  print_hash_table();

  return 0;
}
