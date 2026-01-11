#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // 初始化一個空的hash map
    unordered_map<int,string> hashmap1;
    // 初始化一個包含一些key value的hash map
    unordered_map<int,string> hashmap2 {{1,"one"},{2,"two"},{3,"three"}};
    
    return 0;
}