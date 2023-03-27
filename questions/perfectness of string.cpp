#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int k;
	cin>>k;
	int ca=0,cb=0;
	int i=0,j=0;
	int mx=INT_MIN;
	while(j<s.size())
	{
		s[j]=='a'?ca++:cb++;

		if(ca+k>=cb-k or cb+k>=ca-k)
		{
			mx=max(mx,j-i+1);		
		}
		else
		{
			while(true)
			{
				if(ca+k>=cb-k or cb+k>=ca-k)
					break;

				if(s[i]=='a')
					ca--;
				else
					cb--;
				i++;
			}
		}
		j++;
	}
	cout<<mx;
	return 0;
}