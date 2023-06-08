/*
** pat1020
* Author: zhiying
* Date: 2023.6.6
*
* Description: 先把价格高的全部卖出，如果不够，在卖价格稍微低些的，以此类推，直至全部卖出
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;

typedef struct {
    float inventory;
    float price;
    float per_value;
}MoonCake;
bool cmp(MoonCake &cake1, MoonCake &cake2);

int main(){
    int N = 0;
//    需求量
    int D = 0;
    vector<MoonCake > cake(1000);
    float max=0.0;
    cin >> N>> D;

    for (int i = 0;i < N;i++){
        cin >> cake[i].inventory;
    }

    for (int i = 0;i < N;i++){
        cin >> cake[i].price;
    }

    for (int i = 0;i < N; i++){
        cake[i].per_value = cake[i].price / cake[i].inventory;
    }
    sort(cake.begin(), cake.end(),cmp);
    int i = 0;
    while(i < cake.size()){
        if (D <=cake[i].inventory){
            max += cake[i].per_value * D;
            break;
        }else{
            max += cake[i].price;
            D -= cake[i].inventory;
        }
        i++;
    }
    cout.setf(ios::fixed);
    cout <<setprecision(2)<<max<<endl;
    return 0;
}

bool cmp(MoonCake &cake1, MoonCake &cake2){
    return cake1.per_value >cake2.per_value;
}