/**
* pat1101
* Author: zhiying
* Date: 2023.6.29 21:49
* Description:
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    string str;
    int d=0;

    cin >>str>>d;
    string tmp = str.substr(str.size() - d, d);
    string a = str;
    str.erase(str.size() - d, d);
    string b = tmp + str;
    float multiple = stof(b) / stof(a);
    cout.setf(ios::fixed);
    cout <<setprecision(2)<<multiple<<endl;

    return 0;
}