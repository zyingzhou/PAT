/**
* pat1051
* Author: zhiying
* Date: 2021.3.1 20:00
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float r1, p1, r2, p2;
    scanf("%f %f %f %f", &r1, &p1, &r2, &p2);
    // A1 = r1cos(p1) B1 = r1sin(p1) , A2 = r2cos(p2) B2 = r2sin(p2) (A1, B1) (A2, B2)
    // (A1A2 - B1B2, B1A2 + A1B2)
    float real = r1 * cos(p1) * r2 * cos(p2) - r1*sin(p1)*r2*sin(p2);
    float imag = r1 * sin(p1)* r2 * cos(p2) + r1 * cos(p1) * r2 *sin(p2);
    printf("%.2f%.2fi", real, imag);
    return 0;
}