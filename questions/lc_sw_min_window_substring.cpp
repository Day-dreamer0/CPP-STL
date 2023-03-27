// lc-> https://leetcode.com/problems/minimum-window-substring/description/
class Solution {
public:
    string minWindow(string s, string t) {
        string res="";
        if(t.size()>s.size())
            return res;

        int j=0,i=0,count;
        unordered_map<char,int> total; //char,count
        for(auto i:t)
        total[i]++;
        count=total.size();
        int n=s.size();
        int l=INT_MIN,r=INT_MIN;
        int mn=INT_MAX;
        while(j<n)
        {       
            if(total.find(s[j])!=total.end())
            {
                total[s[j]]--;
                if(total[s[j]]==0)
                    count--;
            }
            if(count==0)
            {

                if((j-i+1)<mn)
                {
                    mn=(j-i+1);
                    r=j;
                    l=i;
                }
                while(total.find(s[i])==total.end() or (total[s[i]]<0))
                {
                    if (total[s[i]]<0)
                        total[s[i]]++;
                    i++;
                }
                if((j-i+1)<mn)
                {
                    mn=(j-i+1);
                    r=j;
                    l=i;
                }
            }
            j++;
        }

        if(l!=INT_MIN)
        {
            copy(s.begin()+l,s.begin()+r+1,back_inserter(res));
        }
            
        return res;
    }
};