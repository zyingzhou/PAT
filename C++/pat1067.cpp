/**
 * pat1067
 * Author：zhiying
 * Date: 23-7-21 22:07
 * Description:
 * 
 */
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    pair<string,int> password;
    cin>>password.first>>password.second;
    string str;
    cin >>str;
    vector<string> words;
    while (str != "#"){
        words.push_back(str);
        cin >>str;
    }
    for (const auto& word: words){
        if (word == password.first && password.second >0){
            cout <<"Welcome in"<<endl;
            break;
        }else{
            cout<<"Wrong password: "<<word<<endl;
            password.second--;
            if (password.second == 0){
                cout <<"Account locked"<<endl;
                break;
            }
        }
    }
    return 0;
}
