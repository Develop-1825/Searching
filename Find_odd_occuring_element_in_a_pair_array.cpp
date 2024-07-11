#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int findOddOccuringElement(vector<int> &nums, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s < e)
    {
        if (mid & 1) // odd
        {
            // compare with previous elements
            if ((mid - 1) >= 0 && nums[mid - 1] == nums[mid])
            {
                // we are in region A
                // we need to go right
                s = mid + 1;
            }
            else
            {
                // we are in region B
                // we need to go left
                e = mid - 1;
            }
        }
        else // even
        {
            // compare with next elements
            if ((mid + 1) < n && nums[mid] == nums[mid + 1])
            {
                // we are in region A
                // we need to go right
                // but the right element is already checked
                // so
                s = mid + 2;
            }
            else
            {
                // we are in the region B OR we are standing on the answer
                // we need to go left
                // but the mid element might be a potential answer because we might be standing on answer as well(Because it is an even index)
                e = mid;
            }
        }
        mid = s + (e - s) / 2;
    }
    // loop breaks when s==e i.e only single element is remaining. That is the answer.
    return nums[mid];
}

int main()
{

    system("cls");
    vector<int> arr = {10, 10, 2, 2, 5, 5, 2, 5, 5, 20, 20, 11, 11, 10, 10};
    int ans = findOddOccuringElement(arr, arr.size());
    cout << "The odd occuring element is: " << ans;
    return 0;
}