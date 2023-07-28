/**
 * pat1108
 * Author：zhiying
 * Date: 23-7-28 14:13
 * Description:
 * 
 */
#include <iostream>
#include <string>


using namespace std;

int main() {
    char ch;
    int arr[6] = {0};
    cin >>noskipws>>ch;
    int len = 0;
    while((int)ch != 10){
        if (ch == 'S'){
            arr[0] += 1;
            len++;
        }

        if (ch == 't'){
            arr[1] += 1;
            len++;
        }
        if (ch == 'r'){
            arr[2] += 1;
            len++;
        }
        if (ch == 'i'){
            arr[3] += 1;
            len++;
        }
        if (ch == 'n'){
            arr[4] += 1;
            len++;
        }
        if (ch == 'g'){
            arr[5] += 1;
            len++;
        }
        cin >>noskipws>>ch;
    }

    for (int i = 0;i < len;i++){
        char ch_arr[] ={'S', 't','r','i','n','g'};
        for (int j =0;j <6;j++){
            if (arr[j]> 0){
                cout <<ch_arr[j];
                arr[j]--;
            }
        }
    }
    cout <<endl;
    return 0;
}
