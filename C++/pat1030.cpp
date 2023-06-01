/*
** pat1030 
* Author: zhiying 
* Date: 2023.2.9
*
*/

#include<iostream>

void swap(int *num1, int *num2);
void sort(int *arrs, int len);
int find_perfect(int *arrs, int len, int p);
template<typename T>
void merge_sort(T arr[], int len);
using namespace std;

int main(){
    int n = 0;
    int p = 0;
    // input
    cin >> n >> p;
    int *arrs = NULL;
    arrs = new int[n];
    for (int i = 0; i < n; i ++){
        cin >> arrs[i];
    }
    // sort
    sort(arrs, n);
//    merge_sort(arrs, n);
//    cout << n << " " << p << endl;
//    for (int j = 0; j < n; j++){
//        cout << arrs[j] << " ";
//    }
//    cout <<endl;
    // compare
    int result = 0;
    result = find_perfect(arrs, n, p);
    cout << result << endl;
    delete [] arrs;
    return 0;

}
void swap(int *num1, int *num2){
    int tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

// from low to high
void sort(int *arrs, int len){
    // bubble sort

    for (int i = 0; i < len-1; i ++){
        for (int j = i + 1; j < len; j++){
            if (arrs[i] > arrs[j]){
                swap(&arrs[i], &arrs[j]);
            }

        }

    }

}

int find_perfect(int *arrs, int len, int p){
//    M <=mp
    int low = 0;
    int high = len -1;
    int ret = len;
    while (ret > 1){

        for (int i = 0; i <=len-ret;i ++){
//            cout << "arrs[i]=" << arrs[i] << " " << "arrs[i+ret-1]=" <<arrs[i+ret-1] <<endl;
            if (arrs[i] * p >= arrs[i+ret-1]){
                return ret;
            }
        }
        ret--;

    }

    return ret;
}

template<typename T>
void merge_sort(T arr[], int len) {
    T *a = arr;
    T *b = new T[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        T *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}