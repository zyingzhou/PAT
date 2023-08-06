/**
* pat1074
* Author: zhiying
* Date: 2023.8.6
*
*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int atoi(char ch);
char itoa(int num);

int main(){
    string code,num1,num2;
    cin >>code>>num1>>num2;
    reverse(code.begin(),code.end());
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    string &lo = num1.size() <= num2.size() ? num1 : num2;
    string &hi = num1.size() >num2.size() ? num1 : num2;
    int carry = 0;
    int i = 0;
    for (;i <lo.size();i++ ){
        int a = atoi(lo[i]) + atoi(hi[i]) + carry;
        if (code[i] != '0'){
            carry = a / atoi(code[i]);
            a = a % atoi(code[i]);

        }else{
            carry = a / 10;
            a = a % 10;
        }
        hi[i] = itoa(a);
    }
    while(carry != 0){
        if (i < hi.size()){
            int a = atoi(hi[i]) + carry;
            if (code[i] != '0'){
                carry = a / atoi(code[i]);
                a = a % atoi(code[i]);

            }else{
                carry = a / 10;
                a = a % 10;
            }
            hi[i] = itoa(a);
        }else{
            hi.push_back(itoa(carry));
            carry = 0;
        }
        i++;
    }
    reverse(hi.begin(),hi.end());
    // ignore zero
    int pos = 0;
    for (;pos< hi.size();pos++){
        if (hi[pos]!='0'){
            break;
        }
    }
    // 测试点5输出0
    if (pos == hi.size()){
        cout <<'0';
    }else{
        for (;pos < hi.size();pos++){
            cout <<hi[pos];
        }
    }

    cout <<endl;
//	cout <<hi<<endl;
    return 0;
}

int atoi(char ch){
    char zero = '0';
    return (int)ch - (int)zero;
}
char itoa(int num){
    int zero =48;
    return (char)(num+zero);

}