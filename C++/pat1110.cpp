/**
 * pat1110
 * Author：zhiying
 * Date: 23-7-29 22:20
 * Description:
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef struct{
    string address;
    int data;
    string next;
}Node;

int main() {
    string head;
    int n,k;
    cin >>head;
    cin >>n>>k;
    map<string, Node >nodes;

    for (int i =0;i <n;i++){
        Node node;
        cin >>node.address>>node.data>>node.next;
        nodes[node.address] = node;
    }

    // make the link ordered
    vector<Node> result;
    string next = head;
    while (next != "-1"){
        Node node = nodes[next];
        result.push_back(node);
        next = node.next;
    }

    // split into blocks
    vector<vector<Node >> blocks;
    vector<Node >block;
    for (int i = 0;i <result.size();i++){
        block.push_back(result[i]);
        if ((i+1) % k == 0){
            blocks.push_back(block);
            block.clear();
            continue;
        }
        if (i == result.size()-1){
            blocks.push_back(block);
            block.clear();
        }
    }
    // reverse
    reverse(blocks.begin(),blocks.end());
    result.clear();
    for (auto item: blocks){
        if (!item.empty()){
            for (auto v: item){
                result.push_back(v);
            }
        }
    }
    for (int i =0;i<result.size();i++){
        if (i != result.size()-1){
            result[i].next = result[i+1].address;
        }else{
            result[i].next="-1";
        }
        cout <<result[i].address << ' '<<result[i].data<< ' '<<result[i].next<<endl;
    }

    return 0;
}
