/**
* 
* Author: zhiying
* Date: 2022/7/31
* Copyright (c) 2022 All rights reserved.
*/
#include <iostream>

typedef struct {
    int id;
    int moral_grade;
    int talent_grade;
    int sign;
}Stu_info;
typedef struct {
    int length;
    Stu_info *sts[100000];
}Stu_kind;
typedef struct {
    int last;
    Stu_kind *kinds[5];
    int passed;
}Result;

void input(Stu_info* students, int len);
int get_passed(Stu_info* students, int len, int low, int high);
void swap(Stu_info *stu1, Stu_info *stu2);
void output(Stu_info* students, int len);
Result set_sign(Stu_info* students, int len, int lo, int hi);
void sort_by_sign(Stu_info* students, int len, Result result);
void quick_sort(Stu_info* students, int passed);
void scan(Stu_info* students, int len, int hi, int lo, Result *res);

using namespace std;

int main(){
    int m = 0 ;
    int low = 0;
    int high = 0;

    cin >> m >> low >> high;

    Stu_info *students = new Stu_info [m];
    Result result;
    input(students, m);
//    scan(students,m,high, low, &result);
//    Result result = set_sign(students, m,low,high);
//    cout << "passed=" << result.passed<<endl;
//    sort_by_sign(students,m,result);
    scan(students,m,high, low, &result);
    for (int idx = 0; idx < 4; idx++){
        quick_sort(reinterpret_cast<Stu_info *>(result.kinds[idx]->sts), result.kinds[idx]->length);
        output(reinterpret_cast<Stu_info *>(result.kinds[idx]->sts), result.kinds[idx]->length);

    }
//    quick_sort(students, result.passed);
//    output(students,result.passed);
    // 释放指针
    delete [] students;

    return 0;
}

void input(Stu_info* students, int len){


    for (int i = 0;i < len;i ++){
        cin >> students[i].id >> students[i].moral_grade >> students[i].talent_grade;
    }
}

int get_passed(Stu_info* students, int len, int low, int high){
    int passed = 0;

    for (int i = 0 ;i  < len-1;i++){
//        cout<< students[i].id << " "<<students[i].moral_grade << " "<< students->talent_grade<<endl;
        if (students[i].moral_grade >= low && students[i].talent_grade >= low){

            for (int j = i + 1;j < len;j++){
                if (students[j].moral_grade >= low && students[j].talent_grade >= low){

                    if (students[i].moral_grade + students[i].talent_grade > students[j].moral_grade + students[j].talent_grade){

                        swap(students[i],students[j]);
                    }

                    // 总分相同
                    if (students[i].moral_grade + students[i].talent_grade == students[j].moral_grade + students[j].talent_grade){

                        if (students[i].moral_grade < students[j].moral_grade){
                            swap(students[i],students[j]);
                        }

                        if (students[i].moral_grade == students[j].moral_grade){

                            if (students[i].id > students[j].id){
                                swap(students[i],students[j]);
                            }
                        }
                    }
                }
            }

            passed++;
        }
    }
    return passed;
}

void swap(Stu_info *stu1, Stu_info *stu2){
    Stu_info *tmp = new Stu_info;

    // deep copy stu1 -> tmp
    tmp->id  = stu1->id;
    tmp->moral_grade = stu1->moral_grade;
    tmp->talent_grade = stu1->talent_grade;

    // stu2 -> stu1
    stu1->id  = stu2->id;
    stu1->moral_grade = stu2->moral_grade;
    stu1->talent_grade = stu2->talent_grade;

    // tmp -> stu2
    stu2->id  = tmp->id;
    stu2->moral_grade = tmp->moral_grade;
    stu2->talent_grade = tmp->talent_grade;

    // 释放指针
    delete tmp;
}

void output(Stu_info* students, int len){
    cout << len <<endl;
    for (int i = 0;i < len;i ++){
//        cout <<"种类"<<students[i].sign<<": "<< students[i].id << " " << students[i].moral_grade << " " << students[i].talent_grade <<endl;
        cout << students[i].id << " " << students[i].moral_grade << " " << students[i].talent_grade <<endl;
    }
}

