/*
I/P=> 3
bat
apple
batman

O/P=> 
apple
batman
bat

SAME QUESTION
https://www.geeksforgeeks.org/sort-an-array-of-strings-lexicographically-based-on-prefix/
*/
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
bool compare(string a, string b)
{
	if(a.compare(0,b.size(),b)==0 or b.compare(0,a.size(),a)==0)
		return a.size()>b.size();
	return a<b;
}
bool comp(string a, string b)
{
	auto p=mismatch(a.begin(),a.end(),b.begin());
	if(p.first==a.end())
	{
		return false;
	}
	else if(p.second==b.end())
	{
		return true;
	}
	return a<b;
}
int main()
{
	int n;
	cin>>n;
	vector<string> v;
	string temp;
	for(int i=0;i<n;++i)
	{
		cin>>temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<n;++i)
	{
		cout<<v[i]<<endl;
	}
	return 0;
}