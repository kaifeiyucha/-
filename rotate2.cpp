#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define N 3

using namespace std;

void rotate(int a[][N], int n);
void printf(int a[][N], int n);
//把矩阵向右旋转90度，按圈扒
//把每一层看做是top, left, right, buttom
//把每一层的最左边的元素拿出来用temp保存起来，然后
//再把对应元素放到这个位置上，遍历每一行。

int main(int argc, const char *argv[])
{
    int i,j;
    int n=0;
    int a[N][N];
    memset(a, 0, sizeof(a));
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            a[i][j] = n++;
    rotate(a, 3);
    return 0;
}


void rotate(int a[][N], int n){
    int i,j,k;
    int count=0;
    for(i=0; i<N/2; i++)//层数
        for(j=i;j<N-1-i;j++){//每一行的个数i 为层数
            int temp = a[i][j];
            a[i][j] = a[N-1-j][i];
            a[N-1-j][i] = a[N-1-i][N-1-j];
            a[N-1-i][N-1-j]=a[j][N-1-i];
            a[j][N-1-i] = temp;
        }
    printf(a, n);
}

void printf(int a[][N], int n){
    int m= 0;
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++){
            m++;
            cout << a[i][j] <<" ";
            if(m%3==0)
                cout << endl;
        }
}
