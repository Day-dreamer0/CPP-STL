// GFG-> https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    {
        int t[n+1][W+1];
        for(int i=0;i<=n;++i)
            t[i][0]=0;
        for(int j=0;j<=W;++j)
        {
            t[0][j]=0;
        }
        
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=W;++j)
            {
                if(wt[i-1]<=j)
                {
                    t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
                }
                else
                    t[i][j]=t[i-1][j];
            }
        }
        return t[n][W];
    }
    
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
    return 0;
}
// } Driver Code Ends