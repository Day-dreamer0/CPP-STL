#include<bits/stdc++.h>
using namespace std;

// 2 QUES:-
// a. next greater element (use stack)
vector<int> next_greater_element(vector<int> &v)
{
	stack<int> s;
	int n=v.size();
	vector<int> res(n);
	res[n-1]=-1;
	s.push(v[n-1]);
	for(int i=v.size()-2;i>=0;i--)
	{
		while(!s.empty() and v[i]>=s.top())
			s.pop();
		if(!s.empty())
			res[i]=s.top();
		else
			res[i]=-1;
		s.push(v[i]);
	}
	return res;
}
// b. next greater element in circular array (use stack by appending array at its end)
vector<int> next_greater_element_circular(vector<int> &v)
{
	copy(v.begin(),v.end(),back_inserter(v));
	vector<int> res=next_greater_element(v);
	return res;
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	vector<int> res=next_greater_element(v);
	vector<int> res_c=next_greater_element_circular(v);
	for(auto i: res)
		cout<<i<<" ";
	cout<<endl;
	for(auto i:res_c)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}