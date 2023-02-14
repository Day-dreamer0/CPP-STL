//leetcode ->  Find First and Last Position of Element in Sorted Array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it=lower_bound(nums.begin(),nums.end(),target);
        vector<int> v;
        if(it==nums.end() or *it!=target)
        {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        
        auto it2=upper_bound(nums.begin(),nums.end(),target);
        v.push_back(it-nums.begin());
        v.push_back((it2-nums.begin())-1);
        return v;
    }
};