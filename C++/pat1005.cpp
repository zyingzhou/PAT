/**
* 
* Author: zhiying
* Date: 2022/7/18
* Copyright (c) 2022 All rights reserved.
*/
#include <iostream>

int is_perfect_digtal(int *nums, int len,int num);
int in_arrary(int *nums, int len, int num);

using namespace std;

int main(){
    int nums[100];
    int k = 0;
    cin >> k;
    int cnt = 0;
    int res[100];

    for (int i = 0;i < k;i ++){
        cin >>nums[i];
    }

    for (int i = 0; i< k;i++){
        if(is_perfect_digtal(nums, k, nums[i])){
            cout <<"完美数字"<<endl;
            res[cnt] = nums[i];
            cnt++;
        }
    }

    // from big to little
    for (int i = 0; i < cnt;i ++){
        cout <<res[i];
        if (i == cnt - 1){
            cout <<endl;
        }else{
            cout <<" ";
        }
    }
    cout << "cnt=" << cnt<<endl;
    cout << "load success";
    return 0;
}

int is_perfect_digtal(int *nums, int len,int num){
    int cnt = 0;
    int ret = 0;
    cout <<"正在验证num="<<num<<" ";
    while (num != 1){
        num = num % 2 == 1 ? (3 * num + 1) / 2 : num / 2;
        cout << num << " ";
        if (in_arrary(nums, len, num)){
            cnt++;
        }
    }
    cout <<endl;
    if (cnt >= len -1){
        ret = 1;
    }

    return ret;
}

int in_arrary(int *nums, int len, int num){
    int *tmp = nums;
    int ret = 0;

    for (int i = 0;i < len;i++){
        if (num == *(tmp + i)){
            ret = 1;
            break;
        }
    }
    return ret;
}