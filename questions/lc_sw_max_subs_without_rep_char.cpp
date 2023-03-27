//LC-> https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int n=s.size(),mx=0;
        unordered_map<char,int> um;
        while(j<n)
        {
            um[s[j]]++;
            if(um[s[j]]<=1)
            {
                mx=max(mx,j-i+1);
                j++;
            }
            else if(um[s[j]]>1)
            {
                while(um[s[j]]!=1)
                {
                    um[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};