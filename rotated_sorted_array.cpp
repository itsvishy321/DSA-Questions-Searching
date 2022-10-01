/*
for a sorted array {1,3,5,7,8}
rotated array at index 3 is {7,8,1,3,5}
*/

#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int>& arr, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] >= arr[0])
            s = mid + 1;

        else
            e = mid;

        mid = s + (e - s) / 2;
    }
    return s;

}

int binary_search(vector<int> arr, int s, int e, int key)
{
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
            return mid;

        else if (arr[mid] > key)
            e = mid - 1;

        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    vector<int> test = { 6,8,10,12,1,2,3,5 };

    int key, n, ans;
    n = test.size();
    cin >> key;
    int pivot = getPivot(test, n);

    if (key >= test[pivot] && key <= test[n - 1])
    {
        ans = binary_search(test, pivot, n - 1, key);
    }
    else
    {
        ans = binary_search(test, 0, pivot - 1, key);
    }
    if (ans != -1)
    {
        cout << "Element found at index " << ans << endl;
    }
    else
    {
        cout << "Element not found!" << endl;
    }


    return 0;
}