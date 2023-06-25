/**
* pat1038
* Author: zhiying
* Date: 2023.6.25 20:49
*
*/
#include <iostream>
#include <map>

using namespace std;

typedef struct {
    map<char, int> m;
    int len;
}Beads;

void read_line(Beads &b);
int main(){
    Beads give;
    Beads want;

    read_line(give);
    read_line(want);

    int guard = 1;
    int need = 0;
    for (auto &item : want.m){
        auto iter = give.m.find(item.first);

        if (iter != give.m.end()){
            if (give.m[item.first] < item.second){
                guard=0;
                need += (item.second - give.m[item.first]);
            }
        }else{
            guard = 0;
            need += (item.second);
        }
    }
    if (guard == 1){
        cout <<"Yes " <<(give.len-want.len)<<endl;
    }else{
        cout <<"No " <<need<<endl;
    }
    return 0;
}

void read_line(Beads &b){
    char ch;
    int i = 0;
    cin >>noskipws>>ch;
    while ((int)ch != 10){
        ++b.m[ch];
        i++;
        cin >>noskipws>>ch;
    }
    b.len = i;
}