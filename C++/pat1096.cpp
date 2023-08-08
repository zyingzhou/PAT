/**
* pat1096
* Author: zhiying
* Date: 2023.8.6
*
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

bool isprime(int num);
bool is_big_perfect_number(int num);
set<int> get_factor(int num);
void dfs(const set<int> factors, int sum,vector<int> vec,int len,int p,int left,bool & ret);

int main(){
    int n;
    cin >>n;
    const string YES = "Yes";
    const string NO = "No";
    vector<string> result;

    for (int i = 0;i < n;i++){
    	int k;
    	cin >>k;
    	if (isprime(k) || k == 1){
    		result.push_back(NO);
		}else{
			if (is_big_perfect_number(k)){
			    result.push_back(YES);
			}else{
				result.push_back(NO);
			}
		}
	}
	
	for (auto v:result){
		cout <<v<<endl;
	}
    return 0;
}

bool isprime(int num){
	bool ret = true;
	
	if (num ==1){
		ret = false;
	}
	
	for (int i = 2; i <= sqrt(num);i++){
		if (num % i ==0){
			ret = false;
			break;
		}
	}
	return ret;
}

bool is_big_perfect_number(int num){

	bool ret = false;
	set<int> factors = get_factor(num);
    vector<int> vec(factors.begin(),factors.end());
    sort(vec.begin(),vec.end());
    vector<int> vec1(vec.begin(),vec.end()-1);
	if (factors.size() > 4){
        dfs(factors,0,vec1,vec1.size(),0,4,ret);
//		ret = true;
	}
	
	return ret;
}

set<int> get_factor(int num){
	set<int> factors;
	for (int i = 1; i<= sqrt(num);i++){
		if (num % i == 0){
			factors.insert(i);
			factors.insert(num / i);
		}
	}
	return factors;
}

void dfs(const set<int> factors, int sum,vector<int> vec,int len,int p,int left,bool & ret){
//    因为n-1是数组最大的下标，所以left为0时，某一种组合已经完成
    if(left==0){
        if (factors.find(sum) != factors.end()){
            ret = true;
            return;
        }
//        cout <<sum<<endl;
        sum = 0;
    }
        //n-left是当前所选下标的最大值，若超过，则会选不够；因为这是按照从前往后的顺序以此进行选择
    else for(int i=p;i<=len-left;i++){

            dfs(factors,sum+vec[i],vec,vec.size(),i+1,left-1,ret); //每递归一次，就会选出一个数来，left就减一
        }
}

