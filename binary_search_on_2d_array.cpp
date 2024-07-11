#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int binarySearchOn2DArray(vector<vector<int>> &mat, int r, int c, int target)
{
    int s = 0;
    int e = r * c - 1;
    int mid = s + (e - s) / 2;
    int ans;
    while (s <= e)
    {
        int i = mid / c;
        int j = mid % c;
        if (mat[i][j] == target)
        {
            return mid;
        }
        else if (mat[i][j] > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{

    system("cls");
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    int index = binarySearchOn2DArray(mat, 3, 4, 44);
    if (index < 0)
        cout << "The element was not found." << endl;
    else
    {
        int i = index / 4;
        int j = index % 4;
        cout << "The element was found at " << '(' << i << "," << j << ')' << endl;
    }

    return 0;
}