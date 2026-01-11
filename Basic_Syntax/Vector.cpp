// vector 是 C++ 函式庫提供的動態陣列
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 7;
    int m = 8;
    // 初始化一個 int 類型的空陣列
    vector <int> nums;
    // 初始化一個 int 類型的空陣列，陣列大小為n，預設每個元素為0
    vector <int> nums1(n);
    // 初始化一個 int 類型的陣列，元素包含1、3、5，C++11支援
    vector <int> nums2{1,3,5};
    // 初始化一個二維 int 類型陣列
    vector <vector <int> > dp;
    // 初始化一個二維 m * n 大小的布林陣列
    // 設置所有的值皆為 true 
    vector <vector <bool> > boolMatrix(m,vector<bool>(n,true));
    return 0;
}