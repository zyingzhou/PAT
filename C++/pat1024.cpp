/**
* pat1021
* Author: zhiying
* Date: 2021.2.21 17:44
* Update: 2023.6.13 7:13
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
void shift(vector<char> & num, char flag, int loc);
void print(vector<char> & num);
void shift_right(vector<char> & num, char flag, int loc);
void shift_left(vector<char> & num, char flag, int loc);

int main(){
//    double num;
    char flag1;
    char flag2;
    string tail;
    char ch;
    vector<char> num;
    cin >>noskipws>>ch;
    flag1 = ch;
    int idx = 0;
    int m = 0;
    int sign = 0;
    while ((int)ch !=10){

        cin >>noskipws>>ch;
        if (ch != 'E' && idx <= m){
            num.push_back(ch);
            m++;
            idx++;
            continue;
        }
        idx++;
        if (ch == 'E'){
            sign = idx;
            continue;
        }
        if (idx == sign + 1){
            flag2 = ch;
            continue;
        }
        if ((int)ch != 10){
            tail.push_back(ch);
        }
    }

    if (flag1 == '-'){
        cout << "-";
    }
    if (flag2 == '-'){
        shift_left(num,flag2,stoi(tail));

        print(num);
    }else{
        shift_right(num,flag2, stoi(tail));
    }
    return 0;
}
void shift_left(vector<char> & num, char flag, int loc){
    // 左移
    auto first = num.begin();
    if (*first == '0'){
        num.insert(first+2,loc, '0');
    }else{
        num.erase(first+1);
        num.insert(first,'0');
        num.insert(first + 1, '.');
        if (loc > 1){
            num.insert(first+ 2, loc-1, '0');
        }



//        auto first = num.begin();
//        num.erase(first+1);
//        if (loc < (num.size()-1)){
//            num.insert(first + 1 + loc,'.');
//        }else {
//            if (loc > (num.size() -1)){
//                for (int m = 0; m < loc + 1-num.size();m++){
//                    num.push_back('0');
//                }
//            }
//        }
//        auto p = first;
//        while (*p == '0'){
//            if (*(p+ 1) == '.'){
//                break;
//            }
//            if (*(p+1) != '0'){
//                num.erase(p);
//                break;
//            }
//            num.erase(p);
//        }

    }
}

void shift_right(vector<char> & num, char flag, int loc){
    //右移
    string str(num.begin(), num.end());
    double f = stof(str);
    double r = f * pow(10, loc);
    cout <<r<<endl;
}
void print(vector<char> & num){
    for (auto n: num){
        cout << n;
    }
    cout <<endl;
}

void shift(vector<char> & num, char flag, int loc){
    if (flag == '-'){
        auto first = num.begin();
        if (*first == '0'){
            num.insert(first+2,loc, '0');
        }else{
            num.erase(first+1);
            num.insert(first,'0');
            num.insert(first + 1, '.');
            if (loc > 1){
                num.insert(first+ 2, loc-1, '0');
            }
        }
    }else{

    }
}