/**
 * pat1043
 * Author：zhiying
 * Date: 23-8-4 16:12
 * Description:
 * 
 */
#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    set<char> item = {'P','A','T','e','s','t'};
    map<char, int> strs;
    char ch;
    cin >>noskipws>>ch;
    int cnt=0;
    while((int)ch != 10){
        if (item.find(ch) != item.end()){
            ++strs[ch];
            cnt++;
        }
        cin >>noskipws>>ch;
    }
    for (int i = 0;i < cnt;){
        if (strs['P'] >0){
            cout <<'P';
            --strs['P'];
            i++;
        }
        if (strs['A'] >0){
            cout <<'A';
            --strs['A'];
            i++;
        }
        if (strs['T'] >0){
            cout <<'T';
            --strs['T'];
            i++;
        }
        if (strs['e'] >0){
            cout <<'e';
            --strs['e'];
            i++;
        }
        if (strs['s'] >0){
            cout <<'s';
            --strs['s'];
            i++;
        }
        if (strs['t'] >0){
            cout <<'t';
            --strs['t'];
            i++;
        }
    }
    cout<<endl;
    return 0;
}
