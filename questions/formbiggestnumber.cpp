class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v(nums.size());
        auto it=nums.begin();
        while(it!=nums.end())
        {
            if(*it !=0)
            break;
            it++;
        }
        if(it==nums.end())
        return "0";
        for(int i=0;i<nums.size();++i)
        {
            v[i]=to_string(nums[i]);
        }
        sort(v.begin(),v.end(),[](string a, string b)
    {
        string X=a.append(b);
        string Y=b.append(a);
        return X>Y;
    });
        string res="";
        for(auto i:v)
        res+=i;
        
        return res;
    }
};