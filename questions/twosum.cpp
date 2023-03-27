//m-1 hashing O(n) using unordered map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um;
        vector<int> res(2);
        int n=nums.size();
        //don't store all the value before hand because only unique values can be 
        //store in unordered_map which will give wrong solution in case of duplicate 
        //values and duplicate value are only needed for one another and not for other values.
        // for(int i=0;i<n;++i)
        // {
        //     if(um[nums[i]])
        //     {
        //         if(nums[i]>=0)
        //         {
        //             um[INT_MAX-nums[i]]=i+1;
        //         }
        //         else
        //         {
        //             um[INT_MIN-nums[i]]=i+1;
        //         }
        //     }
        //     else
        //     {
        //         um[nums[i]]=i+1;
        //     }
        // }
        
        for(int i=0;i<n;++i)
        {
            int temp=target-nums[i];
            if(um[temp])
            {
                res[0]=i;
                res[1]=um[temp]-1;
                break;
            }
            um[nums[i]]=i+1;
        }
        return res;
    }
};

//Two pointer approach O(nlogn)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int> > v(nums.size());
        for(int i=0;i<nums.size();++i)
        v[i]={nums[i],i};
        sort(v.begin(),v.end());
        vector<int> res;
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            if((v[i].first+v[j].first)==target)
            {
                res.push_back(v[i].second);
                res.push_back(v[j].second);
                break;
            }
            else if((v[i].first+v[j].first)>target)
            j--;
            else
            i++;
        }
        return res;
    }
};

//hashing O(n) using unordered map
