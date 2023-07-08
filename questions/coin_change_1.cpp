// GFG-> https://practice.geeksforgeeks.org/problems/coin-change2448/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {
        long long int t[N+1][sum+1];
        for(int j=0;j<sum+1;j++)
        {
            t[0][j]=0;
        }
        long long int cnt=0;
        t[0][0]=1;
        for(int i=1;i<N+1;i++)
        {
            if(coins[i]==0)
            {
                cnt*=2;
                t[i][0]=cnt;
            }
            else
            t[i][0]=t[i-1][0];
        }
        
        for(int i=1;i<N+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(coins[i-1]<=j)
                {
                    t[i][j] = t[i-1][j] + t[i][j-coins[i-1]];
                }
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[N][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends