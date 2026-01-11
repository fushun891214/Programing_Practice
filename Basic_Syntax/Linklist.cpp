#include<iostream>
#include<list>
using namespace std;

int main(){
    // list大小
    int n = 7;
    // list元素值
    int x = 2;
    // 初始化一個空的list
    list<int> lst1;
    // 初始化一個大小為n的list
    list<int> lst2(n);
    // 初始化一個包含1、3、5元素的list，C++11支援
    list<int> lst3{1,3,5};
    // 初始化一個大小為n，其中元素值皆為x
    list<int> lst4(n,x);
    return 0;
}