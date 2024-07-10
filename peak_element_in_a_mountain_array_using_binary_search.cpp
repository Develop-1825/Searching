#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int findPeak(vector<int>& arr,int n)
{
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<e)
    {
        if(arr[mid]<arr[mid+1])
        {
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return arr[s];
}
int main()
{
    system("cls");
    vector<int> arr={1,2,3,10,40,50,60,20,30};
    int n=arr.size();
    cout<<"The peak element is: "<<findPeak(arr,n);
    return 0;
}