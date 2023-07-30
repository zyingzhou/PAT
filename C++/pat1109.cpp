/**
 * pat1109
 * Author：zhiying
 * Date: 23-7-28 15:56
 * Description:
 * 
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    map<char,vector<string>> chars;
    vector<string> words;
    int A = 65;
    for (int i = 0;i < 26;i++){
        char ch =(char) (A + i);
        for (int j = 0;j < 7;j++){
            string str;
            cin >>str;
            chars[ch].push_back(str);
        }
    }
    char ch;
    string word;
    cin >>noskipws>>ch;
    cin >>noskipws>>ch;
    while((int)ch != 10){
        if (isupper(ch)){
            word.push_back(ch);
        }else{
            if(!word.empty()){
                words.push_back(word);
                word="";
            }
        }
        cin >>noskipws>>ch;
    }
    words = {"WORLD","YOU","SEE"};
    for (int i = 0;i < words.size();i++){
        for (int j = 0;j <7;j++){
            for (int k = 0;k < words[i].size();k++){
                cout <<chars[words[i][k]][j];
                if (k != words[i].size() - 1){
                    cout <<' ';
                }else{
                    cout <<endl;
                }
            }
        }
        if (i != words.size()-1){
            cout <<endl;
        }
    }
    return 0;
}
