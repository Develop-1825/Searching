#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

// k=d means the array is rotated d times => d elements from ends are rotated to the front of the array.
//The size of k must not be greater than size of the array. To maintain that we do k=k%arr.size()
//! This algorithm doesn't use modulus operator.

void print(int*arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}


void reverse(int *a,int s,int e)
{
    int loop_for=(e-s)/2;
    int i=1;
    while(i<=loop_for)
    {
        swap(a[s],a[e-i]);
        s++;
        i++;
    }
}


void rotate(int *a,int k,int n)
{
    reverse(a,0,n);
    // print(a,n);
    // cout<<endl;
    reverse(a,0,k);
    // print(a,n);
    // cout<<endl;
    reverse(a,k,n);
    // print(a,n);
    // cout<<endl;
}


int main()
{
    system("cls");
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    print(arr,7);
    cout<<endl;
    cout<<endl;

    // reverse(arr,0,6);
    rotate(arr,6,7);
    print(arr,7);
    
    return 0;
}