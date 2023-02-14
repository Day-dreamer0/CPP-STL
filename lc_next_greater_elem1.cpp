class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_map<int,int> v;
        stack<int> s;
        s.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            while(s.top()!=-1 and nums2[i]>=s.top())
                s.pop();
            v[nums2[i]]=s.top();
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();++i)
            nums1[i]=v[nums1[i]];
        return nums1;
    }
};