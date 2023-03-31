/**
* 
* Author: zhiying
* Date: 2023/1/3
* Copyright (c) 2023 All rights reserved.
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> a;
    int b = 0;
    for (int i = 0;i < 4;i ++){
        cin >> b;
        a.push_back(b);
    }

    for (auto i : a){
        cout << i
    }
//    b != 0

//    cin >> a;
//    cin >> b;
//    cout << a;
    cout << a.size();
    cout << a.capacity();

    return 0;
}


