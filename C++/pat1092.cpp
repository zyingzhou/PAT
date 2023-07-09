/**
* pat1092
* Author: zhiying
* Date: 2023.7.9 8:31
* Description:
*/
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;
bool cmp(pair<int,int> &p1, pair<int,int> &p2);
int main(){
    map<int,int> cake;
    int n;
    int m;
    cin >>n>>m;
    for (int i = 0;i < m;i++){
        for (int j = 1; j <=n;j++){
            int sale= 0;
            cin >>sale;
            cake[j] += sale;
            //关联容器是否有序
        }
    }
    vector<pair<int, int>> vec(cake.begin(),cake.end());
    sort(vec.begin(), vec.end(),cmp);
    int max = vec[0].second;
    cout <<max<<endl;
    vector<int> result;
    for (auto p:vec){
         if (p.second ==max){
             result.push_back(p.first);
         } else{
             break;
         }
    }
    for (int i =0;i < result.size();i++){
        cout <<result[i];
        if(i != result.size() - 1){
            cout <<' ';
        }
    }
    cout <<endl;
    return 0;
}

bool cmp(pair<int,int> &p1, pair<int,int> &p2){
    if (p1.second == p2.second){
        return p1.first <p2.first;
    }
    return p1.second >p2.second;

}