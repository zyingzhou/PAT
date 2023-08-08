/**
 * pat1081
 * Author：zhiying
 * Date: 23-8-8 22:20
 * Description:
 * 
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void chk_password(int &len, bool &has_digtal,bool &has_alpha,bool &has_dot,bool &has_illegal_char);
int main() {
    const string str[] = {"Your password is tai duan le.",
    "Your password needs shu zi.",
    "Your password needs zi mu.",
    "Your password is wan mei.",
    "Your password is tai luan le."};
    int n;
    cin >>n;
    char ch;
    // ignore the line feed;
    cin >>noskipws>>ch;
    vector<string> vec;
    for (int i = 0;i< n;i++){
        bool has_digtal = false;
        bool has_alpha = false;
        bool has_dot = false;
        bool has_illegal_char = false;
        int len = 0;
        chk_password(len,has_digtal,has_alpha,has_dot,has_illegal_char);
        if (len - 1 <6){
            vec.push_back(str[0]);
        }else{
            if (has_illegal_char){
                vec.push_back(str[4]);
                continue;
            }
            if (has_alpha && !has_digtal){
                vec.push_back(str[1]);
                continue;
            }
            if (!has_alpha && has_digtal){
                vec.push_back(str[2]);
                continue;
            }
            vec.push_back(str[3]);

        }
    }
    for (auto v : vec){
        cout <<v<<endl;
    }

    return 0;
}

void chk_password(int &len, bool &has_digtal,bool &has_alpha,bool &has_dot,bool &has_illegal_char){
    char ch;
    cin >>noskipws>>ch;
    len++;
    while ((int)ch != 10){
        if (isalpha(ch) || isdigit(ch) || ch == '.'){
            if (isdigit(ch)){
                has_digtal = true;
            }
            if (isalpha(ch)){
                has_alpha = true;
            }
            if (ch == '.'){
                has_dot = true;
            }
        }else{
            has_illegal_char = true;
        }
        cin >>noskipws>>ch;
        len++;
    }
}