#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float x_1, x_2;
    int a,b,c;
    scanf("%d %d %d", &a , &b,&c);
    float D = b*b -4 *a*c;
    if(D> 0){x_1=(-b +sqrt(D)) /2*a;x_2=(-b -sqrt(D)) /2/a;}
    printf("%d %d", x_1, x_2);
}

