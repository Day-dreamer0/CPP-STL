/*
IP-> 8
1 3 -1 -3 5 3 6 7
3

OP-> 3 3 5 5 6 7 
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
		cin>>v[i];
	int k;
	cin>>k;
	deque<int> q;
	vector<int> res;
	for(int i=0;i<n;++i)
	{
		//create window
		if(i<k)
		{
			while(!q.empty() and v[i]>=v[q.back()])
				q.pop_back();
			q.push_back(i);
		}
		else
		{
			res.push_back(v[q.front()]);
			//check window if front in range of window or not
			while(!q.empty() and q.front()<(i-(k-1)))
				q.pop_front();
			//find the position for ith element
			while(!q.empty() and v[i]>=v[q.back()])
				q.pop_back();
			q.push_back(i);
		}
	}
	res.push_back(v[q.front()]);
	for(int i=0;i<res.size();++i)
		cout<<res[i]<<" ";
	return 0;
}