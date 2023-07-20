/**
* pat1063
* Author: zhiying
* Date: 2023.7.20 22:52
*
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int n;
    float max=0.0;
    cin >>n;
    for (int i = 0;i < n;i++){
        int a,b;
        cin >>a>>b;
        float modulus = sqrt(a*a + b*b);
        if (modulus >max){
            max= modulus;
        }
    }
    cout.setf(ios::fixed);
    cout <<setprecision(2)<<max<<endl;
    return 0;
}