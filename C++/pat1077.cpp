/**
 * pat1077
 * Author：zhiying
 * Date: 23-7-22 15:49
 * Description:
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >>n>>m;
    vector<int> grade;
    for (int i = 0;i < n;i++){
        float g1 = 0.0;
        int g2 = 0;
        vector<int> scores;
        for (int j = 0;j < n;j++){
            if (j ==0){
                cin >>g2;
            }else{
                int score;
                cin >>score;
                if (score >= 0 && score <=m){
                    scores.push_back(score);
                }
            }
        }
        sort(scores.begin(),scores.end());
        int mk_sum = 0;
        for (int k = 1;k < scores.size() - 1;k++){
            mk_sum += scores[k];
        }
        g1 = mk_sum / (float )(scores.size() -2);
        int score = round((g1 + g2) / 2.0);
        grade.push_back(score);
    }
    for (auto item : grade){
        cout <<item<<endl;
    }
    return 0;
}
