class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int> > min_pq;
    int cs=0;
    int k;
    KthLargest(int k, vector<int>& nums) {
        //**********************
        this->k=k;
        for(int i=0;i<nums.size();++i)
        {
            if(cs<k)
            {
                min_pq.push(nums[i]);
                cs++;
            }
            else
            {
                if(nums[i]>min_pq.top())
                {
                    min_pq.pop();
                    min_pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(cs<k)
        {
            min_pq.push(val);
            cs++;
        }
        else
        {
            if(val>min_pq.top())
            {
                min_pq.pop();
                min_pq.push(val);
            }
        }
        return min_pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */