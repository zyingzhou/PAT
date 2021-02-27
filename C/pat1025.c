/**
* pat1025
* Author: zhiying
* Date: 2021.2.27 12:28
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char address[6];    // ５位非负整数
    int data;
    char next[6];
}Node;

void swap (Node *node1, Node *node2);
void sort_nodes(Node *nodes, int len, char *head);
void reverse_nodes(Node *nodes, int len, int reverse);
void print_L(const Node *nodes, int len);

int main(){
    char head[6] = {'0'};
    int n = 0;
    int reverse = 0;
    scanf("%s", head);
    scanf("%d %d", &n, &reverse);

    Node *nodes = (Node *)malloc(sizeof(Node)* n);

    for (int i = 0; i < n; i++){
        scanf("%s", (nodes+i)->address);
        scanf("%d %s", &(nodes+i)->data, (nodes+i)->next);
    }
    sort_nodes(nodes, n, head);
    reverse_nodes(nodes, n, reverse);
    print_L(nodes, n);

    free(nodes);
    return 0;
}

void swap (Node *node1, Node *node2){
//    Node tmp = *node1;
    // deep copy
    Node tmp;

    // copy node1's value to tmp
    strncpy(tmp.address, node1->address, 6);
    tmp.data = node1->data;
    strncpy(tmp.next, node1->next, 6);

    // copy node2's value to node1
    strncpy(node1->address, node2->address, 6);
    node1->data = node2->data;
    strncpy(node1->next, node2->next, 6);

    // copy tmp's value to node2
    strncpy(node2->address, tmp.address,6);
    node2->data = tmp.data;
    strncpy(node2->next, tmp.next,6);
}

void sort_nodes(Node *nodes, int len, char *head){
    Node *tmp = nodes;
    // find head
    for (int i = 0; i < len; i ++){
        if (strncmp((tmp + i)->address, head, 6) == 0){
            if (i != 0){
                swap(tmp, tmp + i);
            }
            break;
        }
    }
    // next
    for (int idx = 1; idx < len-1; idx ++){

        for (int i = idx; i < len; i ++){

            if (strncmp((tmp + idx - 1)->next, (tmp + i)->address, 6) == 0){

                if (i != idx){
                    swap((tmp + idx), (tmp + i));
                }
                break;
            }
        }
    }
}

void reverse_nodes(Node *nodes, int len, int reverse){
    Node *tmp = nodes;
    if (reverse == 0) return;
    int cnt = len / reverse;

    // 反转的轮数
    for (int j = 0; j < cnt; j++){
        // 旋转
        int reverse_counts = reverse / 2;
        // 对换
        for (int i = 0; i < reverse_counts; i ++){
            swap(tmp + i + j * reverse, tmp + reverse - 1 - i + j * reverse);
        }
    }

    // reset all of nodes which they point
    for (int i = 0; i < len-1; i ++){
        strncpy((tmp + i)->next, (tmp + i + 1)->address, 6);
    }
    /*if (reverse > 1){

    }*/
    // 最后一个节点应该指向NULL
    if (strncmp((tmp + len -1)->next, "-1", 3) != 0){
        strncpy((tmp + len - 1)->next,"-1", 3);
    }
}
void print_L(const Node *nodes, int len){

    for (int i = 0; i < len; i ++){
        printf("%s %d %s\n", (nodes+i)->address, (nodes+i)->data, (nodes+i)->next);
    }

}
