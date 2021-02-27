/**
* pat1020
* Author: zhiying
* Date: 2021.2.27 11:28
*/
#include <stdio.h>
#include <stdlib.h>

union Income
{
    int income_int;
    float income_float;
};

void print(const int *a, int len, char* msg);
void calculate_income(int *stock, int *prices, int len , int max_demand);
int main(){
    int n = 0;
    int max_demand = 0;
    scanf("%d %d", &n, &max_demand);
    int stock[n];
    int prices[n];

    for (int i = 0; i < n; i ++){
        scanf("%d",&stock[i]);
    }

    for (int i = 0; i < n; i ++){
        scanf("%d",&prices[i]);
    }
    /*scanf("%d %d %d", &stock[0], &stock[1], &stock[2]);
    scanf("%d %d %d", &prices[0], &prices[1], &prices[2]);*/

    print(stock, n, "库存量为");
    print(prices, n, "价格为");
    return 0;
}

void print(const int *a, int len, char* msg){
    printf("%s: ",msg);

    for(int i = 0; i < len; i ++){
        printf("%d ",*(a + i));
    }

    printf("\n");
}

void calculate_income(int *stock, int *prices, int len , int max_demand){
    union Income max_income;


}