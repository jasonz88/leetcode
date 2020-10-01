class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans = ans^nums[i];
        }
        return ans;
    }
};

// I have added a CPP solution for Single Number Leetcode 136
Kindly Acknowledge.
