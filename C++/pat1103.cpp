/**
 * pat1103
 * Author：zhiying
 * Date: 23-7-26 18:59
 * Description:
 * 
 */
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;
bool is_interge(float a);


int main() {
    float m,n;
    cin >>m>>n;

    float a = m;
    vector<pair<int, int>> result;

    for (;a <=n;){
        pair<int, int> p;
        if (is_interge(sqrt(pow(a,3) - pow(a-1,3)))){

            int b = ceil(sqrt(sqrt(pow(a,3) - pow(a-1,3)) / 2.0));
            for (int i = 0; i <2;i++){
                if (pow(pow(float(b - i),2) + pow(float(b-i-1),2),2) == pow(a,3) - pow(a-1,3)){
                    p.first = (int)a;
                    p.second = b;
                    result.push_back(p);
                    break;
                }
            }
        }
        a+= 1.0;
    }
    if (result.empty()){
        cout <<"No Solution"<<endl;
    }else{
        for (auto a: result){
            // 1满足条件但不是缘分数 测试点4
            if (a.first != 1){
                cout <<a.first << ' '<<a.second<<endl;
            }

        }
    }

    return 0;
}
bool is_interge(float a){
    bool ret = true;
    if (a-(int)a != 0){
        ret = false;
    }
    return ret;
}