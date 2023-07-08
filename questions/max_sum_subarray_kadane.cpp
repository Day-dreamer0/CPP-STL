// lc 53 -> https://leetcode.com/problems/maximum-subarray/description/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local=0;
        int n=nums.size(),i=0;
        int mx=INT_MIN;
        while(i<n)
        {
            local+=nums[i];
            mx=max(mx,local);
            if(local<0)
            local=0;
            i++;
        }
        return mx;
    }
};