Result set_sign(Stu_info* students, int len, int lo, int hi){
    Result res;
    res.last = 0;
    for (int i = 0; i < 5;i++){
        res.kinds[i] = 0;
    }
    res.passed = 0;
    // 第1类 sign = 1;依次类推
    // 不及格 sign = 5;
//    int fail =0;
    for (int i = 0;i < len; i++){
//        第一类
        if(students[i].moral_grade >= hi && students[i].talent_grade >= hi){
            students[i].sign = 1;
            res.kinds[0]++;
            continue;
        }

        if (students[i].moral_grade >= hi && students[i].talent_grade >= lo && students[i].talent_grade < hi){
            students[i].sign = 2;
            res.kinds[1]++;
            continue;
        }

        if (students[i].moral_grade >= students[i].talent_grade && students[i].moral_grade < hi  && students[i].talent_grade >= lo){
            students[i].sign = 3;
            res.kinds[2]++;
            continue;
        }
//        if (students[i].moral_grade >= lo && students[i].moral_grade < hi  && students[i].talent_grade >= lo && students[i].talent_grade < hi ){
//            students[i].sign = 4;
//            continue;
//        }
        if (students[i].moral_grade < lo || students[i].talent_grade < lo){
            students[i].sign = 5;
            res.kinds[4]++;
//            fail++;
//            cout << "不及格考生："<<students[i].id << " " << students[i].moral_grade << " " << students[i].talent_grade <<endl;
            continue;
        }
        students[i].sign = 4;
        res.kinds[3]++;

    }
    res.passed = len - res.kinds[4]->length;

    for (int j = 4;j >=0;j--){
        if (res.kinds[j] != 0){
//            res.last = res.kinds[j];
            break;
        }
    }
    return res;
}

void sort_by_sign(Stu_info* students, int len, Result result){

    for (int i = 0; i < len -result.last;i ++){

        for (int j = i + 1;j <  len;j ++){

            if (students[i].sign > students[j].sign){
                swap(students[i],students[j]);
            }
        }
    }
}

void quick_sort(Stu_info* students, int passed){
    Stu_info *head= students;
//    Stu_info *tmp = head;

    for (int i = 0 ; i < passed-1;i++){
        // 最后一个必然就位
        for (int j = i+1; (head+i)->sign == (head + j)->sign; j++){

            if ((head + i)->moral_grade + (head + i)->talent_grade < (head + j)->moral_grade + (head + j)->talent_grade){
                swap(head + i, head +j);
                continue;
            }

            if ((head + i)->moral_grade + (head + i)->talent_grade == (head + j)->moral_grade + (head + j)->talent_grade){

                if ((head + i)->moral_grade < (head + j)->moral_grade){
                    swap(head + i, head +j);
                    continue;
                }

                if ((head + i)->moral_grade == (head + j)->moral_grade){

                    if (students[i].id > students[j].id){
                        swap(students[i],students[j]);
                        continue;
                    }
                }
            }
        }

    }

}

void scan(Stu_info* students, int len, int hi, int lo, Result *res){
    // 初始化
    for (auto & kind : res->kinds){
        kind->length = 0;

    }


    for (int i = 0;i < len;i ++){

//        第一类
        if(students[i].moral_grade >= hi && students[i].talent_grade >= hi){
            students[i].sign = 1;
            int len = res->kinds[0]->length;
            res->kinds[0]->sts[len] = &students[i];
            res->kinds[0]->length++;
            continue;
        }

        if (students[i].moral_grade >= hi && students[i].talent_grade >= lo && students[i].talent_grade < hi){
            students[i].sign = 2;
            int len = res->kinds[1]->length;
            res->kinds[1]->sts[len] = &students[i];
            res->kinds[1]->length++;
            continue;
        }

        if (students[i].moral_grade >= students[i].talent_grade && students[i].moral_grade < hi  && students[i].talent_grade >= lo){
            students[i].sign = 3;
            int len = res->kinds[2]->length;
            res->kinds[2]->sts[len] = &students[i];
            res->kinds[2]->length++;
            continue;
        }
//        if (students[i].moral_grade >= lo && students[i].moral_grade < hi  && students[i].talent_grade >= lo && students[i].talent_grade < hi ){
//            students[i].sign = 4;
//            continue;
//        }
        if (students[i].moral_grade < lo || students[i].talent_grade < lo){
            students[i].sign = 5;
            int len = res->kinds[4]->length;
            res->kinds[4]->sts[len] = &students[i];
            res->kinds[4]->length++;
//            fail++;
//            cout << "不及格考生："<<students[i].id << " " << students[i].moral_grade << " " << students[i].talent_grade <<endl;
            continue;
        }
        students[i].sign = 4;
        res->kinds[3]->length++;

    }
    res->passed = len - res->kinds[4]->length;
    cout << res->passed;

}