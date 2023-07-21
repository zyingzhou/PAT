/**
* pat1065
* Author: zhiying
* Date: 2023.7.21 09:26
*
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
    int n;
    cin >>n;
    vector<pair<string,string>>married;

    for (int i = 0;i < n;i++){
        pair<string,string>p;
        string male,female;
        cin >>male>>female;
        p.first = male;
        p.second = female;
        married.push_back(p);
    }
    int m;
    cin >>m;
    set<string> result;
    for (int i =0;i <m;i++){
        string man;
        cin >>man;
        result.insert(man);
    }
    for (auto couple:married){

        if ( result.find(couple.first) != result.end() &&  result.find(couple.second)!= result.end()){
            auto pos1 = result.find(couple.first);
            result.erase(pos1);
            auto pos2 = result.find(couple.second);
            result.erase(pos2);
        }
    }
    vector<string> single(result.begin(), result.end());
    sort(single.begin(),single.end());
    cout <<single.size()<<endl;
    for(int i = 0;i < single.size();i++){
        cout <<single[i];
        if (i != single.size() -1){
            cout <<' ';
        }else{
            cout <<endl;
        }
    }

    return 0;
}
