#include<iostream>
using namespace std;

int main(){
    int a = 5;
    
    if(a > 5){
        cout << "a > 5" << endl;
    }
    else if (a == 5){
        cout << "a == 5" << endl;
    }
    else{
        cout << "a < 5" << endl;
    }

    // 0 1 2 3 4
    for (int i = 0; i < 5; i++) {
        cout << i << " ";
    }
    cout << endl;

    int num = 100;
    // 100 50 25 12 6 3 1
    while (num > 0) {
        cout << num << " ";
        num /= 2;
    }
    cout << endl;
    return 0;
}