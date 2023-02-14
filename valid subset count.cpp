#include<bits/stdc++.h>
using namespace std;
bool isSubsetSum(int set[], int n, int sum)
{

    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
  

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;
  
    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }
  
    /*   // uncomment this code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", subset[i][j]);
       cout <<"\n";
     }*/
  
    return subset[n][sum];
}
int subsetsum(vector<int> v)
{
	int n=v.size();
	int max_val=*max_element(v.begin(),v.end());
	int m = (1 << (int)(log2(max_val) + 1)) - 1;
	int sum=sum()
	int dp[n][m][];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++)
		dp[0][a[i]]=1;

	for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            if((dp[i-1][j]!=0) and (dp[i-1][j]&a[i]==0))
            	dp[i][j]=dp[i-1][j]+1;

}
int subsetXOR(int arr[], int n)
{

    int max_ele = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max_ele)
            max_ele = arr[i];
 
    int m = (1 << (int)(log2(max_ele) + 1)) - 1;

    int dp[n + 1][m + 1];
 
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 0;
 
    dp[0][0] = 1;
 

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j]
                = dp[i - 1][j] + dp[i - 1][j ^ arr[i - 1]];
     return arr[n-1][m-1];
}
int main()
{

}