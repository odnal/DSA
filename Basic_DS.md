# DSA

This is a collection of notes on some basic "need to know" data structures
and algorithms. These notes will define what each data structure or algoritm 
that is discussed is, provide examples and theories of how to apporpriately
use the dsa, and discuss the time complexities of each dsa and how to determine 
them.

Firstly, lets define what a `Data Strucute` and `Algorithm` is.

**Data Structure**: in simple terms a data structure is a way of storing and 
viewing data. Furthermore, a data structure has efficient and inefficient
ways of accessing that data depending on the problem/use case.

**Algorithms**: is a way of performing different operations on data structures
plus the set of instructions for executing them.

Note, depending on the data structure you're using your algorithm might look
completely different for solving the same problem.

## Arrays
**Array**: is a data structure consisting of elements (values or variables) of
same memory size (i.e collection of items with a single type) each identified
by a index or key.

Moreover, arrays are just fixed-sized contigous chunks of memory. Once the
memory chunk is allocated, the amount of memory it contains cannot be changed.
You have to allocate space upfront for the array, which can lead to wasted or
insufficient space. Insertion and deletion can be costly, because you have to
shift the elements or resize the array. Because arrays are stored in a contigous
memory space random access operations perform well. This is because elements in
the array are stored sequentially.

Note, arrays are useful because their indecies can be computed at run-time. This
is useful depending on the use case. Below is a snippet of how the index calculation 
is performed.

```
  int myArray[5]; // declaration of integer array with 5 elements
  int index = 2;
  int element = myArray[index]; // Index calculation: address_of_array + (index * sizeof(int))
```

*Index Calculation* can be simple or more complex depending on the array layout and data type.
Take the two-dimensional array below for example.

```
  int twoDArray[3][4]; // declaration of 2D integer array with 3 rows and 4 columns
  int row = 2, col = 3;
  int element = twoDArray[index]; // Index calculation: address_of_array + (row * number_of_columns + col) * sizeof(int))
```

*Time complexity* - arrays take linear *O(n)* space in the number of elements `n` they hold.
Note, it takes of *O(1)* time to access and element given a known index.

## Linked Lists

**Linked List**: is a linear data structure in which elements are linked together using
pointers.

They are commonly used to implement dynamic data structures and abstract data types.
They are particularly useful when the total number of elements is unknown beforehand
or when the order of the elements may need to be changed during run time. Unlike arrays
linked list dont have a fixed size and the memory allocation is done dynamically.

Linked list are flexible in how easy it is to insert and delete elements, (no need to
resize memory buffer like array) just change the pointer of the targets adjacent elements.
However, they are less effecient in terms of memory usage and accessing elements at
random positions (you have to traverse the list in order to get the target value).

A *Node* is an element in a linked list. It has two values: `data` and `next pointer`.
The `next pointer` points to the next node or null (`null` meaning end of the list).

### Types of Linked Lists
* Singly Linked List
    * Has one pointer that points to the next node but not the previous node

* Doubly Linked List
    * Has two pointers - one to access the next node (or null) and one
      to access the previous node (or null)

### Example creating a node (singly & doubly)
# 
```
  // Singly Linked
  typedef struct Node {
    int data;
    struct Node *next;
  } node_t;
  
  // Doubly Linked
  typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
  } node_t;
  
  int main() {
    node_t *head = NULL;
    node_t *tmp = malloc(sizeof(node_t));
    tmp->data = 5;
    tmp->prev = NULL;
    tmp->next = NULL;
    head = tmp;
    
    return 0;
  }
```

### Common operation of Linked Lists
* Insertion
  * you can insert anywhere in the linked list (head, tail, middle)
  * TC - *O(n)* worst case. Note, if inserting at the head *O(1)*
* Deletion
  * removing an element from a linked list
  * TC - *O(n)* worst case. Note, if deleting at the head *O(1)*
* Searching
  * traversing linked list one node at a time
  * TC - *O(n)*

## Stack

**Stack**: is an abstract data type that supports the operations `push` (insert new element
on top of the stack) and `pop` (remove and return the most recently added element). 

As an abstract data type, stacks can be implemented using arrays or singly linked lists.
Note, implementing a stack using an array can result in stack overflow if the element exceeds
the array size capacity. Implementing a stack using a linked list rarely causes an overflow
since linked list grow dynamically.

The behavior of a stack is commonly called LIFO. Stacks are an important way of supporting
nested or recursive function calls and is used to implement depth-first search. Note, DFS
can be implemented using recursion or a manual stack.

### Common operations of a Stack
* Push
  * function used to add element to the top of the stack
  * TC - *O(1)* always add to top of stack
* Pop
  * function used to remove elements from the top of the stack
  * TC - *O(1)* always remove from top of stack
* Top/peek
  * function that returns the value thats on top of the stack (doesnt remove it)
  * TC - *O(1)*
* isEmpty
  * function that checks if the stack is empty or not
  * TC - *O(1)*
* isFull
  * function that checks if the stack is full or not
  * TC - *O(1)*
* search/size
  * function that searches for an element in the stack / function that returns the size of the stack
  * TC - *O(n)* - search / *O(1)* - size

## Queue

**Queue**: is a linear abstract data type that can contain a long list of elements. These elements
can be added to the queue (`enqueue` operation) or removed from the queue (`dequeue` operation).
Usually, the end of the sequence in which the elements are added to the queueh is called the back, 
tail, rear of the queue and the end at which elements are removed is called the head or front of 
the queue. Queues can be implemented using array or singly linked lists.

The behavior of a queue is FIFO. Whats important to remember about them is how they can grow 
and shrink in size. BFS is commonly implemented using queues.

### Common operations of a Queue
* Enqueue
  * function used to add element to the end of the queue
  * TC - *O(1)* always add to back of queue
* Dequeue
  * function used to remove elements from the from of the queue
  * TC - *O(1)* always remove from front of queue
* Front
  * pointer element responsible for fetching the first element from the queue
  * TC - *O(1)*
* Back
  * pointer element responsible for fetching the last element from the queue
  * TC - *O(1)* 
* isEmpty
  * function that checks if the queue is empty or not
  * TC - *O(1)*
* size
  * function to get the size of the queue
  * TC - *O(1)*


