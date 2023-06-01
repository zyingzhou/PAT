/*
** pat1032
* Author: zhiying
* Date: 2023.5.30
*
*/

#include <iostream>
#include <vector>

using namespace  std;

typedef struct {
    int no;
    int grade;
}Entity;


Entity find_max(vector<Entity> schools);

int main(){
    int n = 0;
    cin >> n;

    Entity *sts[n];
    for (int i = 0;i < n; i++){
        sts[i] = new Entity ;
        cin >> sts[i]->no >> sts[i]->grade;
    }
    vector<Entity> schools;
    for (int i = 0 ; i < n ;i ++){
        if (schools.empty()){
            schools.push_back(*sts[i]);
        }else{
            int cnt = 0;
            for (auto &sch : schools){
                cnt++;
//                cout << "sch.no=" <<sch.no <<endl;
                if (sch.no == sts[i]->no){
//                    cout << "相等:"<<sch.no << " "<< sch.grade<< " "<<sts[i]->no << " "<< sts[i]->grade<<endl;

                    sch.grade += sts[i]->grade;
                    break;
                }
            }
//            cout << "-------"<<endl;
            if (cnt == schools.size()){
                schools.push_back(*sts[i]);
            }

        }
        delete sts[i];
    }
    Entity max;
//    cout << schools.size() <<endl;
    max = find_max(schools);
    cout << max.no <<" " <<max.grade<<endl;
    return 0;
}

Entity find_max(vector<Entity> schools){
    Entity max;
    max = schools[0];
    for (auto &sch: schools){
        if (max.grade < sch.grade){
            max = sch;
        }
    }
    return max;
}