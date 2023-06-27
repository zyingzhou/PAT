/**
* pat1047
* Author: zhiying
* Date: 2023.6.27 22:39
*
*/
#include <iostream>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;
bool sort_by_grade(pair<int, int>&p1,pair<int, int>&p);
int main(){
    map<int, int>team;
    int n =0;
    cin >>n;
    for (int i = 0; i < n;i++){
        char ch;
        int team_no,no,grade;
        cin >>team_no>>ch>>no;
        cin >>grade;
        team[team_no] += grade;
    }
    int max_team = 0;
    int max = 0;
    for (auto item:team){
        if (item.second > max){
            max = item.second;
            max_team = item.first;
        }
    }
    cout <<max_team << ' '<<max<<endl;
    return 0;
}
bool sort_by_grade(pair<int, int>&p1,pair<int, int>&p2){
    return p1.second >p2.second;
}