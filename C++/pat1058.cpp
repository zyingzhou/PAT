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

using namespace std;
typedef struct {
    pair<int, int> ques_no;
    int grade;
    int options;
    int right_option;
    set<char> right_answer;
}Question;
bool sort_by_wrong_and_no(Question &q1, Question &q2);
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
            question.right_answer.insert(ch);
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
            set<char> answer;
            int option = 0;

            cin>>ch>>option;
            for (int j = 0;j < option;j++){
                cin >>ch;
                answer.insert(ch);
            }
            cin >>ch;
            if (questions[k].right_answer == answer){
                get_grade += questions[k].grade;
            } else{
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
    for (int i = 0; i < questions.size()-1;i ++){
        idx++;
        cout<<questions[i].ques_no.second<<' ';
        if (questions[i].ques_no.second != questions[i+1].ques_no.second){
            break;
        }

    }
//    cout <<endl;
    for (int i = 0; i < idx;i ++){
        cout <<questions[i].ques_no.first;
        if (i != idx-1){
            cout <<' ';
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