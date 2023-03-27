//leetcode -> Next Permutations II
//M-1
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> >v;
        v.push_back(nums);
        while(next_permutation(nums.begin(),nums.end()))
        {
            v.push_back(nums);
        }
        return v;
    }
};
//M-2
class Solution {
public:
    void permutations(vector<int>& nums,set<vector<int> > &s,int i)
    {
        if(i==nums.size()-1)
        {
            s.insert(nums);
            return;
        }
        for(int j=i;j<nums.size();++j)
        {
            swap(nums[i],nums[j]);
            permutations(nums,s,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int> > s;
        permutations(nums,s,0);
        vector<vector<int> >v;
        for(auto it=s.begin();it!=s.end();it++)
        v.push_back(*it);
        return v;
    }

//M-3
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     set<vector<int> > s;
    //     s.insert(nums);
    //     vector<int> test=nums;
    //     while(next_permutation(nums.begin(),nums.end()))
    //     {
    //         s.insert(nums);
    //     }
    //     while(prev_permutation(test.begin(),test.end()))
    //     {
    //         s.insert(test);
    //     }
    //     vector<vector<int> > v;
    //     for(auto it =s.begin();it!=s.end();it++)
    //     {
    //         v.push_back(*it);
    //     }
    //     return v;
    // }
};