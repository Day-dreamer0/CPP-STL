// ln 928 -> https://www.lintcode.com/problem/928/

class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        int i=0,j=0,n=s.size();
        unordered_map<char,int> um;
        int mx=INT_MIN;
        while(j<n)
        {
            um[s[j]]++;
            if(um.size()<=2)
            {
                mx=max(j-i+1,mx);
            }
            else
            {
                while(um.size()>2)
                {
                    um[s[i]]--;
                    if(um[s[i]]==0)
                        um.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        if(mx==INT_MIN)
            mx=0;
        return mx;
    }
};