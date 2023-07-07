/**
* pat1106
* Author: zhiying
* Date: 2023.7.7 22:30
* Description:
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n = 0;
    vector<int> nums = {2,0,1,9};
    cin >>n;
    int four = 12;

    for (int i = 0;i <(n -4);i ++){
        int next = four % 10;
        nums.push_back(next);
        four = four - nums[i];
        four = four + next;

    }

    for (int i = 0; i < n;i++){
        cout <<nums[i];
    }
    cout <<endl;
    return 0;
}
