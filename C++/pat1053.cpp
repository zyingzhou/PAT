/**
 * pat1053
 * Author：zhiying
 * Date: 23-8-4 22:21
 * Description:
 * 
 */
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    float e;
    int d;
    cin >>n>>e>>d;
    int may_empty = 0;
    int empty = 0;
    for (int i =0;i < n;i++){
        int k;
        int unreached = 0;
        cin >>k;
        for (int j = 0;j <k;j++){
            float elec;
            cin >>elec;
            if (elec <e){
                unreached++;
            }
        }
        if (unreached > k /2.0){
            if (k >d){
                empty++;
            }else{
                may_empty++;
            }
        }

    }
    cout.setf(ios::fixed);
    cout <<setprecision(1)<<((float )may_empty / n)*100<<"% "<<setprecision(1)<<((float )empty /n)*100<<'%'<<endl;
    return 0;
}
