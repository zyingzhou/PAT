/**
* pat1062
* Author: zhiying
* Date: 2023.7.21 12:07
*
*/
#include <iostream>
#include <vector>

using namespace std;
bool is_simple_fraction(int n, int m);

int main(){
    int n1,m1,n2,m2,k;
    char ch;
    cin >>n1>>ch>>m1;
    cin >>n2>>ch>>m2;
    cin >>k;
    float lo = ((float)n1/m1) < ((float)n2/m2)? ((float)n1/m1): ((float)n2/m2);
    float hi = ((float)n1/m1) > ((float)n2/m2)? ((float)n1/m1): ((float)n2/m2);
    vector<int> molecule;
    // 假分数
    for (int i = 1;;i++){
        if (((i/(float)k) > lo) && ((i/(float)k) < hi)){
            // 最简分数
//            if (i == 1){
//                molecule.push_back(i);
//                continue;
//            }
            if (is_simple_fraction(i,k)){
                molecule.push_back(i);
            }
        }
        if ((i/(float)k) >= hi){
            break;
        }

    }
    for (int i = 0;i < molecule.size();i++){
        cout<<molecule[i]<<'/'<<k;
        if (i != molecule.size() -1){
            cout <<' ';
        }else{
            cout <<endl;
        }
    }
    return 0;
}

bool is_simple_fraction(int n, int m){
    bool ret = true;
    int low = n <=m ? n :m;
    for (int i = 2;i <= low;i++){
        if (n % i == 0 && m % i == 0){
            ret = false;
            break;
        }
    }
    return ret;
}