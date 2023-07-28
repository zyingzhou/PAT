/**
 * pat1113
 * Author：zhiying
 * Date: 23-7-28 10:31
 * Description:
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int to_int(char ch);
char to_char(int num);

int main() {
    string str1,str2;
    cin >>str1>>str2;
    string & lo = str1.size() <= str2.size() ? str1: str2;
    string & hi = str1.size() > str2.size() ? str1: str2;
    reverse(lo.begin(),lo.end());
    reverse(hi.begin(),hi.end());
    int carry =0;
    int i =0;
    for (;i < lo.size();i++){
        int su = to_int(lo[i]) + to_int(hi[i]) + carry;
        carry = su / 30;
        su =su % 30;
        hi[i] = to_char(su);
    }
    // 最后一位有进位
    while (carry != 0){
        if (i < hi.size()){
            int su = to_int(hi[i]) + carry;
            carry = su / 30;
            su = su % 30;
            hi[i] = to_char(su);
        }else{
            hi.push_back(to_char(carry));
            carry =0;
        }
        i++;
    }
    reverse(hi.begin(),hi.end());
    int head=0;
    for (int j =0;j<hi.size();j++){
        if (hi[j] != '0'){
            head = j;
            break;
        }
    }
    for (;head < hi.size();head++){
        cout << hi[head];
    }
    cout <<endl;
    return 0;
}

int to_int(char ch){
    if (isdigit(ch)){
        char zero = '0';
        return (int)ch - (int)zero;
    }else{
        char a = 'a';
        return (int)ch - (int)a + 10;
    }
}
char to_char(int num){
    if (num <10){
        int zero = 48;
        return (char) (zero + num);
    }else{
        int a = 97;
        return (char)(a + num - 10);
    }
}