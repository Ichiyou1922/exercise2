#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "list.h"

/* 置換関数
void replace(char *str, char oldChar, char newChar) {
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] == oldChar) {
      str[i] = newChar;
    }
  }
}
*/

Task *load_tasks(const char *filename) {
  char buf[256];
  int id = 1;
  Task *head = NULL;
  
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  int max_range = sizeof(buf) - 1;

  while (fgets(buf, sizeof(buf), fp) != NULL) {
    buf[strcspn(buf, "\n")] = '\0';
    Task *new_task = create_task(id, buf);
    head = add_task(head, new_task);
    id++;
  }

  fclose(fp);
  return head;
}

void save_tasks(const char *filename, Task *head) {
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("Failed to open file for writing");
    return;  
  }
  
  Task *current = head;

  while (current != NULL) {
    fprintf(fp, "%s\n", current->message);

    current = current->next;
  }

  fclose(fp);
  
}
