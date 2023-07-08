// GFG-> https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
    vector<int> subsetsum(int arr[], int n, int sum)
    {
        int t[n+1][sum+1];
        memset(t,0,sizeof(t));
        for(int i=0;i<=n;++i)
        {
            t[i][0]=1;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=sum;++j)
            {
                if(arr[i-1]<=j)
                {
                    t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
                }
                else if(arr[i-1]>j)
                {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        vector<int> v;
        for(int j=0;j<=sum/2;++j)
        {
            if(t[n][j])
                v.push_back(j);
        }
        return v;
    }
    
	int minDifference(int arr[], int n)  { 
	    int t=0;
	    for(int i=0;i<n;++i)
	    {
	        t+=arr[i];
	    }
	    vector<int> v = subsetsum(arr,n,t);
	    return abs(t-2*v[v.size()-1]);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];
        
	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends