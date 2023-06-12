/**
* pat1025
* Author: zhiying
* Date: 2021.2.27 12:28
* Update: 2023.6.10 21:10
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

typedef struct {
    string address;    // ５位非负整数
    int data;
    string next;
}Node;

void sort_nodes(vector<Node> &nodes, string first_addr);
void reverse_nodes(vector<Node> &nodes, int k);
void swap_nodes(Node &node1, Node &node2);
bool cmp(Node &node1, Node &node2);
int main(){
    string first_addr;
    int n;
    int k;
    cin >>first_addr>>n>>k;
    vector<Node >nodes;
    for (int i = 0; i < n; i++){
        Node node;
        cin >>node.address>>node.data>>node.next;
        nodes.push_back(node);
//        if (stoi(node.address) >=0 && stoi(node.address) <=99999 && node.address.size() == 5){
//            nodes.push_back(node);
//        }

    }
//    sort(nodes.begin(), nodes.end(),cmp);
    sort_nodes(nodes, first_addr);
    reverse_nodes(nodes, k);

    for (auto node1:nodes){
        cout <<node1.address <<' '<< node1.data <<' '<<node1.next<<endl;
    }
    return 0;
}

void sort_nodes(vector<Node> &nodes, string first_addr){

    for (int i = 0;i < nodes.size();i++){
        if (nodes[i].address == first_addr){
            if (i != 0){
                swap_nodes(nodes[i],nodes[0]);
            }
            break;
        }
    }

    for (int i = 1;i < nodes.size()-1;i++){
        for (int j = i ;j < nodes.size(); j++){
            if (nodes[i-1].next == nodes[j].address){
                if (j != i ){
                    swap_nodes(nodes[i], nodes[j]);
                }
                break;
            }
        }
    }
//    for (int i = 0;i < nodes.size()-1;i++){
//        for (int j = i + 1;j < nodes.size(); j++){
//            if (nodes[i].next == nodes[j].address){
//                if (j != i + 1){
//                    swap_nodes(nodes[i+1], nodes[j]);
//                }
//                break;
//            }
//        }
//    }

    auto pos = nodes.begin();
    int i=0;
    for (;nodes[i].next != "-1";i++){

    }
    i++;
    for (;i < nodes.size();i++){
        nodes.erase(pos+i);
    }
}
void reverse_nodes(vector<Node> &nodes, int k){
    int len = nodes.size();
    int reverse_cnt = len / k;

    for (int i = 0; i < reverse_cnt; i++){
        for (int j = 0; j <(k / 2);j++ ){
            swap_nodes(nodes[i * k + j], nodes[(i+1)*k - j-1]);
        }
    }

    for (int i = 0;i < len-1; i++){
        nodes[i].next = nodes[i+1].address;
    }
    nodes[len-1].next= "-1";
}

void swap_nodes(Node &node1, Node &node2){
    // 深复制与浅复制
    Node tmp ;
    tmp.address = node1.address;
    tmp.data = node1.data;
    tmp.next = node1.next;

    node1.address = node2.address;
    node1.data = node2.data;
    node1.next = node2.next;

    node2.address = tmp.address;
    node2.data = tmp.data;
    node2.next = tmp.next;

}

bool cmp(Node &node1, Node &node2){
    return node1.next == node2.address;
}

// test case
//00003 4 2
//00002 2 00001
//00003 3 00002
//00005 5 77778
//00001 1 -1
