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

using namespace std;

typedef struct{
    string address;
    int data;
    string next;
}Node;

int main() {
    string first;
    int n,k;
    cin >>first;
    cin >>n>>k;
    vector<Node > nodes;

    for (int i =0;i <n;i++){
        Node node;
        cin >>node.address>>node.data>>node.next;
        // first node position
        if (node.address == first){
            nodes.insert(nodes.begin(),node);
        }else{
            nodes.push_back(node);
        }
    }

    for (int i = 1;i < nodes.size() -1;i++){
        for (int j = i;j< nodes.size();j++){
            if (nodes[i-1].next == nodes[j].address && j!= i){
                swap(nodes[i],nodes[j]);
                break;
            }
        }
    }
    int block_cnt = n % k == 0 ? n / k : n / k + 1;
    vector<Node >result;
    for (int i = 0;i< block_cnt;i++){
        vector<Node >block;
        for (int j = 0;j < k;j++){
            if ((i*k+j)<nodes.size()){
                block.push_back(nodes[i*k + j]);
            }else{
                break;
            }
        }
        result.insert(result.begin(),block.begin(),block.end());
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
