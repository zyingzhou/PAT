/*
** pat1030 
* Author: zhiying 
* Date: 2023.6.9
*
*/

#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

int find_perfect(vector<long>arrs, int tail, long p);

int main(){
    int n = 0;
    // 注意数据类型的范围
    long p = 0;
    cin >> n >> p;
    vector<long> arrs;
    for (int i = 0; i < n; i ++){
        long num;
        cin >> num;
        arrs.push_back(num);
    }
    sort(arrs.begin(),arrs.end());
    int result = 0;
    result = find_perfect(arrs, n, p);
    cout << result << endl;
    return 0;
}

int find_perfect(vector<long> arrs, int len, long p){
    int ret = 0;
//    int idx = 0;
    for (int i = 0; i < len; i ++){
        for(int j = i+ret; j <len ; j++){
            if (arrs[j] > (arrs[i]*p)){
                break;
            }
            ret++;
        }
    }

    return ret;
}