//MAX product subarray
//lc-> https://leetcode.com/problems/maximum-product-subarray/description/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_p=nums[0],min_p=nums[0];
        int max_g=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            int temp=max_p;
            max_p=max(nums[i],temp*nums[i]);
            max_p=max(min_p*nums[i],max_p);

            if(max_g<max_p)
            max_g=max_p;
            
            min_p=min(nums[i],min_p*nums[i]);
            min_p=min(min_p,temp*nums[i]);
        }

        return max_g;
    }
};