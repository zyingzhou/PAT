/**
* pat1057
* Author: zhiying
* Date: 2023.7.1 22:02
* Description:
*/
#include <iostream>
#include <string>

using namespace std;

int main(){
    char ch;
    cin >>noskipws>>ch;
    int cnt_alpha=0;
    int alpha_sum = 0;

    while ((int)ch != 10){
        if (isalpha(ch)){
            cnt_alpha++;
            if (isupper(ch)){
                ch = tolower(ch);
            }
            alpha_sum += ((ch-'a') + 1);
        }
        cin >>noskipws>>ch;
    }

    int cnt_zero = 0;
    int cnt_one = 0;

    if (cnt_alpha == 0){
        cout << cnt_zero << ' '<<cnt_one<<endl;
    }else{
        while (alpha_sum > 1){

            alpha_sum % 2 == 1 ? cnt_one++: cnt_zero++;
            alpha_sum /= 2;
        }
        alpha_sum == 1 ? cnt_one++: cnt_zero++;
        cout << cnt_zero << ' '<<cnt_one<<endl;
    }

    return 0;
}