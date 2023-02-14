/*
IP-> 7
2 73
2 83
2 43
1
1
2 16
2 48

OP-> 43
83

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<int> s;
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int q,val;
		cin>>q;
		if(q==1)
		{
			if(!s.empty())
			{
				cout<<s.top()<<endl;
				s.pop();
			}
			else
				cout<<"No code"<<endl;
		}	
		else
		{
			cin>>val;
			s.push(val);
		}
	}
	return 0;
}