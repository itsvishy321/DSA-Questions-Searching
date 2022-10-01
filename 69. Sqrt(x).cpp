// Given a non-negative integer x, compute and return the square root of x.


// Given a non-negative integer x, compute and return the square root of x.

#include <iostream>
using namespace std;

long int sqrtInt(int n) {
    long int ans;
    int s = 0;
    int e = n;
    long int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (mid * mid == n)
            return mid;

        if (mid * mid > n)
            e = mid - 1;

        else
        {
            s = mid + 1;
            ans = mid;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSoln)
{
    double factor = 1;
    double ans = tempSoln;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;

}

int main()
{
    int x;
    cin >> x;

    int tempSol = sqrtInt(x);
    cout << "Square root of element is " << morePrecision(x, 10, tempSol) << endl;

    return 0;
}
