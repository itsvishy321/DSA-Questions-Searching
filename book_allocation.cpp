/*

    for an array A
->  Ai represents number of pages in the ith book
->  We need to allocate books to m number of students such that :

    1) each student get atleast 1 book
    2) each book should be allocated to a student
    3) allocation should be in contiguous manner
    4) "maximum number of pages assigned to a student should be minimum"

*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> arr, int n, int m, int mid)
{
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (pageSum + arr[i] <= mid)
        {
            pageSum += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > m || arr[i] > mid)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;

}

int book_allocation(vector<int> arr, int n, int m)
{
    int s = 0;
    int e = 0;
    for (int x : arr)
    {
        e += x;
    }
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossible(arr, n, m, mid))
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
    vector<int> test = { 10,20,30,40,50 };
    int result = book_allocation(test, test.size(), 3);

    result == -1 ?
        cout << "No allocation of books can be possible for this input" << endl :
        cout << "Book allocation result : " << result << endl;

    return 0;
}
