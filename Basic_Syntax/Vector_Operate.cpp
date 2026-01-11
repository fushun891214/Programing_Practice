// vector 實際操作
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 10;

    // 初始化一個 int 類型的空陣列，陣列大小為10，預設每個元素為0
    vector<int> nums(n);
    // 輸出0(false)
    cout << nums.empty() << endl;

    // 輸出陣列大小10
    cout << nums.size() << endl;
    // 在陣列尾端插入元素20
    nums.push_back(20);
    // 輸出陣列大小11
    cout << nums.size() << endl;
    // 輸出陣列尾端元素
    cout << nums.back() << endl;

    // 移除陣列尾端元素
    nums.pop_back();
    // 輸出陣列大小10
    cout << nums.size() << endl;

    // 可以透過方括號直接修改值
    nums[0] = 11;
    // 輸出11
    cout << nums[0] << endl;
    // 在 index 3的地方插入元素99
    nums.insert(nums.begin() + 3,99);
    // 刪除 index 2的元素
    nums.erase(nums.begin() + 2);
    //交換 index 0 與 index 1 的元素
    swap(nums[0],nums[1]);
    // 拜訪所有陣列元素
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    
    return 0;
}
