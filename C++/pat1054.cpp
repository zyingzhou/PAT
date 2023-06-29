/**
* pat1054
* Author: zhiying
* Date: 2023.6.28 20:44
* Description: 测试点2 k=1,测试点3
*/
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>

using namespace std;
bool is_legal(string &str);


int main(){
    int n = 0;
    cin >>n;
    vector<float> items;
    for (int i = 0;i < n; i ++){
        string str;
        cin >>str;
        if(is_legal(str)){
            if (stof(str)>=-1000 && stof(str) <=1000){
                items.push_back(stof(str));
                continue;
            }
        }
        cout <<"ERROR: "<<str<<" is not a legal number"<<endl;

    }
    if (items.size()<= 1){
        if (items.empty()){
            cout << "The average of 0 numbers is Undefined"<<endl;
        } else{
            cout.setf(ios::fixed);
            cout <<"The average of "<<items.size()<<" number is "<<setprecision(2)<<items[0]<<endl;
        }

    } else{
        float sum = 0;
        for (auto m: items){
            sum += m;
        }
        float aver = sum / items.size();
        cout.setf(ios::fixed);
        cout <<"The average of "<<items.size()<<" numbers is "<<setprecision(2)<<aver<<endl;
    }
    return 0;
}

bool is_legal(string &str){
    bool ret = true;
    int dot_cnt = 0;
    int dot_loc = 0;
    int minus_cnt = 0;
    int minus_loc = 0;
    int idx  = 0;
    for (auto ch: str){
        idx++;
        if (isdigit(ch) || ch == '.'|| ch == '-'){

            if (ch == '.'){
                dot_loc = idx;
                dot_cnt++;
            }
            if (dot_cnt >1){
                return false;
            }

            if (ch == '-'){
                minus_loc = idx;
                minus_cnt++;
            }

            if (minus_cnt >1){
                return false;
            }
        }else{
            return false;
        }
    }

    if (dot_cnt == 1){
        if (dot_loc == 1 || dot_loc == str.size() || str.size() - dot_loc > 2){
            ret = false;
        }

    }

    if (minus_cnt ==1){
        if (minus_loc != 1){
            ret = false;
        }
    }
    return ret;

}