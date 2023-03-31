/**
* pat1003 for c plus plus
* Author: zhiying
* Date: 2022/12/10 update:2023/4/1 7:37
* Copyright (c) 2022 All rights reserved.
*/
#include <iostream>
#include <string>
#include <cstring>
#include <regex>

using namespace std;
void input(string *strs, int len);
void check_str(string str);
void check(string *strs, int len);


int main(){
    int n = 0;
    cin >> n;
    if (n > 10){
        return 0;
    }
    string strs[n];
    input(strs, n);
    check(strs, n);
    return 0;
}

void input(string *strs, int len){

    for(int i = 0; i < len;i ++){

        cin >> strs[i];
    }
}

void check(string *strs, int len){
    /**
     * L (P) M (T)R
     * L * M = R
     */
    for (int i = 0; i < len; i ++){
        check_str(strs[i]);
    }
}

void check_str(string str){
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    int pointer1 = 0;
    int pointer2 = 0;
    for (int j = 0 ; j < str.length();j ++){

        if (str[j] == 'P'){
            cnt1++;
            pointer1 = j;
            continue;
        }

        if (str[j] == 'A'){
            cnt2 ++;
            continue;
        }
        if (str[j] == 'T'){
            cnt3++;
            pointer2 = j;
            continue;
        }
        cnt4++;
    }

    if (cnt1 != 1 || cnt3 != 1 || cnt2 < 1 || cnt4 != 0){
        cout << "NO"<<endl;
        return;
    }

    int len = str.length();
    if (pointer1 * (pointer2 - pointer1-1) == (len -1- pointer2) && (pointer2 - pointer1) > 1){
        cout << "YES"<< endl;
    } else{
        cout << "NO"<<endl;
    }

}
