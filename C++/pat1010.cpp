/**
* 
* Author: zhiying
* Date: 2022/6/12
* Update: 2022/7/17
* Copyright (c) 2022 All rights reserved.
*/
#include <iostream>
using namespace std;

void input(int* nums, int *len);
void diff(int *nums, int len);
void output(int *nums, int len);

int main(){
//    using namespace std;
    int nums[2001] = {0};
    int len = 0;
    input(nums,&len);
    diff(nums, len);
    output(nums, len);

    return 0;
}

void input(int *nums, int *len){
//    using namespace std;

//    int cnt = 0;
    int *tmp = nums;
    int i = 0;

    while (cin>>tmp[i]){
        i++;
        if (cin.get() == '\n'){  // 输入未知个整数，以回车结束
            break;
        }
    }

    *len = i;
}


// 求导数
void diff(int *nums, int len){
    int *tmp = nums;

    for (int i = 0; i< len;i = i+2){
        tmp[i] = tmp[i] * tmp[i+1];

        if (tmp[i+1] == 0){
            continue;
        }
        tmp[i+1]--;
    }

}

void output(int *nums, int len){
    int *tmp = nums;

    for (int i = 0; i< len;i = i+2){

        if (tmp[i] != 0){
            if (i == 0){
                cout << tmp[i] << ' '<<tmp[i+1];
            }else{
                cout << ' '<< tmp[i] << ' '<<tmp[i+1];
            }

        }

        if (tmp[i] == 0 && len == 2){
            cout << 0 <<' '<< 0;
        }
        if (i+2 == len){
            cout << endl;
        }
    }
}