// lc 2461 -> https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
// if commented code is used then TC would be O(nk) else in this part it would be O(n)

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long int sum=0;
        int i=0,j=0;
        long long int mx=INT_MIN;
        unordered_map<int,int> um;
        int n=nums.size();
        while(j<n)
        {
            um[nums[j]]++;
            sum+=nums[j];
            while(um[nums[j]]>=2)
            {
                um[nums[i]]--;
                if(um[nums[i]]==0)
                    um.erase(nums[i]);
                sum-=nums[i];
                i++;
            }
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                // if(um.size()!=k)
                // {
                //     for(auto p:um)
                //     {
                //         while(um[p.first]>=2)
                //         {
                //             um[nums[i]]--;
                //             if(um[nums[i]]==0)
                //                 um.erase(nums[i]);
                //             sum-=nums[i];
                //             i++;
                //         }
                //     }
                // }
                // else
                // {
                    mx=max(sum,mx);
                    sum-=nums[i];
                    um[nums[i]]--;
                    if(um[nums[i]]==0)
                        um.erase(nums[i]);
                    i++;
                // }
                j++;
            }
        }

        if(mx == INT_MIN)
            mx=0;
        return mx;
    }
};