/**
* pat1059
* Author: zhiying
* Date: 2023.7.17 20:52
*
*/
#include <iostream>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;
bool is_prime_number(int num);

int main(){
    int n = 0;
    cin >>n;
    map<string, int> can_rank;
    for (int i = 1;i<= n;i++){
        string id;
        cin >>id;
        can_rank[id] = i;
    }
    int k = 0;
    cin >>k;
    set<string> checked;
    vector<pair<string,string>> result;
    for (int i =0;i < k;i++){
        pair<string, string> p;
        string id;
        cin >>id;
        p.first= id;
        if(can_rank.find(id) != can_rank.end()){
            if (checked.empty()){
                checked.insert(id);
            }else{
                if(checked.find(id) != checked.end()){
//                    cout <<id<<": "<<"Checked"<<endl;
                    p.second = "Checked";
                    result.push_back(p);
                    continue;
                }else{
                    checked.insert(id);
                }
            }
            if (can_rank[id] == 1){
//                cout <<id<<": "<<"Mystery Award"<<endl;
                p.second = "Mystery Award";

            } else if (is_prime_number(can_rank[id])){
//                cout <<id<<": "<<"Minion"<<endl;
                p.second = "Minion";
            }else{
//                cout <<id<<": "<<"Chocolate"<<endl;
                p.second = "Chocolate";
            }

        }else{
//            cout <<id<<": "<<"Are you kidding?"<<endl;
            p.second = "Are you kidding?";
        }
        result.push_back(p);
    }
    for (auto p:result){
        cout <<p.first<<": "<<p.second<<endl;
    }

    return 0;
}
bool is_prime_number(int num){
    // num >1;
    bool ret = true;

    for (int i = 2;i <= sqrt(num);i++){
        if (num % i == 0){
            ret = false;
            break;
        }
    }
    return ret;
}
