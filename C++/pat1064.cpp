/**
* pat1064
* Author: zhiying
* Date: 2023.7.20 18:52
*
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
int make_sum(int num);
int main(){
    int n;
    map<int, int>friends;
    cin >>n;
    for (int i =0;i <n;i++){
        int num = 0;
        cin >>num;
        ++friends[make_sum(num)];
    }
    vector<int>result;
    for (auto item: friends){
        result.push_back(item.first);
    }
    sort(result.begin(),result.end());
    cout <<result.size()<<endl;
    for (int i =0;i < result.size();i++){
        cout<<result[i];
        if (i != result.size() -1 ){
            cout <<' ';
        }
    }
    cout <<endl;
    return 0;
}

int make_sum(int num){
    int ret =0;
    while (num >0){
        ret += num % 10;
        num /= 10;
    }
    return ret;
}
