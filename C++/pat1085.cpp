/**
 * pat1085
 * Author：zhiying
 * Date: 23-7-25 20:52
 * Description:
 * 
 */
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool sort_by_grade(pair<string,pair<float,int>> &p1, pair<string,pair<float,int>> &p2);
int main() {
    int n;
    cin >>n;
    map<string,pair<float,int>> result;
    for (int i = 0;i <n;i++){
        string id;
        cin >>id;
        int grade;
        cin >>grade;
        string sch_name;
        cin >>sch_name;
        for (auto &s:sch_name){
            if (isupper(s)){
                s = tolower(s);
            }
        }
        if (id[0] == 'A'){
            result[sch_name].first += grade;
        }
        if (id[0] == 'B'){
            result[sch_name].first += grade / 1.5;
        }
        if (id[0] == 'T'){
            result[sch_name].first += grade * 1.5;
        }
        result[sch_name].second += 1;
    }
    vector<pair<string,pair<float,int>>> results(result.begin(),result.end());
    for(auto &p: results){
        p.second.first = floorf(p.second.first);
    }
    sort(results.begin(),results.end(), sort_by_grade);
    pair<float, int> before;
    before.first = results.begin()->second.first;
    before.second = 1;
    cout<< results.size()<<endl;
    int i = 1;
    for(auto &p: results){
        if (p.second.first != before.first){
            before.first = p.second.first;
            before.second = i;
        }
        cout <<before.second<< ' '<< p.first << ' ' <<p.second.first<< ' '<<p.second.second<<endl;
        i ++;
    }
    return 0;
}
bool sort_by_grade(pair<string,pair<float,int>> &p1, pair<string,pair<float,int>> &p2){
    if(p1.second.first == p2.second.first){
        if (p1.second.second == p2.second.second){
            return p1.first <p2.first;
        }else{
            return p1.second.second < p2.second.second;
        }
    }else{
        return p1.second.first > p2.second.first;
    }
}