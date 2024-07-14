#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

// * assuming the max element in rotated sorted array to be the pivot element
//* search an element in rotated search array return -1 if not found.

int bin_search(vector<int>&nums,int s,int e,int target)
{
    int mid = s+(e-s)/2;
    while(s<=e)
    {
        if(nums[mid]==target)
        return mid;
        else if(target>nums[mid])
        s=mid+1;
        else if(target<nums[mid])
        e=mid-1;
        else
        return -1;

        mid= s+(e-s)/2;
    }
    return -1;
}
int find_pivot(vector<int> &arr)
{
    int s = 0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;

    while(s<=e)
    {
        if(s==e) //single element
        {
            return s;
        }
        else if((mid+1)<=(arr.size()-1) && arr[mid]>arr[mid+1]) //! Don't forget the boundary conditions.
        {
            return mid;
        }
        else if( (mid-1) >=0 && arr[mid]<arr[mid-1])//! Don't forget the boundary conditions.
        {
            return mid-1;
        }
        else if(arr[mid]<arr[0])
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }

        mid=s+(e-s)/2;
    }   

    return -1; 


}

int search(vector<int>& nums, int target) 
{
    int pivot=find_pivot(nums);
    int s=0;
    int e=nums.size()-1;

    if(target<nums[0])
    {
        bin_search(nums,pivot+1,e,target);
    }
    else if(target>nums[0])
    {
        bin_search(nums,0,pivot,target);
    }
    else
    return -1;
}

int main()
{
    system("cls");
    vector<int>v ;

    //Case-1
    v.push_back(12);
    v.push_back(14);
    v.push_back(16);
    v.push_back(2);
    v.push_back(4);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);
   
   //Case-2
    // v.push_back(1);
    // v.push_back(3);

    cout<<search(v,11);
    return 0;
}