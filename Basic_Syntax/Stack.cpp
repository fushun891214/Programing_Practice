#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // 初始化一個空的stack
    stack<int> s;
    
    // 對stack新增元素
    s.push(10);
    s.push(20);
    s.push(30);
    
    // 檢查stack是否為空
    // 輸出：0
    cout << s.empty() << endl;
    
    // 檢查stack的大小
    // 輸出：3
    cout << s.size() << endl;
    
    // 獲取stack頂端的元素
    // 輸出：30
    cout << s.top() << endl;
    
    // 刪除stack頂端的元素
    s.pop();
    
    // 獲取stack頂端的元素
    // 輸出：20
    cout << s.top() << endl;
    
    return 0;
}