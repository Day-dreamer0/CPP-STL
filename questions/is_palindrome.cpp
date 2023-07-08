// lc-9-> https://leetcode.com/problems/palindrome-number/description/ 
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        vector<int> v;
        while(x)
        {
            v.push_back(x%10);
            x/=10;
        }
        for(int i=0;i<v.size()/2;i++)
        {
            if(v[i]!=v[v.size()-1-i])
                return false;
        }
        return true;
    }
};