#include<bits/stdc++.h>
using namespace std;
bool comp (const pair<int,int> a, const pair<int,int> b)
{
	// if(a.second==b.second)
	// 	return a.first>b.first;
	return a.second<b.second;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i)
		cin>>a[i];
	unordered_map<int,int> um;
	for(int i=0;i<n;++i)
	{
		um[a[i]]++;
	}
	pair<int,int> p = *max_element(um.begin(),um.end(),comp);
	cout<< p.first<< "  "<<p.second;
	return 0;
}