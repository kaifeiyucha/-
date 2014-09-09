#include <iostream>

using namespace std;

void *cal(int *a, int n);
void printf(int *a, int n);
//a[2 3 4 5]
//output[60 40 30 24]
//
int main(int argc, const char *argv[])
{
    int a[4]={2,3,4,5};
    cal(a, 4);
    return 0;
}

void printf(int *a, int n){
    for(int i=0; i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void *cal(int *a ,int n){
    int *left = new int[n];
    int *right = new int[n];
    int *result =new int[n];
    left[0]=right[n-1]=1;
    for(int i = 1; i<n; i++){
        left[i]=left[i-1]*a[i-1];
    }

    for(int j=n-2; j>=0; j--){
        right[j]=right[j+1]*a[j+1];
    }

    for(int i=0; i<n; i++)
    result[i]=left[i]*right[i];
    
    printf(result, 4);
}
