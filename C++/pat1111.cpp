/**
* pat1111
* Author: zhiying
* Date: 2023.7.1 23:32
* Description:
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
bool is_symmetry_day(string &str);

int main(){
    int n = 0;
    cin >>n;
    map<string,string> month_map = {{"Jan","01"},{"Feb","02"},{"Mar","03"},{"Apr","04"},{"May","05"},{"Jun","06"},{"Jul","07"},{"Aug","08"},{"Sep","09"},{"Oct","10"},{"Nov","11"},{"Dec","12"}};
    vector<string> time;

    for (int i = 0;i < n;i ++){
        string time_str;
        string month;
        cin >>month;
        string str;
        cin >>str;
        int pos = str.find(',',0);
        string day = str.substr(0,pos);
        if (day.size()!= 2){
            day.insert(0,1,'0');
        }
        string year;
        cin >>year;
        if (year.size() != 4){
            year.insert(0,4- year.size(),'0');
        }

        time_str = year + month_map[month] + day;
        time.push_back(time_str);
        if (i == n-1){
            break;
        }
    }
    for (auto t:time){
        if (is_symmetry_day(t)){
            cout <<"Y "<<t<<endl;
        } else{
            cout <<"N "<<t<<endl;
        }
    }
    return 0;
}

bool is_symmetry_day(string &str){
    bool ret = true;
    for (int i = 0;i < 4;i++){
        if (str[i] != str[str.size()-1 - i]){
            ret = false;
            break;
        }
    }
    return ret;
}