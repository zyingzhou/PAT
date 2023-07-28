/**
 * pat1102
 * Author：zhiying
 * Date: 23-7-28 14:37
 * Description:
 * 
 */
#include <iostream>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >>n;
    pair<string, int> hot_sale;
    // 测试点1: 销量为0
    hot_sale.second = -1;
    pair<string, int> hot_money;
    hot_money.second = -1;
    for (int i =0;i < n;i++){
        string id;
        int price,cnt;
        cin >>id>>price>>cnt;
        if (hot_sale.second < cnt){
            hot_sale.first = id;
            hot_sale.second = cnt;
        }

        if (hot_money.second < price *cnt){
            hot_money.first = id;
            hot_money.second = price * cnt;
        }
    }
    cout <<hot_sale.first <<' '<<hot_sale.second<<endl;
    cout <<hot_money.first <<' '<<hot_money.second<<endl;

    return 0;
}
