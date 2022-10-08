/*
    for an array A
->  Ai represents number of units in the ith board
->  K represents number of painters
->  Each unit on board takes 1unit of time
->  We need to return area of the minimum time to get this job done such that :
    
    #NOTE  any painter will only paint the continuous sections on boards
*/

#include <iostream>
#include <vector>
using namespace std;

bool possibleSoln(vector<int> arr, int n, int mid, int k)
{
    int paintersCount = 1;
    int boardSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (boardSum + arr[i] <= mid)
        {
            boardSum += arr[i];
        }

        else
        {
            paintersCount++;
            if (paintersCount > k || arr[i] > mid)
            {
                return false;
            }
            boardSum = arr[i];
        }
    }
    return true;
}

int painters_partition(vector<int> arr, int n, int k)
{
    int s = 0, e = 0;
    int ans = -1;
    for (int x : arr)
    {
        e += x;
    }
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (possibleSoln(arr, n, mid, k))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;

}

int main()
{
    vector<int> arr = { 5, 10 , 6 , 7 };
    int result = painters_partition(arr, arr.size(), 3);

    result == -1 ?
        cout << "Painters partition can not be possible!" << endl :
        cout << "Painters partition result : " << result << endl;
    return 0;
}
