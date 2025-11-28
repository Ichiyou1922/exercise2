#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>

Task* create_task(int id, const char *msg){
  Task *new_task = (Task *)malloc(sizeof(Task));
  if (new_task == NULL) {
    perror("malloc failed");
    exit(1);
  }

  new_task->id = id;
  strncpy(new_task->message, msg, MAX_TASK_LEN - 1); //msgの内容をnew_tasks->messageにコピー
  new_task->message[MAX_TASK_LEN - 1] = '\0'; //安全のため最後をヌル文字で閉じる．

  new_task->next = NULL;
  return new_task;
}

Task *add_task(Task *head, Task *new_node) {
  // 先頭が空なら新しいノードはそのまま先頭になる．
  if (head == NULL) {
    return new_node;
  }
  
  // リストが空でない場合
  // 探索用ポインタcurrentを用意して，先頭に配置
  Task *current = head;
  // currentの次のアドレスが空になるまで，currentをcurrentの次のアドレスに塗り替える
  while (current->next != NULL) {
    current = current->next;
  }
  // 最終的なアドレスにnew_nodeを配置する
  current->next = new_node;
  // 先頭のアドレス自体は変わっていないためheadを返す
  return head;
}

void print_tasks(Task *head) {
  Task *current = head;
  int id = 1;
  if (current == NULL) {
    printf("No tasks!\n");
  }
  else {
    while (current != NULL) {
      printf("%d. %s\n", id, current->message);
      current = current->next;
      id++;
    }
  }
}

void free_tasks(Task *head) {
  Task *current = head;
  Task *temp;

  while (current != NULL) {
    temp = current->next; // 次の行き先をメモ
    free(current);
    current = temp;
  }
}
