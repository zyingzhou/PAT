/**
* pat1094
* Author: zhiying
* Date: 2023.7.8 16:33
* Description:
*/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
bool is_prime(long number);
int main(){
    // not found
    const string notfound = "404";
    int l,k;
    cin >>l>>k;
    string nums;
    cin >>nums;
    string found;
    int sign = 0;
    for (int pos = 0;pos < l-k+1;pos++){
        long num = stol(nums.substr(pos,k));
        if(is_prime(num)){
            found = nums.substr(pos,k);
            sign = 1;
            break;
        }
    }
    if (!sign){
        cout<<notfound<<endl;
    }else{
        cout <<found<<endl;
    }
    return 0;
}

bool is_prime(long number){
    bool ret = true;
    if (number > 1){
        int i= 2;
        while (i <= sqrt(number)){
            if (number % i == 0){
                ret = false;
                break;
            }
            i++;
        }
    }else{
        ret = false;
    }
    return ret;
}