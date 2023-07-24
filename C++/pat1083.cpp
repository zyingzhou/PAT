/**
 * pat1083
 * Author：zhiying
 * Date: 23-7-24 21:26
 * Description:
 * 
 */
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >>n;
    map<int, int> count;
    for (int i = 1;i <=n;i++){
//        pair<int,int> p;
        int card;
        cin >>card;
        ++count[abs(card - i)];
    }
    vector<pair<int,int>> results(count.begin(),count.end());

    for (int i= results.size() - 1 ;i >=0;i--){
        if (results[i].second > 1){
            cout <<results[i].first <<' '<<results[i].second<<endl;

        }
    }
    return 0;
}

