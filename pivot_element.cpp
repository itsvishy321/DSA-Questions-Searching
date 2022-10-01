// Pivot element is the only element in input array 
// which is smaller than it's previous element. 
// A pivot element divided a sorted rotated array 
// into two monotonically increasing array.

// A = {7,9,1,2,3}
// pivot elememt -> 1

// B = {8,9,10,5,6,7}
// pivot element -> 5

#include <iostream>
#include <vector>
using namespace std;

int getPivot(vector<int> arr, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int main()
{
    vector<int> test = { 7,9,1,2,3 };
    cout << "Pivot  index is " << getPivot(test, test.size()) << endl;
    return 0;
}
