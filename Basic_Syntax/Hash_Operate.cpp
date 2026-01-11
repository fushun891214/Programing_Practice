#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // 初始化一個包含一些key value的hash map
    unordered_map<int,string> hashmap {{1,"one"},{2,"two"},{3,"three"}};
    
    // 檢查hash map是否為空
    // 輸出：0
    cout << hashmap.empty() << endl;
    
    // 獲取hash map大小
    // 輸出：3
    cout << hashmap.size() << endl;
    
    // 檢查hash map指定key是否存在
    // contains 是 C++ 20才有的函數
    // 輸出：Key 2 -> two
    if(hashmap.contains(2)){
        cout << "Key 2 -> " << hashmap[2] << endl;
    }
    else{
        cout << "Key 2 not found" << endl;
    }
    
    // 取得特定key的value，如果該key不存在則返回預設型別的值
    cout << hashmap[4] << endl;
    
    // 在特定key插入新值
    hashmap[4] = "four";
    
    // 取得特定key的value
    // 輸出：four
    cout << hashmap[4] << endl;
    
    // 刪除特定key與其value
    hashmap.erase(3);
    
    // 檢查hash map指定key是否存在
    // 輸出：Key 3 not found
    if(hashmap.contains(3)){
        cout << "Key 3 -> " << hashmap[3] << endl;
    }
    else{
        cout << "Key 3 not found" << endl;
    }
    
    // 拜訪hash map的所有元素
    // 輸出（順序可能不同）：
    // 4 -> four
    // 2 -> two
    // 1 -> one
    for(auto &pair:hashmap){
        cout << pair.first << " -> " << pair.second << endl;
    }
    
    // 特別注意，拜訪不存在的key會自動創建對應的key
    unordered_map<int,string> hashmap2;
    
    // hashmap2的數量為0
    cout << hashmap2.size() << endl;
    
    // 拜訪不存在的key會自動創建Key，其value為預設的資料型別值
    cout << hashmap2[1] << endl;
    cout << hashmap2[2] << endl;
    
    // hashmap2的數量為2
    cout << hashmap2.size() << endl;
    
    return 0;
}