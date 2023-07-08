/**
* pat1100
* Author: zhiying
* Date: 2023.7.8 16:00
*
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
int main(){
    int n =0;
    cin >>n;
    map<string,int> mates;
    for(int i =0;i<n;i++){
        string str;
        cin >>str;
        ++mates[str];
    }
    int m =0;
    int mate_cnt=0;
    cin >>m;
    string older_mate="xxxxxx99999999xxxx";
    string older_cum="xxxxxx99999999xxxx";
    for (int i = 0;i<m;i++){
        string str;
        cin >>str;
        if (mates[str] ==1){
            mate_cnt++;
            if (str.substr(6,8) < older_mate.substr(6,8)){
                older_mate = str;
            }
        } else{
            if (str.substr(6,8) < older_cum.substr(6,8)){
                older_cum = str;
            }
        }

    }
    cout<<mate_cnt<<endl;
    if(mate_cnt != 0){
        cout <<older_mate<<endl;
    }else{
        cout <<older_cum<<endl;
    }
    return 0;
}
