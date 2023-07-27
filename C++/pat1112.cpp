/**
 * pat1112
 * Author：zhiying
 * Date: 23-7-27 22:49
 * Description:
 * 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int n,t;
    cin >>n>>t;
    vector<int> points;
    vector<pair<int,int>> ranges;
    pair<int, int> range;
    int sign = 0;
    for (int i = 0;i < n;i++){
        int point;
        cin >>point;
        points.push_back(point);
        if (point > t){
            if (points.size() > 1){
                if (points[i-1] <= t){
                    range.first = i;
                }
            }else{
                range.first = i;
            }

            if (i == n - 1){
                range.second = i;
                ranges.push_back(range);
            }

        }else{
            if (points.size() > 1){
                if (points[i-1] > t){
                    range.second = i-1;
                    ranges.push_back(range);
                }
            }
        }
    }
    if (ranges.empty()){
        sort(points.begin(),points.end());
        cout << points[points.size() -1]<<endl;
    }else{
        for (auto item : ranges){
            cout <<'['<<item.first <<", "<<item.second<<']'<<endl;
        }
    }
    return 0;
}
