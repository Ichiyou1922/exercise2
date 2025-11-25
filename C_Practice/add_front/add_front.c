#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 新しいノードを作るヘルパー関数
Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) exit(1); // エラー処理
    
    new_node->data = data;
    new_node->next = NULL; // 最初は誰にも繋がっていない
    return new_node;
}

void print_list(Node *head) {
    Node *current = head; // 現在地

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next; // 次のノードへ移動
    }
    printf("NULL\n");
}

void free_list(Node *head) {
    Node *current = head;
    Node *temp;

    while (current != NULL) {
        temp = current->next; // 次の行き先を避難させておく
        free(current);        // 安心して現在のノードを爆破
        current = temp;       // 次へ
    }
}

Node* add_front(Node *head, int val) {
  Node *front = create_node(val);
  front->next = head;
  return front;
}

int main(void) {
  Node *head = NULL;
  head = add_front(head, 10);
  head = add_front(head, 20);
  head = add_front(head, 30);
  print_list(head);
  free_list(head);
}
