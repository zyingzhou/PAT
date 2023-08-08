/**
* pat1050
* Author: zhiying
* Date: 2023.6.26 23:35
*
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool sort_by_value(int num1,int num2);
void reshape_to_2dim(vector<int> vec, int m,int n);

int main(){
    int n;
    cin >>n;
    vector<int> vec;

    for (int i = 0;i < n;i++){
        int num;
        cin >>num;
        vec.push_back(num);
    }
    sort(vec.begin(),vec.end(), sort_by_value);
    int m = ceil(sqrt(n));
    cout <<m<<endl;
    int k = n / m;
    cout <<k<<endl;
    reshape_to_2dim(vec,m,k);

    return 0;
}

bool sort_by_value(int num1,int num2){
    return num1>num2;
}

void reshape_to_2dim(vector<int> vec, int m,int n){
    // m >n
    int **arr=new int*[m];
    for(int i = 0;i < m;i++){
        arr[i] = new int[n];
    }
    int j = 0;
    int row = 0;
    int col = 0;
    int circle = 0;
    while(true){
        for(;col< n;col++){
            arr[row][col] = vec[j];
            j++;
        }
        col--;
        for (row= row+1;row <m;row++){
            arr[row][col]= vec[j];
            j++;
        }
        row--;
        for (col = col -1;col>=0;col--){
            arr[row][col] = vec[j];
            j++;
        }
        col++;
        for (row = row-1;row > 0;row--){
            arr[row][col] = vec[j];
            j++;
        }
        row++;
    }

    for (int a = 0;a <m;a++){
        for (int b = 0;b <n;b++){
            cout <<arr[a][b]<<' ';
        }
        cout <<endl;
    }
    for (int i =0;i< m;i++){
        delete [] arr[i];
    }
}