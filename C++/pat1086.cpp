/**
 * pat1086
 * Author：zhiying
 * Date: 23-8-1 22:28
 * Description:
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a,b;
    cin >>a>>b;
    string str = to_string(a*b);
    reverse(str.begin(),str.end());
    // 注意前导有0的情况
    int pos =0;
    for (int i = 0;i <str.size();i++){
        if (str[i] != '0'){
            pos = i;
            break;
        }
    }
    for (;pos<str.size();pos++){
        cout <<str[pos];
    }
    cout <<endl;
    return 0;
}
