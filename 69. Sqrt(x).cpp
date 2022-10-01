// Given a non-negative integer x, compute and return the square root of x.

// Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

// Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.


class Solution {
public:
    int binary_search(int n){
        long int ans;
        int s=0;
        int e=n;
        long int mid = s+(e-s)/2;
        while(s<=e)
        {
            if(mid*mid == n)
                return mid;
            
            if(mid*mid > n)
                e=mid-1;

            else
            {
                s=mid+1;
                ans = mid;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    
    int mySqrt(int x) {
        return binary_search(x);
    }
};
