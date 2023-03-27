// lc-> https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s, int k) {
    unordered_set<char> us(begin(s),end(s));
    int unique=1,mx=0;
    while(unique<=us.size())
    {
        int i=0,j=0,n=s.size();
        unordered_map<char,int> um;
        int count=0;
        while(j<n)
        {
            um[s[j]]++;
            if(um[s[j]]==k)
                count++; //count of atleast k frequency characters
            if(um.size()==unique)
            {
            	if(count==um.size())
                	mx=max(mx,j-i+1);
            }

            else if(um.size()>unique)
            {
                while(um.size()>unique)
                {
                    if(um[s[i]]==k)
                        count--;
                    um[s[i]]--;
                    if(um[s[i]]==0)
                        um.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        unique++;
    }
    return mx;
}
int main()
{
	string s;
	cin>>s;
	int k;
	cin>>k;
	cout<< longestSubstring(s,k);
	return 0;
}