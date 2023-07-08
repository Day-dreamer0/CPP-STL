// lc 1004 -> https://leetcode.com/problems/max-consecutive-ones-iii/description/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        int zero=0,one=0;
        int mx=INT_MIN;
        while(j<n)
        {
            if(nums[j]==0)
                zero++;
            else if(nums[j]==1)
                one++;
            if((j-i+1)-one<=k)
            {
                mx=max(mx,j-i+1);
            }
            else
            {
                while((j-i+1)-one>k)
                {
                    nums[i]==1?one--:zero--;
                    i++;
                }
                mx=max(mx,j-i+1);
            }
            j++;
        }
        return mx;
    }
};