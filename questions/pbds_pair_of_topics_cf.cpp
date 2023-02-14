#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define lli long long int
using namespace __gnu_pbds;
// custom comparator function only works in struct or class in pbds
// struct cmp
// {
// 	bool operator () (const int a, const int b) const 
// 	{
// 		cout<<a<<",,"<<b<<endl;
// 	return a+b>0;
// 	};
// };

/*
IP ->
5
4 8 2 6 2
4 5 4 1 3

OP ->7
*/
typedef tree<
pair<int,int>,
null_type,
less<pair<int,int> >,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;++i)
	{
		cin>>b[i];
	}
	lli result=0;
	ordered_set s;
	for(int i=0;i<n;++i)
	{
		int val=b[i]-a[i];
		if(i>0)
		{
			// cout<<"c"<<i<<endl;
			result+=(s.size()-s.order_of_key(make_pair(val,INT_MAX)));
		}
		// s.insert(make_pair(-val,i));
		//OR just as i is always going to be unique
		int ord=s.order_of_key({-val,INT_MAX});
		auto value= s.find_by_order(ord-1);
		cout<< value->first<<","<<value->second<<endl;
		if(i>0 and value->first== -val)
			s.insert(make_pair(-val,value->second+1));
		else
			s.insert(make_pair(-val,0));
	}
	cout<<result;
	cout<<endl;
	

        return 0;
	return 0;
}