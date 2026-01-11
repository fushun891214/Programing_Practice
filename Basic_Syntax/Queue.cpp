#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // 初始化一個空的queue
    queue<int> q;
    
    // 在queue尾端加入元素
    q.push(10);
    q.push(20);
    q.push(30);
    
    // 檢查queue是否為空，輸出: false
    cout << q.empty() << endl;
    
    // 獲取 queue的大小，輸出：3
    cout << q.size() << endl;
    
    // 輸出queue頭端與尾端元素
    // 輸出：10、30
    cout << q.front() << " " << q.back() << endl;
    
    // 移除queue頭端的元素
    q.pop();
    
    // 輸出queue頭端的元素
    // 輸出:20
    cout << q.front() << endl;
    
    return 0;
}