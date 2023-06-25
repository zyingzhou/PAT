/**
* pat1037
* Author: zhiying
* Date: 2023.6.25 18:45
*
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int p[3];
    int a[3];
    int res[3];
    char ch;
    cin >>p[0] >>ch >>p[1] >>ch >>p[2];
    cin >>a[0] >>ch >>a[1] >>ch >>a[2];
    int cnt = (a[0] * 29 * 17 +a[1]* 29 + a[2]) - (p[0] * 29 * 17 +p[1]* 29 + p[2]);
    if (cnt <0){
        cout <<'-';
        cnt = abs(cnt);
    }
    res[0] = cnt / (29 * 17);
    res[1] = (cnt - res[0] * (29 * 17)) / 29;
    res[2] = cnt - res[0] * (29 * 17)- res[1] * 29;
    cout <<res[0]<<'.'<<res[1]<<'.'<<res[2]<<endl;
    return 0;
}