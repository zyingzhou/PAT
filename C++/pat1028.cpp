/*
** pat1028
* Author: zhiying
* Date: 2023.6.10
*
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

typedef struct {
//    int year;
//    int month;
//    int day;
    string birth_flag;
}Birth;

typedef struct {
    string name;
    Birth birth;
}Person;

bool cmp(Person &p1, Person &p2);
int main(){
    int n = 0;
    cin >> n;
    vector<Person > person;
    string today="20140906";
    string old="18140906";
    int valid = 0;
    for (int i = 0;i < n; i ++){
        string name, br;
        Person p;
        cin>>name>>br;
        auto pos = br.begin();
        br.erase(pos + 4);
        br.erase(pos + 6);
        if (br <= today && br >=old){
            p.name = name;
            p.birth.birth_flag = br;
            person.push_back(p);
            valid++;
        }
    }
    sort(person.begin(), person.end(),cmp);
    cout <<valid;
    if (valid != 0){
        cout<<' '<<person[0].name<<' '<<person[valid-1].name<<endl;
    }else{
        cout<<endl;
    }
    return 0;
}

bool cmp(Person &p1, Person &p2){
    return p1.birth.birth_flag < p2.birth.birth_flag;
}