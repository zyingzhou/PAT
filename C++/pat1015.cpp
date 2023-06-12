/**
* 
* Author: zhiying
* Date: 2022/7/31
* Update: 2023/6/12 21:53
* Copyright (c) 2022 All rights reserved.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct {
    int id;
    int moral_grade;
    int talent_grade;
}Candidate;

void print(vector<Candidate> &cans);
bool cmp(Candidate can1, Candidate can2);

int main(){
    int valid =0;
    int m = 0 ;
    int low = 0;
    int high = 0;
    vector<Candidate > first;
    vector<Candidate > second;
    vector<Candidate > third;
    vector<Candidate > fourth;

    cin >> m >> low >> high;
    for (int i = 0; i < m; i++){
        int id, moral_grade,talent_grade;
        cin >> id >> moral_grade >>talent_grade;

        if (moral_grade >= high && talent_grade >= high){
            Candidate candidate;
            candidate.id = id;
            candidate.moral_grade = moral_grade;
            candidate.talent_grade = talent_grade;
            first.push_back(candidate);
            valid++;
            continue;
        }

        if (moral_grade >= high && talent_grade < high && talent_grade >= low){
            Candidate candidate;
            candidate.id = id;
            candidate.moral_grade = moral_grade;
            candidate.talent_grade = talent_grade;
            second.push_back(candidate);
            valid++;
            continue;
        }
        if (moral_grade < high && moral_grade >=low && talent_grade < high && talent_grade >= low && moral_grade >=talent_grade){
            Candidate candidate;
            candidate.id = id;
            candidate.moral_grade = moral_grade;
            candidate.talent_grade = talent_grade;
            third.push_back(candidate);
            valid++;
            continue;
        }

        if (moral_grade >=low && talent_grade >= low){
            Candidate candidate;
            candidate.id = id;
            candidate.moral_grade = moral_grade;
            candidate.talent_grade = talent_grade;
            fourth.push_back(candidate);
            valid++;
            continue;
        }

    }
    sort(first.begin(), first.end(),cmp);
    sort(second.begin(), second.end(),cmp);
    sort(third.begin(), third.end(),cmp);
    sort(fourth.begin(), fourth.end(),cmp);
    cout << valid<<endl;
    print(first);
    print(second);
    print(third);
    print(fourth);
    return 0;
}
void print(vector<Candidate> &cans){
    for (auto can: cans){
        cout << can.id << ' ' << can.moral_grade << ' ' << can.talent_grade <<endl;
    }
}

bool cmp(Candidate can1, Candidate can2){
    if((can1.moral_grade + can1.talent_grade) != (can2.moral_grade + can2.talent_grade)){
        return (can1.moral_grade + can1.talent_grade) > (can2.moral_grade + can2.talent_grade);
    }
    if (can1.moral_grade != can2.moral_grade){
        return can1.moral_grade > can2.moral_grade;
    }
    return can1.id < can2.id;

}
