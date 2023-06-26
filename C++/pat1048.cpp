/**
* pat1048
* Author: zhiying
* Date: 2023.6.26 19:47
*
*/
#include <iostream>
#include <map>
#include <vector>

using namespace std;
int chtoi(char &ch);
int main(){
    vector<char> a;
    vector<char> b;

    vector<char> *p;
    p = &a;
    char ch;
    cin >>noskipws>>ch;

    while((int)ch != 10){
        if (ch == ' '){
            p = &b;
            cin >>noskipws>>ch;
            continue;
        }
        p->push_back(ch);
        cin >>noskipws>>ch;
    }
    // B的位数不足时前面补0
    if (a.size() > b.size()){
        for (;a.size()>b.size();){
            b.insert(b.begin(),'0');
        }
    }
    auto a_end= a.end();
    auto b_end = b.end();
    for (int i =1; i <=a.size();i++){
        --a_end;
        --b_end;

        if (i % 2 == 1){
            int remain = (chtoi(*a_end) + chtoi(*b_end)) % 13;
            if (remain >9){
                map<int, char> m={{10, 'J'}, {11, 'Q'}, {12, 'K'}};
                *b_end = m[remain];
            }else{
                *b_end = remain + '0';
            }
        }else{
            int remain = chtoi(*b_end)- chtoi(*a_end);
            if (remain < 0){
                remain += 10;
            }
            *b_end = remain + '0';
        }
    }

    for(auto item: b){
        cout << item;
    }
    cout <<endl;
    return 0;
}

int chtoi(char &ch){
    char c = '0';
    return (int)ch - (int)c;
}