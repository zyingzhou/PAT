/**
 * pat1073
 * Author：zhiying
 * Date: 23-7-23 21:13
 * Description:
 * 
 */
#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    int n,m;
    cin >>n>>m;
    vector<pair<int,set<char>>> answers;
    vector<int> right_options;
    for (int i = 0;i < m;i++){
        pair<int,set<char>> answer;
        cin >>answer.first;
        int tmp;
        cin >>tmp;
        cin >>tmp;
        right_options.push_back(tmp);
        for (int j = 0;j < tmp;j++){
            char ch;
            cin >>ch;
            answer.second.insert(ch);
        }
        answers.push_back(answer);
    }
    vector<float> result;
    map<string, int> wrong_cnt;
    for(int i = 0;i < n;i++){
        float score = 0.0;
        for (int k = 0;k <m;k++){
            char ch;
            cin >>ch;
            int cnt;
            cin >>cnt;
            int right = 0;
            int wrong = 0;
            for (int j = 0;j <cnt;j++){
                char opt;
                if (j != cnt - 1){
                    cin >>opt;
                }else{
                    cin>>opt>>ch;
                }
                if (answers[k].second.find(opt) != answers[k].second.end()){
                    right++;
                }else{
                    wrong++;
                    string qes_id = to_string(k+1);
                    qes_id.push_back('-');
                    qes_id.push_back(opt);
                    ++wrong_cnt[qes_id];
                }
            }
            if (right == right_options[k] && wrong == 0){
                score += answers[k].first;
                continue;
            }
            if (right < right_options[k] && right > 0 && wrong == 0){
                score += (answers[k].first / 2.0);
                continue;
            }
            if (right < right_options[k] && wrong >0){
                score += 0.0;
            }

        }
        result.push_back(score);
    }
    for (auto res:result){
        cout.setf(ios::fixed);
        cout <<setprecision(1)<<res<<endl;
    }
    if (wrong_cnt.empty()){
        cout <<"Too simple"<<endl;
    }else{

        for (auto m: wrong_cnt){
            cout <<m.second<<' '<<m.first<<endl;
        }
    }

    return 0;
}
