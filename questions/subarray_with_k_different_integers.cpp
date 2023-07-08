class Solution {
public:
    // vector<int> v(2*10000+7,-1);
    // int check=0;
    void sliding_window_count(vector<int> nums, unordered_map<int,int> &um,int k, long long int &count,int j,vector<int> &v,int &i,int &current)
    {        
        if(current==-1)
            v[j]=1;
        else
            v[j]=v[current]+1;
        while(um.size()==k)
        {
            if(um[nums[i]]>1)
                um[nums[i]]--;
            if(um.size()==k)
                v[j]++;
            i++;
        }
        current=j;
        return;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        long long int count=0;
        unordered_map<int,int> um;
        int current=-1;
        vector<int> v(2*10000+7,-1);
        while(j<n)
        {
            um[nums[j]]++;
            if(um.size()==k)
            {
                if(j>0 and nums[j]==nums[j-1])
                    count += v[j-1];
                else
                    sliding_window_count(nums,um,k,count,j,v,i,current);
            }
            else if(um.size()>k)
            {

                while(um.size()>k)
                {
                    um[nums[i]]--;
                    if(um[nums[i]]==0)
                        um.erase(nums[i]);
                    i++;
                }
                current=-1;
                sliding_window_count(nums,um,k,count,j,v,i,current);
            }
            j++;
        }
        return count;
    }
};