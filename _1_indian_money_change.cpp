#include<bits/stdc++.h>
#define pb push_back
using namespace std;
bool compare(int a, int b)
{
	return a<b;
}
vector<int> findmin(vector<int> &v, int m)
{
	vector<int> res;
	while(m>0)
	{
		auto it=lower_bound(v.begin(),v.end(),m);
		if(*it>m and *it>v[0])
			it--;
		res.pb(*it);
		int val=*it;
		m=m-val;
	}
	return res;
}
int main()
{
	int money;                      
	cin>>money;
	// cout<<money;
	vector<int> v={1,2,5,10,20,50,100,200,500,2000};
	vector<int> res=findmin(v,money);
	for(int i=0;i<res.size();++i)
		cout<<res[i]<<" ";
	return 0;
}
