/*
IP-> 11
2 3 5 1 [4 1 1 1 1 1 -4] ans
5
OP-> 7
*/
//(for only +ve numbers)CN-> https://www.codingninjas.com/codestudio/problems/longest-subarray-with-sum-k_6682399
//(for +ve and -ve numbers) GFG-> https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
//(for +ve and -ve numbers) CN-> https://www.codingninjas.com/codestudio/problems/longest-subarray-with-sum-k_5713505
#include<bits/stdc++.h>
using namespace std;
// BOTH +VE AND -VE
// ON GFG
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<long long int,int> um;
        int j=0;
        um[0]=-1;
        long long int sum=0;
        int mx=INT_MIN;
        while(j<N)
        {
            sum+=A[j];
            // if(sum==K)
            // mx=max(mx,j+1);
            if(um.find(sum-K)!=um.end())
            {
                mx=max(mx,j-um[sum-K]);
            }
            if(um.find(sum)==um.end())
            {
                um[sum]=j;
            }
            j++;
        }
        if(mx==INT_MIN)
            mx=0;
        return mx;
    } 

};
// OR CN
int getLongestSubarray(vector<int>& nums, int k){
    unordered_map<long long int,int> um;
    int j=0,n=nums.size();
    um[0]=-1;
    long long int sum=0;
    int mx=INT_MIN;
    while(j<n)
    {
        sum+=nums[j];
        if(um.find(sum-k)!=um.end())
        {
            mx=max(mx,j-um[sum-k]);
        }
        if(um.find(sum)==um.end())
        {
    		um[sum]=j;
        }
        
        j++;
    }
    if(mx==INT_MIN)
        mx=0;
    return mx;
}
int main()
{
	// int n;
	// cin>>n;
	// int a[n];
	// for(int i=0;i<n;++i)
	// 	cin>>a[i];
	// int k;
	// cin>>k;
	// int max_count=0,mx=INT_MIN,sum;
	// int cum_sum[n];

	// //M-1 easy
	// for(int i=0;i<n;++i)
	// {
	// 	sum=0;
	// 	for(int j=i;j<n;++j)
	// 	{
	// 		sum+=a[j];
	// 		if(sum==k and j-i+1>mx)
	// 		{
	// 			mx=j-i+1;
	// 		}
	// 	}
	// }
	// cout<<mx;

	//M-2 (lengthy)
	// for(int i=0;i<n;++i)
	// {
	// 	if(i)
	// 		cum_sum[i]=cum_sum[i-1]+a[i];
	// 	else
	// 		cum_sum[i]=a[i];
	// }
	// for(int i=1;i<=n;++i) //size
	// {
	// 	int sum=0,count=0,l=0;
	// 	for(int j=0;j<=n-i;++j) //array start point traverse
	// 	{
	// 		count=j+i-1;
	// 			sum=cum_sum[j+i-1];
	// 			// cout<<sum<<endl;
	// 			if(l)
	// 			{
	// 				count-=(l-1);
	// 				sum-=cum_sum[l-1];
	// 			}

	// 		l++;
	// 		cout<<sum<<endl;
	// 		if (sum==k and count>max_count)
	// 			max_count=count;
	// 	}
	// }

	//M-3
	vector<int> v;
	int n,temp;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>temp;
		v.push_back(temp);
	}
	int k;
	cin>>k;
	cout<<getLongestSubarray(v,k);
	return 0;
}

// ONLY +VE
#include <climits>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long int sum=0;
    int i=0,j=0,mx=INT_MIN;
    while(j<a.size())
    {
        sum+=a[j];
        if(sum<k)
        j++;
        else if(sum==k)
        {
            mx=max(mx,j-i+1);
            j++;
        }
        else if(sum>k)
        {
            while(sum>k)
            {
                sum-=a[i];
                i++;
                if(sum==k)
                    mx=max(mx,j-i+1);
            }
            j++;
        }
    }
    return mx;
}

