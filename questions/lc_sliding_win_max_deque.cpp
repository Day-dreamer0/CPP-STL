class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        deque<int> q(k);
        for(int i=0;i<k;i++)
        {
            while(!q.empty() and nums[i]>=nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
            
        for(int i=k;i<nums.size();i++)
        {
            v.push_back(nums[q.front()]);
            while(!q.empty() and q.front()<=(i-k))
                q.pop_front();
            while(!q.empty() and nums[i]>=nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        v.push_back(nums[q.front()]);
        return v;
    }
};