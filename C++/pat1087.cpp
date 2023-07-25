/**
 * pat1087
 * Author：zhiying
 * Date: 23-7-25 20:16
 * Description:
 * 
 */
#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    cin >>n;
    set<int> result;
    for (int i =1;i<= n;i++){
        int val = i / 2 + i / 3 + i / 5;
        result.insert(val);
    }
    cout <<result.size()<<endl;
    return 0;
}
