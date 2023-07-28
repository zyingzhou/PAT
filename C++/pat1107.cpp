/**
 * pat1107
 * Author：zhiying
 * Date: 23-7-28 15:05
 * Description:
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n,m;
    cin >>n>>m;
    vector<int> result;
    for (int i =0;i <n;i++){
        int max = -1;
        for (int j = 0;j <m;j++){
            int weight;
            cin >>weight;
            if (max < weight){
                max = weight;
            }
        }
        result.push_back(max);
    }
    for (int i = 0;i < result.size();i++){
        cout <<result[i];
        if (i != result.size()-1){
            cout <<' ';
        }else{
            cout <<endl;
        }
    }
    sort(result.begin(),result.end());
    cout <<result[result.size()-1];
    return 0;
}
