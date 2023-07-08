// GFG-> https://practice.geeksforgeeks.org/problems/09b910559335521654aa2909f86f893447d8f5ba/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:


    bool coinchange(int N, int k, int target, vector<int> &coins, vector<vector<int> > &dp)
    {
        if(target==0 and k==0)
            return 1;
        if(N<=0 or k<=0)
            return 0;
        if(dp[k][target]!=-1) 
            return dp[k][target];
        
        if(coins[N-1]<=target)
        {
          return dp[k][target] = coinchange(N,k-1,target-coins[N-1],coins,dp) || coinchange(N-1,k,target,coins,dp);
        }
        else
            return dp[k][target] = coinchange(N-1,k,target,coins,dp);


    }

    bool makeChanges(int N, int k, int target, vector<int> &coins) {
        bool t[k+1][target+1];
        memset(t,0,sizeof(t));
        for(int j=0;j<target+1;j++)
            t[0][j]=0;
        
        for(int i=0;i<k+1;i++)
        {
            if(i==0) //0 coin use krke 0 target ho sakda
            t[i][0]=1;
            else
            t[i][0]=0; //exactly 1 coin, 2 coin, 3 coin... k coin use krke 0 target possible hai? -> nhi
        }
        int j;
        for(int i=1;i<k+1;i++)
        {
            for( j=1;j<target+1;j++)
            {
                t[i][j]=0;
                for(int l=0;l<N;++l)
                {
                    if(coins[l]<=j)
                    {
                       t[i][j] = t[i-1][j-coins[l]];// || t[i-1][j];
                    }
                    if(t[i][j])
                        break;
                }
            }
            if(t[i][j]==0)
                t[i][j] =t[i-1][j];
        }
        return t[k][target];   
        // vector<vector<int> >  dp(k+1,vector<int>(target+1,-1));

        // return coinchange(N,k,target,coins,dp);

        //[100+1][1000+1];
        // memset(dp,0,sizeof(dp));
        // for(int j=0;j<target+1;++j)
        // {
        //     t[0][j]=0;
        // }
        // t[0][0]=1;
        // // for(int i=1;i<k+1;++i)
        // // {
        // //     t[i][0]=1;
        // // }
        // for(int i=1;i<k+1;++i)
        // {
        //     for(int c=0;c<N;++c)
        //     {
        //         for(int j=1;j<target+1;++j)
        //         {
        //             if(coins[c]<=j )
        //             {
        //                 if(t[i-1][j-coins[c]])
        //                     t[i][j]= t[i-1][j-coins[c]];
        //             }

        //         }
        //     }
        // }
        // return t[k][target];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends