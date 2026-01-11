// 指標與雙重指標示範程式
#include<iostream>
using namespace std;

// 定義 Node 結構
typedef struct Node {
    int val;
    struct Node* next;
}Node;

int main(){
    /*
    記憶體配置範例：
    Node dummy;          // Node 結構，位址 0x2000
    Node *p = &dummy;    // 指標變數 p，位址 0x1000，值 0x2000
    Node **pp = &p;      // 雙重指標 pp，位址 0x0500，值 0x1000

    記憶體配置圖：
    0x0500           0x1000           0x2000
    ┌─────────┐      ┌─────────┐      ┌─────────────┐
    │ pp      │─────▶│ p       │─────▶│ dummy       │
    │ 值:0x1000│      │ 值:0x2000│      │ val: -1     │
    └─────────┘      └─────────┘      │ next: ...   │
                                      └─────────────┘

    ---

    從 p 的角度：
    表達式    型別        值                      意義
    &p       Node **    0x1000                 p 這個變數在哪裡
    p        Node *     0x2000                 p 裡面存的值（節點位址）
    *p       Node       {val:-1, next:...}     p 指向的節點本身

    ---

    從 pp 的角度：
    表達式    型別        值                      意義
    &pp      Node ***   0x0500                 pp 這個變數在哪裡
    pp       Node **    0x1000                 pp 裡面存的值（p 的位址）
    *pp      Node *     0x2000                 pp 指向的東西（就是 p 的值）
    **pp     Node       {val:-1, next:...}     最終的節點本身

    ---

    等價關係：
    表達式    等於    原因
    *pp      p      pp 指向 p，解引用得到 p 的值
    **pp     *p     再解一次，得到節點本身
    pp       &p     pp 存的就是 p 的位址

    ---

    操作對照：
    你想做什麼                用什麼表達式
    讀取/修改節點內容          *p 或 **pp，例如 (*p).val = 10
    讀取/修改 p 指向誰         p 或 *pp，例如 p = new_node
    讀取/修改 pp 指向誰        pp，例如 pp = &another_ptr

    ---

    一句話記法：
    每加一個 *  → 往右走一格（解引用，取得指向的內容）
    每加一個 &  → 往左走一格（取得自己的位址）
    */

    // 實際範例程式
    Node dummy;
    dummy.val = -1;
    dummy.next = nullptr;

    Node *p = &dummy;        // p 指向 dummy
    Node **pp = &p;          // pp 指向 p

    // 印出位址資訊
    cout << "=== 位址資訊 ===" << endl;
    cout << "&dummy 的位址: " << &dummy << endl;
    cout << "&p 的位址: " << &p << endl;
    cout << "&pp 的位址: " << &pp << endl;
    cout << endl;

    cout << "=== 從 p 的角度 ===" << endl;
    cout << "&p (p 變數的位址): " << &p << endl;
    cout << "p (p 存的值，即 dummy 的位址): " << p << endl;
    cout << "(*p).val (p 指向的節點的值): " << (*p).val << endl;
    cout << endl;

    cout << "=== 從 pp 的角度 ===" << endl;
    cout << "&pp (pp 變數的位址): " << &pp << endl;
    cout << "pp (pp 存的值，即 p 的位址): " << pp << endl;
    cout << "*pp (pp 指向的東西，即 p 的值): " << *pp << endl;
    cout << "(**pp).val (最終的節點的值): " << (**pp).val << endl;
    cout << endl;

    cout << "=== 等價關係驗證 ===" << endl;
    cout << "*pp == p? " << (*pp == p ? "是" : "否") << endl;
    cout << "**pp 的值 == *p 的值? " << ((**pp).val == (*p).val ? "是" : "否") << endl;
    cout << "pp == &p? " << (pp == &p ? "是" : "否") << endl;
    cout << endl;

    cout << "=== 操作示範 ===" << endl;
    // 透過 *p 修改節點內容
    (*p).val = 10;
    cout << "透過 (*p).val = 10 修改後: " << dummy.val << endl;

    // 透過 **pp 修改節點內容
    (**pp).val = 20;
    cout << "透過 (**pp).val = 20 修改後: " << dummy.val << endl;

    return 0;
}
