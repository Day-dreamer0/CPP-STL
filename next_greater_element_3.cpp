#include<bits/stdc++.h>
using namespace std;
//M-1 O(nlogn)
class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int m=s.size();
        stack<char> k;
        k.push(m-1);
        int check=-1,index=-2;
        int i;
        for( i=m-2;i>=0;--i)
        {
            while(!k.empty() and s[i]>=s[k.top()])
            k.pop();
            if(!k.empty())
            {
                check=s[k.top()];
                index=k.top();
                break;
            }
            k.push(i);
        }
        if(check==-1 and index==-2)
        return -1;
        else
        {
            sort(s.begin()+i+1,s.end());
            int ind=upper_bound(s.begin()+i+1,s.end(),s[i])-s.begin();
            swap(s[ind],s[i]);
            sort(s.begin()+i+1,s.end());
        }

        long long int val=stoll(s);
        if(val>INT_MAX )
        return -1;
        return val;
    }
};

//M-2 O(n)
class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        if(next_permutation(s.begin(),s.end()))
        {
            long long int val=stoll(s);
            if(val>INT_MAX)
            return -1;
            return val;
        }
        return -1;
    }
};

//M-3 O(n)
class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int m=s.size();
        stack<int>k;
        k.push(m-1);
        int i,index=-1;
        for(i=m-2;i>=0;--i)
        {
            while(!k.empty() and s[i]>=s[k.top()])
            k.pop();
            if(!k.empty())
            {
                for(int j=m-1;j>i;--j)
                {
                    if(s[j]>s[i])
                    {
                        index=j;
                        break;
                    } 
                }
                break;
            }
            k.push(i);
        }
        if(index==-1) return index;
        swap(s[i],s[index]);
        reverse(s.begin()+i+1,s.end());
        long long int val=stoll(s);
        if(val>INT_MAX)
        return -1;
        return val;
    }
};