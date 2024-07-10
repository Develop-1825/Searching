#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int findMissing(vector<int> &nums, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans=-1;
    while (s <= e)
    {
        if (nums[mid] - mid == 1)
        {
            s = mid + 1;
        }
        else
        {
            ans = nums[mid];
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    // //makes no sense but still if you want to show that the last element is not there
    // //then do this
    // if(ans==-1) //no missing elements =>  ums[mid]-mid was consistently 1
    // return n+1;

    return ans - 1;
}
int main()
{

    system("cls");
    vector<int> arr = {1,2, 3, 4, 5, 6, 7, 8};
    int ans = findMissing(arr, arr.size());
    (ans<0)?cout<<"No missing element"<<endl:cout<<"Missing element = " << ans<<endl;
    // cout << "Missing element = " << ans;

    return 0;
}