/**
* pat1042
* Author: zhiying
* Date: 2023.6.26 18:59
*
*/
#include <iostream>
#include <map>
#include <string>


using namespace std;
void read_line(map<char, int> &strs);

int main(){
    map<char, int> line;
    read_line(line);
    char fre_ch;
    int fre_cnt = 0;

    for (auto s: line){
        if (s.second > fre_cnt){
            fre_ch = s.first;
            fre_cnt = s.second;
            continue;
        }

        if (s.second == fre_cnt){
            if ((int)s.first <(int)fre_ch){
                fre_ch = s.first;
                fre_cnt = s.second;
                continue;
            }

        }
    }
    cout <<fre_ch << ' '<<fre_cnt<<endl;
    return 0;
}

void read_line(map<char, int> &strs){
    char ch;
    cin >>noskipws>>ch;

    while ((int)ch != 10){
        // 忽略非英文
        if(isalpha(ch)){
            if(isupper(ch)){
                ch = tolower(ch);
            }
            ++strs[ch];
        }
        cin >>noskipws>>ch;
    }
}