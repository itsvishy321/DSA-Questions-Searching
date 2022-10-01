// First and last position of an element in a sorted array



#include <iostream>
#include <vector>
using namespace std;

int firstOcc(vector<int> arr, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] << key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int lastOcc(vector<int> arr, int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    int ans;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] << key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;

    }
    return ans;
}

int main()
{
    vector<int> arr = { 2,3,3,3,3,3,3,3,5,6 };
    cout << "First Occurence of 3 at index " << firstOcc(arr, arr.size(), 3) << endl;
    cout << "Last Occurence of 3 at index " << lastOcc(arr, arr.size(), 3) << endl;

    return 0;
}




// ******************NOTE****************

/*

Total no. of occurences of key = lastOcc - first Occ + 1

*/