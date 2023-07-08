// LC-> https://leetcode.com/problems/combination-sum-iv/description/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int> > t(nums.size()+1,vector<int> (target+1,0));
        for(int j=0;j<target+1;++j)
        {
            t[0][j]=0;
        }

        for(int i=0;i<nums.size()+1;i++)
        {
            t[i][0]=1;
        }

        // for(int j=1;j<target+1;++j)
        // {
        //     if(j%nums[0]==0)
        //         t[1][j]=1;
        // }

        for(int i=1;i<nums.size()+1;++i)
        {
            for(int j=1;j<target+1;++j)
            {

                for(int l=0;l<nums.size();++l)
                {
                    
                    if(nums[l]<=j)
                    {
                        // t[i][j] += t[i][j-nums[l]];
                        //OR
                        long long int val=t[i][j];
                        val+=t[i][j-nums[l]];
                        if(val>INT_MAX)
                            t[i][j]=0;
                        else
                            t[i][j] += t[i][j-nums[l]];
                    }

                }
                
            }
        }
        return t[nums.size()][target];
        // int sum=0;
        // for( int i=1; i<nums.size()+1; ++i)
        //     sum += t[i][target];   
        // return sum;
    }
};