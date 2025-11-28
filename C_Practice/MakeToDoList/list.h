/* list.h */

#ifndef LIST_H
#define LIST_H

#define MAX_TASK_LEN 256

typedef struct TaskNode {
  int id;
  char message[MAX_TASK_LEN];
  struct TaskNode *next;
} Task;

// get id and messages. memory allocation and return initialized node
Task* create_task(int id, const char *msg);

// add node to end of the list.
Task* add_task(Task *Head, Task *new_node);

// display all tasks 
void print_tasks(Task *Head);

// free all tasks
void free_tasks(Task *Head);

#endif
