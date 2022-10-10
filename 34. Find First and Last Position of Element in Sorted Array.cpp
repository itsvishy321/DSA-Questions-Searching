// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.


class Solution {
public:
    int firstPosition(vector<int> &nums , int target , int n)
    {
        int ans = -1;
        int s=0;
        int e=n-1;
        int mid = s+(e-s)/2;
        while(s<=e)
        {
            if(nums[mid]==target)
            {
                ans = mid;
                e = mid - 1;
                s = 0;
            }
            else if(target>nums[mid])
            {
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
    
    int lastPosition(vector<int> &nums , int target , int n)
    {
        int ans = -1;
        int s=0;
        int e=n-1;
        int mid = s+(e-s)/2;
        while(s<=e)
        {
            if(nums[mid]==target)
            {
                ans = mid;
                s = mid+1;
                e = n-1;
            }
            else if(target>nums[mid])
            {
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }
        
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(firstPosition(nums,target,nums.size()));
        ans.push_back(lastPosition(nums,target,nums.size()));
        
        return ans;
    }
};
