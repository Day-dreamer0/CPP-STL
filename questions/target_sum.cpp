// LC-> https://leetcode.com/problems/target-sum/description/
class Solution {
public:
    int count_subset_sum(vector<int>& nums, int sum)
    {
        int t[nums.size()+1][sum+1];
        for(int j=0;j<sum+1;j++)
            t[0][j]=0;
        t[0][0]=1;
        int cnt=1;
        for(int i=1;i<nums.size()+1;++i)
        {
            if(nums[i-1]==0)
            {
                cnt*=2;
                t[i][0]=cnt;
            }
            else
            {
                t[i][0]=t[i-1][0];
            }
        }
        for(int i=1;i<nums.size()+1;++i)
        {
            for(int j=1;j<sum+1;++j)
            {
                if(nums[i-1]<=j)
                {
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[nums.size()][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
        }
        if(((sum+target)&1) or (sum+target)<0)
            return 0;
        int s=(sum+target)/2;
        return count_subset_sum(nums,s);
    }
};