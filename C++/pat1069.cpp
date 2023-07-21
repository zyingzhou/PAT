/**
* pat1069
* Author: zhiying
* Date: 2023.7.21 17:16
*
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(){
    int m,n,s;
    cin >>m>>n>>s;
    int next = s;
    set<string> reward;
    for (int i = 1;i <=m;i++){
        string nickname;
        cin >>nickname;
        if (i== s){
            reward.insert(nickname);
            next = s + n;
            cout <<nickname<<endl;
        }else{
            if (i == next){
                if (reward.find(nickname) == reward.end()){
                    reward.insert(nickname);
                    next += n;
                    cout <<nickname<<endl;
                }else{
                    next++;
                }
            }
        }
    }
    if (reward.empty()){
        cout<<"Keep going..."<<endl;
    }
    return 0;
}