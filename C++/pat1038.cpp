/**
* pat1038
* Author: zhiying
* Date: 2023.6.24 23:20
*
*/
#include <iostream>
#include <map>
#include <vector>

using namespace  std;

int main(){
    int n;
    cin >>n;
    map<int, int>stu_grades;

    int grade = 0;
    for (int i =0;i < n;i ++){
        cin >>grade;
        ++stu_grades[grade];
    }
    int m;
    cin >>m;
    vector<int> search;
    for(int i =0;i < m ; i++){
        cin >>grade;
        search.push_back(grade);
    }

    for(int i =0;i < m ; i++){
        cout << stu_grades[search[i]];
        if (i != m-1){
            cout << ' ';
        }
    }
    cout <<endl;

    return 0;
}