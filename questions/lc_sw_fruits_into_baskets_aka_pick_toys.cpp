// lc-> https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int n=fruits.size();
        unordered_map<int,int> um; // char,count
        int k=2;
        int mx=0;
        while(j<n)
        {
            um[fruits[j]]++;
            if(um.size()<=k)
            {
                mx=max(mx,j-i+1);
                j++;
            }
            // if(um.size()<k)
            // j++;
            // else if(um.size()==k)
            // {
            //     mx=max(mx,j-i+1);
            //     j++;
            // }
            else if(um.size()>k)
            {
                while(um.size()>k)
                {
                    um[fruits[i]]--;
                    if(um[fruits[i]]==0)
                    um.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};