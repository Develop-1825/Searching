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
    double finalAns = sqRootInteger(n);
    int precision;
    cout << "Enter the precision: " << endl;
    cin >> precision;
    double step = 0.1;
    for (int i = 0; i < precision; i++)
    {
        for (double j = finalAns; j * j <= n; j += step)
        {
            finalAns = j;
        }
        step /= 10;
    }
    cout << endl
         << "The square root of " << n << " upto " << precision << " decimal places is:" << finalAns << endl;
    return 0;
}