/**
 * pat1024 v2
 * Author：zhiying
 * Date: 23-8-2 20:59
 * Description:
 * 
 */
#include <iostream>
#include <string>

using namespace std;

typedef struct {
    char flag;
    string integer;
    string decimal;
    char direction;
    int shift_cnt;
}SciNum;
void print_sci_num(SciNum &num);
void print_ordinary_num(SciNum &num);

int main() {
    SciNum a;
    cin >>a.flag;
    char ch;
    cin >>ch;
    a.integer.push_back(ch);
    // ignore the dot
    cin >>ch;
    cin >>ch;
    while (ch != 'E'){
        a.decimal.push_back(ch);
        cin >>ch;
    }
    cin >> a.direction;
    string str;
    cin >> str;
    a.shift_cnt = stoi(str);
//    print_sci_num(a);
    if(a.shift_cnt != 0){
        // shift left
        if (a.direction == '-'){
            a.integer.insert(a.integer.begin(),'.');
            a.integer.insert(a.integer.begin(),'0');
            if (a.shift_cnt >1){
                a.integer.insert(a.integer.begin()+2,a.shift_cnt -1,'0');
            }
        }else{
            if (a.shift_cnt <= a.decimal.size()){
                if (a.shift_cnt != a.decimal.size()){
                    a.decimal.insert(a.decimal.begin()+ a.shift_cnt,'.');
                }

            }else{
                a.decimal.insert(a.decimal.end(),a.shift_cnt-a.decimal.size(),'0');
            }

        }
    }
    print_ordinary_num(a);
    return 0;
}
void print_sci_num(SciNum &num){
    if (num.flag != '+'){
        cout <<num.flag;
    }
    cout <<num.integer<<'.'<<num.decimal<<'E'<<num.direction<<to_string(num.shift_cnt)<<endl;
}

void print_ordinary_num(SciNum &num){
    if (num.flag != '+'){
        cout <<num.flag;
    }
    if (num.shift_cnt == 0){
        cout <<num.integer<<'.'<<num.decimal<<endl;
    }else{
        cout <<num.integer<<num.decimal<<endl;
    }
}