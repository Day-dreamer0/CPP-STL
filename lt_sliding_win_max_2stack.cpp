class Solution {
public:
    void insert(stack<pair<int,int> > &s1, int val)
    {
        if(s1.empty())
        {
            s1.push({val,val});
        }
        else
        {
            s1.push({val,max(val,s1.top().second)});
        }
    }
    void delete_val(stack<pair<int,int> > &s1, stack<pair<int,int> > &s2)
    {
        if(s2.empty())
        {
           while(!s1.empty())
           {
               int val=s1.top().first;
               insert(s2,val);
               s1.pop();
           }
        }
        s2.pop();
    }
    int max_val(stack<pair<int,int> >&s1,stack<pair<int,int> >&s2)
    {
        int maxx=-100000;
        if(!s1.empty())
        {
            maxx=max(maxx,s1.top().second);
        }
        if(!s2.empty())
        {
            maxx=max(maxx,s2.top().second);
        }
        return maxx;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        stack<pair<int,int> > s1,s2;
        for(int i=0;i<k-1;i++)
            insert(s1,nums[i]);
        for(int i=k-1;i<nums.size();i++)
        {
            if(i-k>=0)
                delete_val(s1,s2);
            insert(s1,nums[i]);
            v.push_back(max_val(s1,s2));
        }
        return v;
    }
    
};