#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int sqRootInteger(int n)
{
    int s = 0;
    int e = n;
    int mid = s + (e - s) / 2;
    int ans;
    while (s <= e)
    {
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            e = mid - 1;
        }
        else
        {
            ans = mid;
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{

    system("cls");
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    cout << sqRootInteger(n);
    return 0;
}