#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int twoPointerApproach(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int i = 0;
    int j = 1;
    set<pair<int, int>> ans; // use set to avoid duplicates
    while (j < nums.size())
    {
        int diff = nums[j] - nums[i];
        if (diff == k)
        {
            ans.insert(make_pair(nums[i], nums[j]));
            i++;
            j++;
        }
        else if (diff < k)
        {
            j++;
        }
        else
        {
            i++;
        }
        if (i == j) // corner case
        {
            j++;
        }
    }

    return ans.size();
}

int binarySearch(vector<int> &nums, int s, int target)
{
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int binarySearchApproach(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans; // handling corner case
    for (int i = 0; i < nums.size(); i++)
    {
        if (binarySearch(nums, nums[i], nums[i] + k) != -1)
        {
            ans.insert({nums[i], nums[i] + k});
        }
    }
    return ans.size();
}

int main()
{
    // vector<int> nums = {3, 1, 4, 1, 5};
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1}; // corner case
    // cout << "No.of unique pairs:" << twoPointerApproach(nums, 2);
    cout << endl
         << "No.of unique pairs:" << binarySearchApproach(nums, 0) << endl;
    return 0;
}