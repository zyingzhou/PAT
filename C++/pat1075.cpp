/**
 * pat1075
 * Author：zhiying
 * Date: 23-7-31 21:25
 * Description:
 * 
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef struct {
    string address;
    int data;
    string next;
}Node;

int main() {
    string head;
    vector<Node >first;
    vector<Node >less_k;
    vector<Node >greater_k;
    int n,k;
    cin >>head>>n>>k;
    map<string, Node > nodes;
    for (int i =0;i < n;i++){
        Node node;
        cin>>node.address>>node.data>>node.next;
        nodes[node.address] = node;

    }
    string next = head;
    while (next != "-1"){
        Node node = nodes[next];
        if (node.data <0){
            first.push_back(node);
        }else if(node.data >=0 && node.data <=k){
            less_k.push_back(node);
        }else{
            greater_k.push_back(node);
        }
        next = node.next;
    }
    vector<Node >result;
    if (!greater_k.empty()){
        result.insert(result.begin(),greater_k.begin(),greater_k.end());
    }
    if (!less_k.empty()){
        result.insert(result.begin(),less_k.begin(),less_k.end());
    }
    if(!first.empty()){
        result.insert(result.begin(),first.begin(),first.end());
    }

    for (int i =0;i <result.size();i++){
        if (i != result.size() -1){
            result[i].next = result[i+1].address;
        }else{
            result[i].next = "-1";
        }
        cout <<result[i].address<< ' '<<result[i].data<<' '<<result[i].next<<endl;
    }
    return 0;
}
