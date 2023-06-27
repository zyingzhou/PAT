/**
* pat1051
* Author: zhiying
* Date: 2023.6.27 20:59
*
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct {
    float r;
    float p;
}Plural;

int main(){
    Plural p1;
    Plural p2;
    cin >>p1.r >>p1.p >>p2.r >>p2.p;
    float real = p1.r * p2.r*(cos(p1.p)*cos(p2.p)-sin(p1.p)*sin(p2.p));
    float imag = p1.r * p2.r*(sin(p1.p)*cos(p2.p) + sin(p2.p)* cos(p1.p));
    cout.setf(ios::fixed);
    if (real >= (-0.005) && real <= 0){
        real =0.00;
    }

    if (imag >= (-0.005) && imag <=0){
        imag =0.00;
    }
    cout <<setprecision(2)<<real;

    if (imag>= 0){
        cout<<'+';
    }
    cout <<setprecision(2)<<imag;
    cout<<'i';
    cout <<endl;
    return 0;
}