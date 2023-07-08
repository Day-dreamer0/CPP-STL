// GFG -> https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    bool subsetsum(vector<int>arr, int n,int sum, int** t)
    {
        if(n==0 or sum==0)
        {
            return 0;
        }
        if(arr[n-1]==sum)
        {
            return 1;
        }
        if(t[n][sum]!=-1)
            return t[n][sum];
        if(arr[n-1]>sum)
        {
            return t[n][sum]=subsetsum(arr,n-1,sum,t);
        }
        else if(arr[n-1]<sum)
        {
            return t[n][sum]=subsetsum(arr,n-1,sum,t) or subsetsum(arr,n-1,sum-arr[n-1],t);
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int **t= new int*[arr.size()+1];
        for(int i=0;i<arr.size()+1;++i)
        {
            t[i] = new int[sum+1];
        }
        // int t[100+1][sum+1];

        for(int j=0;j<=sum;++j)
            t[0][j]=0;

        for(int i=0;i<=arr.size();++i)
            t[i][0]=1;

        int n=arr.size();

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
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends