/*
** pat1033
* Author: zhiying
* Date: 2023.6.9
*
* Description:
*/
#include <iostream>
#include <vector>
#include <set>
#include <cctype>

using namespace std;

int main(){
    set <char> broken_chars;
    vector<char> strs(100010);
    char ch;
    // version2

    while (cin >> noskipws >>ch){
//        cout <<"ch=" <<ch <<"ch的ASCII码="<<(int)ch<<endl;
        if ((int)ch ==10) break;
        // upper to lower
        if (isupper(ch)){
            ch = tolower(ch);
        }
        broken_chars.insert(ch);
//        //不忽略空白符
//        cin >> noskipws >>ch;
    }
    int idx = 0;
    while (cin >> noskipws >>ch){
//        cout <<"ch=" <<ch <<"ch的ASCII码="<<(int)ch<<endl;
        if ((int)ch ==10) break;
        strs[idx] = ch;
        idx++;
//        //不忽略空白符
//        cin >> noskipws >>ch;
    }
    int remain = idx;
    auto first=strs.begin();
    char key = '+';
    for (int j = 0; j < idx;j++){
        if (isupper(strs[j])){
            char c = tolower(strs[j]);
            if (broken_chars.find(c) != broken_chars.end() || (broken_chars.find(key) != broken_chars.end())){
                strs.erase(first + j);
                remain--;
                j--;
            }
        } else{
            if (broken_chars.find(strs[j]) != broken_chars.end()){
                strs.erase(first + j);
                remain--;
                j--;
            }
        }

        // 如何上档键坏了
//        if (broken_chars.find(key) != broken_chars.end() && isupper(key)){
//            strs.erase(first + j);
//        }

    }
    // version1
//    cin >> noskipws >>ch;
//    while (((int) ch) != 10){
//        cout <<"ch=" <<ch <<"ch的ASCII码="<<(int)ch<<endl;
//        broken_chars.insert(ch);
//        //不忽略空白符
//        cin >> noskipws >>ch;
//    }
//    for (auto ch1 :broken_chars){
//        cout <<ch1;
//    }
    for (int j = 0; j < remain; j++){
        cout <<strs[j];
    }
    cout << endl;
    return 0;
}