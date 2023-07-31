/**
* pat1105
* Author: zhiying
* Date: 2023.7.30
*
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
void cal_diff(set<int> &nums, set<int> &diff,int in);

int main(){
    int n,m,num1,num2;
    set<int> nums;
    set<int> diff;
    cin >>num1;
    nums.insert(num1);
    cin >>num2;
    nums.insert(num2);
    diff.insert(abs(num1-num2));

    cin >>n>>m;
    vector<vector<int> > arrs;
    for (int i =0;i <n;i++){
    	vector<int>arr;
    	for (int j = 0;j <m;j++){
    		int num;
    		cin >>num;
    		arr.push_back(num);
		}
		arrs.push_back(arr);
	}
    int failed = 0;
	for (int i = 0;i < m;i++){
		for (int j = 0;j<arrs.size();j++){
			if (!arrs[j].empty()){
				if (diff.find(arrs[j][i]) != diff.end() && nums.find(arrs[j][i])== nums.end()){
				    cal_diff(nums,diff,arrs[j][i]);
                }else{
                    failed++;
                    cout<<"Round #"<<i+1<<": "<<j+1<<" is out."<<endl;
                    //cal_diff(nums,diff,arrs[j][i]);
                    arrs[j].erase(arrs[j].begin(),arrs[j].end());
			}
			}
		}
	}
    if (arrs.size() == failed){
        cout<<"No winner."<<endl;
    }else{
        cout<<"Winner(s):";
        for (int i = 0;i< arrs.size();i++){
            if (!arrs[i].empty()){
                cout<<' '<<i+1;
            }
        }
        cout<<endl;
    }

    return 0;    
}
void cal_diff(set<int> &nums, set<int> &diff,int in){
	for (int i : nums){
		diff.insert(abs(i-in));
	}
	// update 
	nums.insert(in);
}
