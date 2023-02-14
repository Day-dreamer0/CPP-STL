#include <iostream>
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
// note ^ has right associativity and others have left associativity
int prec(char s)
{
    if(s=='^') return 3;
    else if(s=='*' or s=='/') return 2;
    else if(s=='+' or s=='-') return 1;
    else return -1;
}

vector<char> infix(string s)
{
    vector<char> v;
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='A' and s[i]<='Z')
            v.pb(s[i]);
        else if(s[i]=='(')
        st.push(s[i]);
        else if(s[i]==')')
        {
            while(st.top()!='(')
            {
                char temp=st.top();
                v.pb(temp);
                st.pop();
            }
            st.pop();
        }
        else
        {
            if(st.empty())
                st.push(s[i]);
            else if(prec(s[i])<=prec(st.top()))
            {
                if(s[i]=='^')
                st.push(s[i]);
                else
                {
                    while(!st.empty() and (prec(s[i])<=prec(st.top())))
                    {
                        v.pb(st.top());
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    while(!st.empty())
    {
        if(st.top()!='(' and st.top()!=')')
        v.pb(st.top());
        st.pop();
    }
    
    return v;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    vector<char> result=infix(s);
	    for(auto x:result)
	    cout<<x;
	    cout<<"\n";
	}
	return 0;
}
