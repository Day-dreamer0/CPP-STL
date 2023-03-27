/*
IP-> 3
2
40 40
80

5
10 2 6 8 4
10

5
2 20 6 4 8

OP-> 40  40
4  6
4  6
*/
#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
	lli t;
	cin>>t;
	while(t--)
	{
		lli n;
		cin>>n;
		lli a[n];
		for(int i=0;i<n;++i)
		{
			cin>>a[i];
		}
		lli m;
		cin>>m;
		sort(a,a+n);
		int i=0,j=n-1;
		int res1=i,res2=j;
		while(i<j)
		{
			if((a[i]+a[j])==m)
			{
				res1=i;
				res2=j;
				i++;j--;
			}
			else if ((a[i]+a[j])>m)
				j--;
			else
				i++;
		}
		cout<<a[res1]<<"  "<<a[res2]<<endl;
	}
	return 0;
}