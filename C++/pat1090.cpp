/**
* pat1090
* Author: zhiying
* Date: 2023.7.9 21:59
* Description:
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
bool is_incompatible(set<string> &vec,multimap<string,string> &items);

int main(){
    int n,m;
    cin >>n>>m;
    multimap<string,string> items;
    for (int i = 0;i < n;i++){
        pair<string, string>p;
        string fir,sec;
        cin >>p.first>>p.second;
        items.insert(p);
//        items[fir] = sec;
    }

    vector<string> result;
    for (int i = 0;i <m;i++){
        int cnt = 0;
        cin >>cnt;
        set<string> vec;
        for (int j = 0;j <cnt;j++){
            string good;
            cin >>good;
            vec.insert(good);
        }
        if (is_incompatible(vec,items)){
            result.push_back("No");
//            cout <<"No"<<endl;
        } else{
            result.push_back("Yes");
//            cout <<"Yes"<<endl;
        }

    }
    for (auto item:result){
        cout <<item<<endl;
    }

    return 0;
}
bool is_incompatible(set<string> &vec,multimap<string,string> &items){
    bool ret = false;
    for (auto v: vec){
        if(items.find(v) != items.end()){
            for (auto p :items){
                if (p.first == v){
                    if (vec.find(p.second) != vec.end()){
                        return true;
                    }
                }
            }
        }

    }
    return ret;
}
