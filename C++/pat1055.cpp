/**
* pat1090
* Author: zhiying
* Date: 2023.7.9 22:26
* Description:
*/
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

using namespace std;
bool cmp(pair<string,int> &p1,pair<string,int> &p2);
void sort_from_mid(vector<pair<string, int>> &vec);
void print_deque(vector<pair<string, int>> &vec);

int main(){
    int n,k;
    cin >>n>>k;
    map<string, int>people;
    for (int i = 0;i <n;i++){
        string name;
        int height;
        cin >>name>>height;
        people[name] = height;
    }
    vector<pair<string,int>>peoples(people.begin(),people.end());
    sort(peoples.begin(),peoples.end(),cmp);
    int per_row = n / k;
    auto iter = peoples.begin();
    for(int i = 0; i < k;i++){
        if (i == 0){
            vector<pair<string, int>>vec(iter,iter + per_row + (n % k));
            sort_from_mid(vec);
            // 输出一行结果
            print_deque(vec);
            // 改变迭代器的位置
            iter = iter + per_row + (n % k);
        }else{
            vector<pair<string, int>>vec(iter,iter+per_row);
            // 输出一行结果
            sort_from_mid(vec);
            print_deque(vec);
            // 改变迭代器的位置
            iter = iter + per_row;
        }
    }
    return 0;
}

bool cmp(pair<string,int> &p1,pair<string,int> &p2){
    if (p1.second == p2.second){
        return p1.first <p2.first;
    }
    return p1.second >p2.second;
}

void sort_from_mid(vector<pair<string, int>> &vec){
    vector<pair<string, int>>tmp(vec.begin(),vec.end());
    int len = tmp.size();
    for (int i = 0;i <len;i++){
        if (i ==0){
            tmp[len/2] = vec[0];
            continue;
        }
        if (i % 2 != 0){
            tmp[len/2 - (i /2 + i % 2)] = vec[i];
            continue;
        }
        if (i % 2 == 0){
            tmp[len/2+i/2] = vec[i];
            continue;
        }
    }
    for (int i =0;i<len;i++){
        vec[i] = tmp[i];
    }
}
void print_deque(vector<pair<string, int>> &vec){
    for (int i = 0;i < vec.size();i ++){
        cout <<vec[i].first;
        if (i != vec.size() -1){
            cout<<' ';
        }else{
            cout <<endl;
        }
    }
}
