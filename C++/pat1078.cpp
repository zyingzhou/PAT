/**
* pat1078
* Author: zhiying
* Date: 2023.7.18 19:14
*
*/
#include <iostream>
#include <vector>
#include <utility>
#include <string>


using namespace std;

int main (){
    char ch1;
    cin >>ch1;
    char ch;
    cin >>noskipws>>ch; // the line feed behind the char 'C'
    if (ch1 == 'C'){
        vector<pair<char,int>> strings;
        cin >>noskipws>>ch;
        pair<char,int>pairs;
        pairs.first = ch;
//        pairs.second = 0;
        pairs.second++;

        while(int(ch) != 10){
            cin >>noskipws>>ch;
            if (pairs.first == ch){
                pairs.second++;
            } else{
                strings.push_back(pairs);
                pairs.first =ch;
                pairs.second =1;
            }
        }
        for (auto item :strings){
            if (item.second ==1){
                cout <<item.first;
            }else{
                cout <<item.second<<item.first;
            }

        }
        cout <<endl;
    }else{
        vector<pair<char,int>> strings;
        pair<char,int>pairs;
        string strs;
        cin >>noskipws>>ch;
        while(int(ch) != 10){
            strs.push_back(ch);
            cin >>noskipws>>ch;
        }
        int pos = 0;
        for (int j = 0;j < strs.size();j++){
            if(isalpha(strs[j]) || isspace(strs[j])){
                pairs.first = strs[j];
                if (pos ==j){
                    pairs.second = 1;
                }else{
                    string cnt=strs.substr(pos, j-pos);
                    pairs.second = stoi(cnt);
                }
                pos = j+1;
                strings.push_back(pairs);
            }
        }
        for(auto item:strings){
            for (int k = 0;k <item.second;k++){
                cout<<item.first;
            }
        }
        cout <<endl;

    }
    return 0;
}
