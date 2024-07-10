#include<iostream>
#include<stdlib.h>
#include<vector>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int findFirstOccurence(vector<int>&nums,int &s,int &e,int &target)
{
    int mid=(s+e)/2;
    int ans;
    while(s<=e)
    {
        if(nums[mid]==target)
        {
            ans=mid;
            e=mid-1; //important step
        }
        else if(nums[mid]>target)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=(s+e)/2;
    }
    return ans;
}
int main()
{

    system("cls");
    vector<int> arr={10,20,30,30,30,40,50};
    int s=0;
    int target=30;
    int e=arr.size()-1;
    cout<<findFirstOccurence(arr,s,e,target);

    return 0;
}