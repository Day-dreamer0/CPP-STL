/*IP->forxxorfxdofr
for

OP->0123
*/
// LC-> https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/915389776/
// GFG-> https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

// GFG SOLUTION  here count is needed
#include<bits/stdc++.h>
using namespace std;
bool compare(int ch1[],int ch2[])
{
        for(int i=0;i<26;++i)
        if(ch1[i]!=ch2[i])
        return false;
        return true;
}
int search(string pat, string txt) {
	   if(pat.length()<txt.length())
	   return search(txt,pat);
	   
	   int i=0,j=0;
	   int ch1[26]={0},ch2[26]={0};
	   int k=txt.length(),n=pat.length(),count=0;
	   for(i=0;i<k;++i)
	   ch1[txt[i]-'a']++;
	   i=0;
	   while(j<n)
	   {
	       ch2[pat[j]-'a']++;
	       if(j-i+1<k)
	       		j++;
	       else if((j-i+1)==k)
	       {
	           if(compare(ch1,ch2))
	           		count+=1;
	           ch2[pat[i]-'a']--;
	           i++;
	           j++;
	       }
	   }
	   return count;
	}
int main()
{
	string s1,s2;
	cin>>s1>>s2;
	cout<< search(s1,s2);
	return 0;
}

// LEETCODE SOLUTION here starting point of all found anagrams needed
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char,int> um;
        for(int i=0;i<p.length();i++)
            um[p[i]]++;

        int count=um.size();
        int n=s.length(),k=p.size();
        int i=0,j=0;
        while(j<n)
        {
            if(um.find(s[j])!=um.end())
            {
                um[s[j]]--;
                if(um[s[j]]==0)
                count--;
            }
            if(j-i+1<k)
            j++;
            else if(j-i+1==k)
            {
                if(count==0)
                    res.push_back(i);
                if(um.find(s[i])!=um.end())
                {
                    um[s[i]]++;
                    if(um[s[i]]==1)
                    count++;
                }
                i++;
                j++;
            }
        }
        return res;
    }
};