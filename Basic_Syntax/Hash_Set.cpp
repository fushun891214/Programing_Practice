#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    // 初始化一個hashset
    unordered_set<int> hashset{1,2,3,4};
    
    // 檢查hashset是否為空
    // 輸出：0
    cout << hashset.empty() << endl;

    // 獲取hashset大小
    // 輸出：4
    cout << hashset.size() << endl;
    
    // 尋找指定元素是否存在
    // 輸出: Element 3 found
    if(hashset.contains(3)){
        cout << "Element 3 found" << endl;
    }
    else{
        cout << "Element 3 not found" << endl;
    }
    
    // 插入一個新元素
    hashset.insert(5);
    
    // 刪除一個元素
    hashset.erase(2);
    
    // 輸出 Element 2 not found
    if(hashset.contains(2)){
        cout << "Element 2 found" << endl;
    }
    else{
        cout << "Element 2 not found" << endl;
    }
    
    // 拜訪hashset的所有元素
    // 輸出（順序可能會不同):
    // 5
    // 4
    // 3
    // 1
    for(auto &element:hashset){
        cout << element << endl;
    }
    
    return 0;
}