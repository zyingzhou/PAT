/**
* pat1058
* Author: zhiying
* Date: 2023.7.1 23:09
* Description:
*/
#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef struct {
    pair<int, int> ques_no;
    int grade;
    int options;
    int right_option;
    string right_answer;
}Question;
bool sort_by_wrong_and_no(Question &q1, Question &q2);
bool chk_answer(set<char> &right_answer,set<char> &answer);
int main(){
    int n = 0;
    int m = 0;
    cin >>n>>m;
    vector<Question> questions;

    int full_mark = 0;
    for (int i = 1; i <= m;i++){
        Question question;
        question.ques_no.first = i;
        question.ques_no.second = 0;
        cin >>question.grade>>question.options>>question.right_option;
        for (int j = 0;j < question.right_option; j++){
            char ch;
            cin>>ch;
            question.right_answer.push_back(ch);
        }
        full_mark += question.grade;
        questions.push_back(question);

    }
    int grade[n];
    int all_right = 1;
    for (int i = 0;i <n; i ++){
        int get_grade =0;
        char ch;
        for (int k = 0; k < m; k++){
            string answer;
            int option = 0;

            cin>>ch>>option;
            for (int j = 0;j < option;j++){
                cin >>ch;
                answer.push_back(ch);
            }
            cin >>ch;
            if (strcmp()){
                get_grade += questions[k].grade;
            } else{
                if (chk_answer(questions[k].right_answer,answer)){
                    continue;
                }
                questions[k].ques_no.second += 1;
            }
            if(ch == ')' &&  k== m-1){
                break;
            }
        }
        grade[i] = get_grade;
        if (get_grade != full_mark){
            all_right =0;
        }
//        cout <<get_grade<<endl;
    }

    for (int i = 0;i < n;i++){
        cout <<grade[i]<<endl;
    }
    if (all_right){
        cout <<"Too simple"<<endl;
        return 0;
    }
    sort(questions.begin(),questions.end(), sort_by_wrong_and_no);
    int idx = 0;
    int end =0;
    for (int i = 0; i < questions.size();i ++){
//        idx++;
//        cout<<questions[i].ques_no.second<<' ';
        if (questions[end].ques_no.second != questions[i].ques_no.second){
            end = i;
            break;
        }

    }
    if (end != 0){
        for (int i = 0; i < end;i ++){
            cout<<questions[i].ques_no.second<<' ';
        }
        for (int i = 0; i < end;i ++){
            cout <<questions[i].ques_no.first;
            if (i != end-1){
                cout <<' ';
            }
        }
    }else{
        for (int i = 0; i < questions.size();i ++){
            cout<<questions[i].ques_no.second<<' ';
        }
        for (int i = 0; i < questions.size();i ++){
            cout <<questions[i].ques_no.first;
            if (i != end-1){
                cout <<' ';
            }
        }
    }

    cout <<endl;
    return 0;
}

bool sort_by_wrong_and_no(Question &q1, Question &q2){

    if(q1.ques_no.second == q2.ques_no.second){
        return q1.ques_no.first < q2.ques_no.first;
    }
    return q1.ques_no.second > q2.ques_no.second;
}

bool chk_answer(set<char> &right_answer,set<char> &answer){
    bool ret = false;
    int checked =0;
    for (auto v : right_answer){
        if (answer.find(v) != answer.end()){
            checked++;
        }
    }
    if (checked == right_answer.size()){
        ret = true;
    }
    return ret;
}