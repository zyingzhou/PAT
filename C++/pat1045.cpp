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

using namespace std;
bool is_principal(vector<int> &vec, int idx);
bool is_principal_v2(vector<int> &vec, int idx);
bool is_principal_v3(vector<int> &vec, int idx);

int main(){
    int n = 0;
    cin >>n;
    vector<int> vec;
    vector<int> vec1;
    int max = 0;
    for (int i = 0;i <n;i ++){
        int num;
        cin >>num;
        if (num >max){
            max = num;
            vec1.push_back(i);
        }
        vec.push_back(num);
        if (vec1.size() != 0){
            for (int m =0;m<vec1.size();m++){
                if (vec[vec1[m]] > num){
                    vec1.erase(vec1.begin()+m);
                    m--;
                }
            }
        }
    }
    int cnt = 0;
    vector<int> result;
//    for (int j = 0;j < vec1.size();j++){
//        if(is_principal(vec1,j)){
//            cnt++;
//            result.push_back(vec[j]);
//        }
//    }
//    for (auto item:vec1){
//        if(is_principal_v2(vec,item)){
//            cnt++;
//            result.push_back(vec[item]);
//        }
//    }
//    cout <<cnt<<endl;
    cout <<vec1.size()<<endl;
//    for (int i = 0;i < result.size();i++){
//        cout<<result[i];
//        if (i != result.size() -1){
//            cout <<' ';
//        }
//    }
    for (int i = 0;i < vec1.size();i++){
        cout<<vec[vec1[i]];
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