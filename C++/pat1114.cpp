/**
 * pat1114
 * Author：zhiying
 * Date: 23-7-26 20:49
 * Description:
 * 
 */
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
bool is_prime(int n);

int main() {
    string date;
    cin >>date;
    int prime_date = 1;
    for (int pos = 0; pos <date.size();pos++){
        string sub = date.substr(pos, date.size() -pos);
        if (is_prime(stoi(sub))){
            cout <<sub << ' '<< "Yes"<<endl;
        }else{
            prime_date = 0;
            cout <<sub << ' '<< "No"<<endl;
        }
    }
    if (prime_date == 1){
        cout <<"All Prime!"<<endl;
    }
    return 0;
}
bool is_prime(int n){
    bool ret = true;
    if (n == 1){
        ret = false;
    }
    for (int i = 2;i <= sqrt(n);i++){
        if (n % i == 0){
            ret = false;
            break;
        }
    }
    return ret;
}