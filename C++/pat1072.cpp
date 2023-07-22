/**
 * pat1072
 * Author：zhiying
 * Date: 23-7-22 15:08
 * Description:
 * 
 */
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main() {
    int n,m;
    cin >>n>>m;
    set<string> forbid;
    vector<pair<string,vector<string>>> chk;
    int forbid_thing=0;
    for (int i = 0 ;i < m;i++){
        string str;
        cin >>str;
        forbid.insert(str);
    }
    for (int i = 0;i < n;i++){
        pair<string, vector<string>> p;
        string name;
        int cnt;
        cin >>name;
        p.first = name;
        cin >>cnt;
        for (int j = 0; j <cnt;j++){
            string str;
            cin >>str;
            if (forbid.find(str) != forbid.end()){
                p.second.push_back(str);
                forbid_thing++;
            }
        }
        if (!p.second.empty()){
            chk.push_back(p);
        }
    }
    for (auto p: chk){
        cout<<p.first<<": ";
        for (int i = 0;i < p.second.size();i++){
            cout <<p.second[i];
            if (i != p.second.size() -1){
                cout <<' ';
            }else{
                cout <<endl;
            }
        }
    }
    cout <<chk.size()<<' '<<forbid_thing<<endl;
    return 0;
}
