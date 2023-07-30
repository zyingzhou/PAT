/**
* pat1105
* Author: zhiying
* Date: 2023.7.30
*
*/
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

typedef struct{
    string address;
    int data;
    string next;
}Node;

void get_link(map<string,Node> &nodes, string first,vector<Node> &link);

int main(){
    int n;
    string link1_first;
    string link2_first;
    cin >>link1_first >>link2_first >>n;
    map<string, Node> nodes;
    for (int i =0;i < n;i++){
        Node node;
        cin>>node.address>>node.data>>node.next;
        nodes[node.address] = node;
    }
    vector<Node>link1;
    vector<Node>link2;
    get_link(nodes,link1_first,link1);
    get_link(nodes,link2_first,link2);
    vector<Node>result;
    int idx = 0;
    vector<Node > &lo = link1.size() < link2.size()? link1: link2;
    vector<Node > &hi = link1.size() > link2.size()? link1: link2;
    reverse(lo.begin(),lo.end());
    for(int i = 0;i <hi.size();i++){
        result.push_back(hi[i]);
        if((i+1) %2 == 0 && idx < lo.size()){
            result.push_back(lo[idx]);
            idx++;
        }
    }
    
    for (int i = 0;i < result.size();i++){
        if(i != result.size() -1){
            result[i].next = result[i+1].address;
        }else{
            result[i].next = "-1";
        }
        cout <<result[i].address << ' '<<result[i].data <<' '<<result[i].next<<endl;
    }
    return 0;    
}

void get_link(map<string,Node> &nodes, string first,vector<Node> &link){
    string next = std::move(first);
    while(next != "-1"){
        link.push_back(nodes[next]);
        next = nodes[next].next;
    }
}
