/**
* pat1001 for c plus plus
* Author: zhiying
* Date: 2022/7/22
* Copyright (c) 2022 All rights reserved.
*/
#include <iostream>
using namespace std;

int main(){
    int k = 0;
    cin >> k;
    int cnt = 0;

    while(k!= 1){
        k = k % 2 == 1 ? (3 * k + 1) / 2 : k / 2;
        cnt++;
    }
    cout << cnt <<endl;

    return 0;
}



