#include <stdio.h>
#include <string.h>
#include "list.h"
#include "file.h"

int main(int argc, char *argv[]) {
  Task *head = load_tasks("tasks.txt");

  if (argc < 2) {
    printf("Usage: %s list | add [message]\n", argv[0]);
    free_tasks(head);
    return 1;
  }

  if (strcmp(argv[1], "list") == 0) {
    print_tasks(head);
  }
  else if (strcmp(argv[1], "add") == 0) {
    if (argc < 3){
      printf("Error: Message required.\n");
      free_tasks(head);
      return 1;
    }

    int next_id = 1;
    Task *curr = head;
    while (curr != NULL) {
      if (curr->id >= next_id) {
        next_id = curr->id + 1;
      }
      curr = curr->next;
    }
    
    Task *new_node = create_task(next_id, argv[2]);

    head = add_task(head, new_node);

    save_tasks("tasks.txt", head);

    printf("Task added: %s\n", argv[2]);
  }

  else {
    printf("Unknown command: %s\n", argv[1]);
  }
  free_tasks(head);
  return 0;
}
