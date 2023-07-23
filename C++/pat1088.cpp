/**
 * pat1088
 * Author：zhiying
 * Date: 23-7-23 23:31
 * Description:
 * 
 */
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

void cmp_print(int base, int other);
void cmp_print(int base, float other);
int main() {
    int m,x,y;
    cin >>m>>x>>y;
    int a= 99;
    int b;
    float c;
    while (a >=10){
        string str = to_string(a);
        reverse(str.begin(),str.end());
        b = stoi(str);
        c = b / (float )y;
        if (x * c == abs(a-b)){
            break;
        }
        a--;
    }
    if (a ==9){
        cout <<"No Solution"<<endl;
    }else{
        cout <<a<<' ';
        cmp_print(m,a);
        cout <<' ';
        cmp_print(m,b);
        cout <<' ';
        cmp_print(m,c);
        cout <<endl;
    }
    return 0;
}
void cmp_print(int base, int other){
    if (other > base){
        cout <<"Cong";
    } else if (other == base){
        cout <<"Ping";
    }else{
        cout <<"Gai";
    }
}

void cmp_print(int base, float other){
    if (other > (float)base){
        cout <<"Cong";
    } else if (other == (float)base){
        cout <<"Ping";
    }else{
        cout <<"Gai";
    }
}