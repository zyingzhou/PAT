/**
* pat1091
* Author: zhiying
* Date: 2023.7.8 21:53
* Description:
*/
#include <iostream>

using namespace std;
bool is_n_number(int k,int &n, int& data);
bool cmp_tail(int num1,int num2);
int main(){
    int m;
    cin >>m;
    int n = 0;
    int data = 0;
    for (int i = 0;i< m;i++){
        int num;
        cin >>num;
        if(is_n_number(num,n,data)){
            cout <<n<<' '<<data<<endl;
        }else{
            cout <<"No"<<endl;
        }

    }
    return 0;
}

bool is_n_number(int k,int &n, int& data){
    int ret = false;
    n = 1;
    for(;n< 10;n++){
        data = n*k*k;
        if (cmp_tail(data,k)){
            ret = true;
            break;
        }

    }

    return ret;
}
bool cmp_tail(int num1,int num2){
    bool ret = false;
    string num1_str = to_string(num1);
    string num2_str = to_string(num2);
    if (num1_str.size() >=num2_str.size()){
        if (num1_str.substr(num1_str.size()-num2_str.size(),num2_str.size())== num2_str){
            ret = true;
        }
    } else{
        if (num2_str.substr(num2_str.size()-num1_str.size(),num1_str.size())== num1_str){
            ret = true;
        }
    }

    return ret;
}