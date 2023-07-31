/**
 * pat1025 v2
 * Author：zhiying
 * Date: 23-7-31 21:58
 * Description:
 * test case6
 * 00003 4 2
 * 00002 2 00001
 * 00003 3 00002
 * 00005 5 77778
 * 00001 1 -1
 * 
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef struct {
    string address;
    int data;
    string next;
}Node;

int main() {
    string head;
    int n,k;
    cin >>head>>n>>k;
    map<string, Node> nodes;
    for (int i =0;i <n;i++){
        Node node;
        cin >>node.address>>node.data>>node.next;
        nodes[node.address] = node;
    }
    string next = head;
    vector<Node> result;
    while(next != "-1"){
        Node node = nodes[next];
        result.push_back(node);
        next = node.next;
    }
    auto pos = result.begin();
    // 测试点6：存在冗余点

    int cnt = result.size() / k;

    // reverse nodes
    for (int i = 0;i <cnt;i++){
        reverse(pos+ i* k, pos + (i+1) *k);
    }
    for (int i = 0;i <result.size();i++){
        if (i != result.size() -1){
            result[i].next = result[i+1].address;
        }else{
            result[i].next = "-1";
        }
        cout <<result[i].address<<' '<<result[i].data<<' '<<result[i].next<<endl;
    }
    return 0;
}
