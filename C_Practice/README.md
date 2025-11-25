# C言語の練習

## fopen-close
- stdin-outの練習

## my_cat 
- catコマンドの自作．
- fgetsを使う練習
  - fgetsによって，ファイルの中身を表示する．

## StaticとExtern
- 関数の外に書いた変数はグローバル変数となり，メモリに居座り続ける．また，ほかのファイルからも見えてしまう．
- static
  - 使う場所によって意味が違う
  1. 関数内でstaticをつけると，その変数は関数が終わってもメモリに残る．状態を持つ関数を作るときに使おう．
  2. 関数の外でstaticをつけると，その変数はそのファイルの中からしか見えなくなる．
  - 他ファイルに公開する必要のないグローバル変数や関数にはstaticをつけよう．カプセル化，オブジェクト指向におけるprivateに相当する．

- extern
  - 複数のファイルで変数を共有したい場合(設定値など)はexternを使う．
  1. 実体は一つのファイルに書く．
  2. 他ファイルでの宣言にはexternをつける．

## 関数とポインタとコールバック
- 関数だってアドレスに配置される．->関数のアドレスを変数に格納すれば，その変数経由で関数を呼び出せるね．これを関数ポインタという．
```c
int add(int a, int b){ return a + b; }
//add関数をfunc_ptrに格納するための宣言
int (*func_ptr)(int, int);
```
- main関数内のロジックを変更することなく，動作を切り替えられる．->Strategyパターン．

- コールバック
  - qsortで実験
  - qsortには比較関数のポインタを渡す必要がある．
    - この時に関数ポインタで自分の作った処理を渡す必要がある．
    - 比較関数の引数はconst void *
    - 値の比較には引数をint型に直す必要がある．
    - val_a = *(int *)a;
    1. a: const void * 型．謎のアドレス．
    2. (int * )a: const int * 型．住所にどんな型(方)が住んでいるのか(今回はint)を伝える．
    3. * ( ): 2.の住所に行って値を読みだす．

## 連結リスト(Linked list)
- arrayの途中に新しい要素を追加したいとき，その後ろの要素を全てずらす必要があるのだろうか？
  - これを解決するのがポインタと構造体とmallocを組み合わせた自己参照構造体(連結リスト)．
1. リストの各要素をノードとする．自分のデータと次のノードのデータを持つ．
```c
typedef struct Node{
    int data;
    struct Node *next;
  }Node;
```

2. ノードの作成と連結
```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data; //自分のデータと
    struct Node *next; //次のノードのデータ
  }Node;

Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) exit(1);

    new_node->data = data;
    new_node->next = NULL;
    return new_node;
  }

  int main(void) {
      Node *head = create_node(10);

      Node *second = create_node(20);

      head->next = second;
      
      second->next = create_node(30);

      return 0;
    }
```

3. リストの走査
- nextポインタをたどるしかない．arr[i]のようにはいかない．

```c
void print_list(Node *head) {
  Node *current = head;
  Node *temp;
  while (current != NULL) {
    temp = current->next; //次の行き先を避難させる
    free(current); //現在のノードを解放
    current = current->next;
  }
  print("NULL\n")
}

```


