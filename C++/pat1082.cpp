/**
 * pat1082
 * Author：zhiying
 * Date: 23-7-24 21:02
 * Description:
 * 
 */
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;
bool sort_by_distance(pair<string,int> &p1, pair<string,int> &p2);

int main() {
    int n;
    cin >>n;
    vector<pair<string,int>>results;
    for (int i = 0;i <n;i++){
        pair<string,int> p;
        cin >>p.first;
        int x,y;
        cin >>x>>y;
        p.second = x * x + y * y;
        results.push_back(p);
    }
    sort(results.begin(),results.end(), sort_by_distance);
    cout <<results[0].first <<' '<<results[n-1].first<<endl;
    return 0;
}
bool sort_by_distance(pair<string,int> &p1, pair<string,int> &p2){
    return p1.second < p2.second;
}