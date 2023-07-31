/**
* pat1104
* Author: zhiying
* Date: 2023.7.30
*
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;
bool is_prime(int num);
int cal_sum(int num);
int max_divisor(int num1,int num2);
int max_divisor_v2(int num1,int num2);
int max_divisor_v3(int num1,int num2);
int max_divisor_v4(int num1,int num2);

int main(){
    int x;
    cin >>x;
    vector<vector<pair<int,int>>>results;
    for (int i = 0;i<x;i++){
        int k,m;
        cin >>k>>m;
        vector<pair<int,int>> result;
        for (int j = pow(10,k-1);j<pow(10,k);j++){
            int a_sum = cal_sum(j);
            if(a_sum == m){
                int b_sum = cal_sum(j+1);
                int max = max_divisor_v4(a_sum,b_sum);
                if (is_prime(max) && max>2){
                    pair<int,int> p;
                    p.first = b_sum;
                    p.second = j;
                    result.push_back(p);
                }
            }

        }
        results.push_back(result);
    }
    int idx = 1;
    for (auto v:results){
        cout <<"Case "<<idx<<endl;
        if (v.empty()){
            cout <<"No Solution"<<endl;
        }else{
            for (auto item:v){
                cout<<item.first<<' '<<item.second<<endl;
            }
        }
        idx++;
    }
}

bool is_prime(int num){
    bool ret = true;
    if (num ==1){ret = false;}
    for (int i = 2;i <= sqrt(num);i++){
        if (num % i == 0){
            ret = false;
            break;
        }
    }
    return ret;
}
int cal_sum(int num){
    int ret = 0;
    
    while(num >0){
    ret += (num % 10);
    num /= 10;
    }
    return ret;
}
int max_divisor(int num1,int num2){
    int ret = 1;
    int lo = num1 <=num2 ?num1:num2;
    for (int i = lo;i >= sqrt(lo);i--){
        if (num1 % i == 0 && num2 % i ==0){
             ret = i;
             break;        
        }
    }
    return ret;
}

int max_divisor_v2(int num1,int num2){
    if(num2 == 0)
        return num1;
    return max_divisor_v2(num2,num1%num2);
}

int max_divisor_v3(int num1,int num2){
    while (true)//用大数减去小数并将结果保存起来
    {
        if (num1 > num2)
        {
            num1 -= num2;
        }
        else if(num1 < num2)
        {
            num2 -= num1;
        }
        else//如果两个数相等时，则这个数就是最大公约数
        {
            return num1;
        }
    }
}
int max_divisor_v4(int num1,int num2){
    if(num1 == 0) return num2;
    if(num2 == 0) return num1;
    if(num1 % 2 == 0 && num2 % 2 == 0) return 2 * max_divisor_v4(num1 >> 1, num2 >> 1);
    else if(num1 % 2 == 0)  return max_divisor_v4(num1 >> 1, num2);
    else if(num2 % 2 == 0) return max_divisor_v4(num1, num2 >> 1);
    else return max_divisor_v4(abs(num1 - num2), min(num1, num2));
}