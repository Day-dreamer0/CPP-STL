/*
I/P=> 79
4
Eve 78
Bob 99
Suzy 86
Alice 86

O/P=> Bob 99
Alice 86
Suzy 86
*/

#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
bool comp(pair<string,int> a, pair<string,int> b)
{
	if(a.second==b.second)
		return a.first<b.first;
	return a.second>b.second;

}
int main()
{
	vector<pair<string,int> > v;
	int x;
	cin>>x;
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		string first;
		int second;
		cin>>first>>second;
		v.push_back({first,second});
	}
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<n and v[i].second>=x;++i)
	{
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}