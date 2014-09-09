#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define N 3

using namespace std;

void rotate(int a[][N], int n);
void printf(int a[][N], int n);
void swap(int &a, int &b);

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

void swap(int &a, int &b){
    int t=a;
    a= b;
    b= t;
}

void rotate(int a[][N], int n){
    int i,j;
    for( i=0; i<n; i++)
        for(j=0; j<i; j++){
            swap(a[i][j], a[j][i]);
        }

    for( i=0; i<n; i++)
        for(j=0; j<n/2; j++)
            swap(a[i][j], a[i][n-1-j]);

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
