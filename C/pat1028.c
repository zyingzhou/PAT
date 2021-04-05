/**
* pat1028
* Author: zhiying
* Date: 2021/3/10
* Copyright (c) 2021 All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
}Birth;

typedef struct {
    char name[6];
    Birth birth;
}Person;

void get_birth(char *str, Birth *bir);
void get_valid_birth(Person *person, int len,  Birth *today, int *valid, char *older, char *younger);
void sort_person(Person *person, int len);
void sort_person_v2(Person *person, int len);
void swap(Person *p1, Person *p2);
int cmp_birth(Birth *bir1, Birth *bir2);

int main(){
    int n = 0;
    char younger[6];
    char older[6];
    int valid = 0;
    scanf("%d", &n);

    Person *person = (Person *)malloc(sizeof(Person) * n);
    char ch;
    char birth_str[10];
    Birth today;
    today.year = 2014;
    today.month = 9;
    today.day = 6;

    scanf("%c", &ch);
    for (int i = 0; i < n; i++){
        scanf("%s", (person + i)->name);
        scanf("%c", &ch);
        scanf("%s", birth_str);
        get_birth(birth_str, &((person + i)->birth));
        scanf("%c", &ch);
    }
    get_valid_birth(person, n, &today, &valid, older, younger);
    if (valid == 0){
        printf("%d\n", valid);
    }else if(valid == 1){
        printf("%d %s %s\n", valid, older, older);
    }else{
        printf("%d %s %s\n", valid, older, younger);
    }

    free(person);
    return 0;
}

void get_birth(char *str, Birth *bir){
    char * pch;
    pch = strtok (str, "/");
    int i = 0;
    while (pch != NULL)
    {
//        printf ("%s\n",pch);
        if (i == 0){
            bir->year = atoi(pch);
        }
        if (i == 1){
            bir->month = atoi(pch);
        }
        if (i == 2){
            bir->day = atoi(pch);
        }

        pch = strtok (NULL, "/");
        i ++;
    }
}

void get_valid_birth(Person *person, int len,  Birth *today, int *valid, char *older, char *younger){
    Person *tmp = person;
    Birth old;
    old.year = 1814;
    old.month = 9;
    old.day = 6;
    sort_person_v2(tmp, len);
//    sort_person(tmp, len);

    int valid_birth = 0;
    int start = 0;
    for (int i = 0; i < len; i++){
        if (cmp_birth(&old, &((tmp + i)->birth)) != 1 && cmp_birth(today, &((tmp + i)->birth)) != -1){
            valid_birth ++;
        } else{
            continue;
        }
        if (start == 0) {
            strcpy(older, (tmp + i)->name);
            start ++;
        }
        if (cmp_birth(today, &((tmp + i + 1)->birth)) == -1){
            strcpy(younger, (tmp + i)->name);
            break;
        }

        /*if ((tmp + i)->birth.year > today->year){

            strcpy(younger, (tmp + i - 1)->name);
            break;
        } else if ((tmp + i)->birth.year == today->year){
            if ((tmp + i)->birth.month > today->month){

                strcpy(younger, (tmp + i - 1)->name);
                break;
            } else if((tmp + i)->birth.month == today->month){
                if ((tmp + i)->birth.day > today->day){

                    strcpy(younger, (tmp + i - 1)->name);
                    break;
                } else{
                    continue;
                }
            } else{
                continue;
            }
        } else{
            continue;
        }*/
    }
    *valid = valid_birth;
}

void sort_person(Person *person, int len){
    Person *tmp = person;

    for (int i = 0; i < len-1; i++){

        for (int j = i + 1; j < len; j ++){

            if ((tmp + i)->birth.year > (tmp + j)->birth.year){
                swap(tmp + i, tmp + j);
            } else if((tmp + i)->birth.year == (tmp + j)->birth.year){

                if ((tmp + i)->birth.month > (tmp + j)->birth.month){
                    swap(tmp + i, tmp + j);
                } else if ((tmp + i)->birth.month == (tmp + j)->birth.month){

                    if ((tmp + i)->birth.day > (tmp + j)->birth.day){
                        swap(tmp + i, tmp + j);
                    } else{
                        continue;
                    }
                } else{
                    continue;
                }
            } else{
                continue;
            }
        }
    }
}

void swap(Person *p1, Person *p2){
    Person tmp;
    strcpy(tmp.name, p1->name);
    tmp.birth.year = p1->birth.year;
    tmp.birth.month = p1->birth.month;
    tmp.birth.day = p1->birth.day;

    // deep copy
    strcpy(p1->name, p2->name);
    p1->birth.year = p2->birth.year;
    p1->birth.month = p2->birth.month;
    p1->birth.day = p2->birth.day;

    strcpy(p2->name, tmp.name);
    p2->birth.year = tmp.birth.year;
    p2->birth.month = tmp.birth.month;
    p2->birth.day = tmp.birth.day;

}
/**
 * compare two date
 * @param bir1  first date
 * @param bir2  second date
 * @return if bir1 < bir2 return -1; if bir1 = bir2 return 0; if bir1 > bir2 return 1;
 */
int cmp_birth(Birth *bir1, Birth *bir2){
    int ret = 0;

    if (bir1->year < bir2->year){
        ret = -1;
    } else if(bir1->year == bir2->year){
        if (bir1->month < bir2->month){
            ret = -1;
        } else if(bir1->month == bir2->month){

            if (bir1->day < bir2->day){
                ret = -1;
            } else if (bir1->day == bir2->day){
                ret = 0;
            } else{
                ret = 1;
            }
        } else{
            ret = 1;
        }
    } else{
        ret = 1;
    }
    return ret;
}

void sort_person_v2(Person *person, int len){
    Person *tmp = person;

    for (int i = 0; i < len-1; i++){

        for (int j = i + 1; j < len; j ++){
            if (cmp_birth(&((tmp + i)->birth), &((tmp + j)->birth)) == 1){
                swap(tmp + i, tmp + j);
            }

        }
    }
}