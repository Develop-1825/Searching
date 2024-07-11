#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int findInNearlySortedArray(vector<int> &nums, int n, int target)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (mid + 1 < n && nums[mid + 1] == target)
        {
            return mid + 1;
        }
        else if (mid - 1 >= 0 && nums[mid - 1] == target)
        {
            return mid - 1;
        }
        else if (nums[mid] > target)
        {
            e = mid - 2; // mid-1 is already checked in the above if conditions
        }
        else
        {
            s = mid + 2; // mid+1 is already checked in the above if conditions
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{

    system("cls");
    vector<int> arr = {20, 10, 30, 50, 40, 70, 60};
    int target;
    cout << "Enter the element to search:" << endl;
    cin >> target;
    int ans = findInNearlySortedArray(arr, arr.size(), target);
    if (ans < 0)
        cout << "Element was not found." << endl;
    else
        cout << "The element was found at: " << ans;
    return 0;
}