#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
int divide2Numbers(int divisor, int dividend)
{
    int s = 0;
    int e = dividend;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (mid * divisor == dividend)
        {
            return mid;
        }
        else if (mid * divisor > dividend)
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
    int divisor, dividend;

    cout << "Enter the dividend:" << endl;
    cin >> dividend;
    cout << "Enter the divisor:" << endl;
    cin >> divisor;
    int ans = divide2Numbers(abs(divisor), abs(dividend));
    if (divisor < 0 && dividend > 0)
    {
        cout << "The quotient is: " << (ans * -1);
    }
    else if (dividend < 0 && dividend > 0)
    {
        cout << "The quotient is: " << (ans * -1);
    }
    else
    {
        cout << "The quotient is: " << ans;
    }

    return 0;
}