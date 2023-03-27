// LINTCODE-> https://www.lintcode.com/problem/386/
// I/P-> eceba
// 3
// O/P-> 4
//LC-> FRUIT INTO BASKETS
//LINTCODE SOLUTION
#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstringKDistinct(string &s, int k) {
    int mx=INT_MIN;
    int i=0,j=0,n=s.length(),count=0;
    unordered_map<char,int> um;
    while(j<n)
    {
        um[s[j]]++;
        if(um[s[j]]==1)
            count++;
        if(count<=k)
        {
            mx=max(mx,j-i+1);
            j++;
        }
        else if(count>k)
        {
            while(count>k)
            {
                um[s[i]]--;
                if(um[s[i]]==0)
                    count--;
                i++;
            }
            mx=max(mx,j-i+1);
            j++;
        }
    }
    if(mx==INT_MIN)
        mx=0;
    return mx;
}
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<< lengthOfLongestSubstringKDistinct(s,k);
    return 0; 
}

//LEETCODE SOLUTION
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