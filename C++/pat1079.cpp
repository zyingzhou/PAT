/**
 * pat1079
 * Author：zhiying
 * Date: 23-7-22 20:27
 * Description:
 * 
 */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool is_pal_num(string num);
string add_in_str(string &a, string &b);
int atoi(char ch);
char itoa(int a);
int main() {
    string str;
    cin >>str;

    int limit = 10;
    while (true){
        if (is_pal_num(str)){
            cout <<str <<" is a palindromic number."<<endl;
            break;
        }else{
            string b(str.begin(),str.end());
            reverse(b.begin(),b.end());
            string c = add_in_str(str,b);
//            int c = stoi(str) + stoi(b);
//            string c_str = to_string(c);
            cout <<str<<" + "<<b<<" = "<<c<<endl;
            limit--;
            if (limit == 0){
                cout <<"Not found in 10 iterations."<<endl;
                break;
            }
            str = c;
        }
    }

    return 0;
}
bool is_pal_num(string num){
    bool ret = true;
    int k = num.size()-1;
    for(int i = 0;i < num.size() / 2;i++){
        if (num[k-i] != num[i]){
            ret = false;
            break;
        }
    }

    return ret;
}
string add_in_str(string &a, string &b){
    string sum_str;
    int flag = 0;
    for (int i = a.size() -1;i>=0;i--){
        int c = atoi(a[i]) + atoi(b[i]) + flag;
        flag = c / 10;
        char ch = itoa(c % 10);
        sum_str.push_back(ch);
        if (i == 0 && flag != 0){
            sum_str.push_back(itoa(flag));
        }
    }
    reverse(sum_str.begin(),sum_str.end());
    return sum_str;
}

int atoi(char ch){
    char zero = '0';
    return (int)ch - (int)zero;
}
char itoa(int a){
    char zero = '0';
    return (char)((int)zero + a);
}