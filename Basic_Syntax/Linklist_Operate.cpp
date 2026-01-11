#include<iostream>
#include<list>
using namespace std;

int main(){
    // 初始化linklist
    list<int> lst{1,2,3,4,5};
    // 檢查linklist是否為空，輸出：false
    cout << lst.empty() << endl;
    // 獲取linklist長度
    cout << lst.size() << endl;

    // 在linklist頭插入元素0
    lst.push_front(0);
    // 在linklist尾插入元素6
    lst.push_back(6);
    // 輸出linklist頭和尾的元素
    cout << lst.front() << " " << lst.back() << endl;

    // 刪除linklist頭的元素
    lst.pop_front();
    // 刪除linklist尾的元素
    lst.pop_back();

    // 在linklist插入元素
    auto it = lst.begin();
    // 移動到linklist第三個位置
    advance(it,2);
    // 在linklist第三個位置插入元素99
    lst.insert(it,99);
    
    // 在linklist刪除某個元素
    it = lst.begin();
    // 移動到linklist第二個位置
    advance(it,1);
    // 刪除第二個位置的元素
    lst.erase(it);
    
    // 拜訪並輸出linklist所有元素
    // 輸出：1 99 3 4 5
    for(int val:lst){
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}