/**
* pat1045
* Author: zhiying
* Date: 2023.7.13 19:16
*
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
bool is_principal(vector<int> &vec, int idx);
bool is_principal_v2(vector<int> &vec, int idx);
bool is_principal_v3(vector<int> &vec, int idx);

int main(){
    int n = 0;
    cin >>n;
    vector<int> vec;
    vector<pair<int,int>> vec1;
    int max = 0;
    for (int i = 0;i <n;i ++){
        int num;
        cin >>num;
        vec.push_back(num);
        if (num >max){
            pair<int,int> p;
            p.first = i;
            p.second = num;
            max = num;
            vec1.push_back(p);
        }

    }
    for (int i = 0;i <vec1.size();i++){
        vector<int> tmp(vec.begin(),vec.end());
        if (vec1[i].first < vec.size()-2){
//            vector<int> tmp(vec.begin()+vec1[i].first+1,vec.end());
            sort((tmp.begin()+vec1[i].first+1),tmp.end());
            if (vec1[i].second > tmp[vec1[i].first+1]){
                vec1.erase(vec1.begin()+i);
                i--;
            }
            continue;
        }
        if (vec1[i].first == vec.size()-2){
            if (vec1[i].second > tmp[vec1[i].first+1]){
                vec1.erase(vec1.begin()+i);
                i--;
            }

        }
    }

    cout <<vec1.size()<<endl;
    for (int i = 0;i < vec1.size();i++){
        cout<<vec1[i].second;
        if (i != vec1.size() -1){
            cout <<' ';
        }
    }
    cout <<endl;
    return 0;
}

bool is_principal(vector<int> &vec, int idx){
    bool ret = true;
    for (int i =0;i < idx;i++){
        if (vec[i]>=vec[idx]){
            return false;
        }
    }

    for (int i =idx + 1;i < vec.size();i++){
        if (vec[i] <= vec[idx]){
            return false;
        }
    }

    return ret;
}
bool is_principal_v2(vector<int> &vec, int idx){
    bool ret = true;
    for (int i =idx + 1;i < vec.size();i++) {
        if (vec[i] <= vec[idx]) {
            return false;
        }
    }
    return ret;
}

bool is_principal_v3(vector<int> &vec, int idx){
    bool ret = true;

    return ret;
}