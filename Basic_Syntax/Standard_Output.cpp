// 引入標準輸入輸出函式庫
#include<iostream>
// C++ 的標準函式庫 (Standard Library) 中的所有變數、函式、類別
// 都放在一個叫做 std 的 命名空間 (namespace) 盒子裡
using namespace std;

int main(){
    int a = 10;
    // 輸出 10
    // endl 代表換行
    cout << a << endl; 

    // 可以串聯輸出
    // 輸出 Hello,World
    cout << "Hello" << "," << "World" << endl;

    // 可以字串與數字一起輸出
    string s = "abc";
    cout << "Hello " << a << endl;
    return 0;
}