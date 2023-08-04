/**
 * pat1044
 * Author：zhiying
 * Date: 23-8-3 22:46
 * Description:
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

string man_to_spark(int num);
int spark_to_man(string str);

int main() {
    int n;

    cin >>n;
    vector<string>  vec;
    char ch;
    cin >>noskipws>>ch;
    for (int i = 0;i < n;i++){
        string str;
        cin >>noskipws>>ch;
        while ((int)ch != 10){
            str.push_back(ch);
            cin >>noskipws>>ch;
        }
        vec.push_back(str);
    }
    for (auto s: vec){
        if (isdigit(s[0])){
            string str = man_to_spark(stoi(s));
            cout <<str<<endl;
        }else{
            int num = spark_to_man(s);
            cout <<num<<endl;
        }

    }
    return 0;
}
string man_to_spark(int num){
    string lo[] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string hi[] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    int carry = num / 13;
    int remind = num % 13;
    if (carry != 0){
        if (remind ==0){
            return hi[carry-1];
        }else{
            return hi[carry-1] +' ' + lo[remind];
        }
    }else{
        return lo[remind];
    };

}
int spark_to_man(string str){
    map<string, int> lo = {{"tret",0},{"jan",1},{"feb",2},{"mar",3},{"apr",4},{"may",5},{"jun",6},{"jly",7},{"aug",8},{"sep",9},{"oct",10},{"nov",11},{"dec",12}};
    map<string, int> hi = {{"tam",1}, {"hel",2}, {"maa",3}, {"huh",4}, {"tou",5}, {"kes",6}, {"hei",7}, {"elo",8}, {"syy",9}, {"lok",10}, {"mer",11}, {"jou",12}};
    int pos = str.find(' ');
    if (pos != -1){
        return hi[str.substr(0,pos)]*13 + lo[str.substr(pos+1,str.size()-pos)];
    }else{
        if (lo.find(str) != lo.end()){
            return lo[str];
        }else{
            return hi[str]*13;
        }
    }
}