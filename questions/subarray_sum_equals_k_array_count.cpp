class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        
        unordered_map<int,vector<int> > um; //sum,index
        um[0].push_back(-1);
        // unordered_map<int, int > um;
        // um[0]=-1;
        int sum=0,count=0;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            if(um.find(sum-k)!=um.end())
            {
                // count++;
                count+=um[sum-k].size();
                // um[sum].push_back(i);
            }
            // else if(um.find(sum)==um.end())
            // {
                // um[sum]=i;
                um[sum].push_back(i);
            // }
        }
        return count;
    }
};