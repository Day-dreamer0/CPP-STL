// GFG -> https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    bool subsetsum(int arr[],int n, int sum)
    {
        int t[n+1][sum+1];
        for(int j=0;j<sum+1;++j)
        {
            t[0][j]=0;
        }
        for(int i=0;i<n+1;++i)
        {
            t[i][0]=1;
        }
        for(int i=1;i<n+1;++i)
        {
            for(int j=1;j<sum+1;++j)
            {
                if(arr[i-1]>j)
                {
                    t[i][j]=t[i-1][j];
                }
                else if(arr[i-1]<=j)
                {
                    t[i][j]=t[i-1][j] || t[i-1][j-arr[i-1]];
                }
            }
        }
        return t[n][sum];
    }
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;++i)
        {
            sum+=arr[i];
        }
        if(sum&1)
            return 0;
        else
        {
            return subsetsum(arr,N,sum/2);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends