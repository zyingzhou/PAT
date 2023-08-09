/**
 * pat1080
 * Author：zhiying
 * Date: 23-8-9 20:06
 * Description:
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct {
    int program = -1;
    int mid = -1;
    int final = -1;
    int total;
}Grade;
bool sort_by_score(pair<string,Grade> &p1, pair<string,Grade> &p2);

int main() {
    int p,m,n;
    map<string, Grade > scores;
    cin >>p>>m>>n;
    for (int i =0;i <p;i++){
        string name;
        int score;
        cin >>name >>score;
        if (score >=200){
            scores[name].program = score;
        }
    }
    // mid
    for (int i = 0;i <m;i++){
        string name;
        int score;
        cin >>name >>score;
        if (scores.find(name) != scores.end()){
            scores[name].mid = score;
        }
    }
    // final
    for (int i = 0;i <n;i++){
        string name;
        int score;
        cin >>name >>score;
        if (scores.find(name) != scores.end()){
            scores[name].final = score;
        }
    }
    vector<pair<string,Grade >> result;
//    auto v = scores.begin();
    for (auto &v : scores){

        if (v.second.mid >v.second.final){
            v.second.final = v.second.final == -1 ? 0: v.second.final;
            v.second.mid = v.second.mid == -1 ? 0: v.second.mid;
            v.second.total = round(v.second.mid * 0.4 + v.second.final * 0.6);
        }else{
            v.second.final = v.second.final == -1 ? 0: v.second.final;
            v.second.total = v.second.final;
        }
        if (v.second.total >=60){
            result.push_back(v);
        }
        
    }
//    vector<pair<string,Grade >> result(scores.begin(),scores.end());
    sort(result.begin(),result.end(), sort_by_score);

    for (auto res: result){
        cout <<res.first<<' '<<res.second.program<<' '<<res.second.mid<<' '<<res.second.final<<' '<<res.second.total<<endl;
    }
    return 0;
}

bool sort_by_score(pair<string,Grade> &p1, pair<string,Grade> &p2){
    if (p1.second.total == p2.second.total){
        return p1.first <p2.first;
    }else{
        return p1.second.total > p2.second.total;
    }
}
