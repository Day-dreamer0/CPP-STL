// GFG-> https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countsubsets(vector<int> & arr,int n, int sum, int mod)
    {
        vector<vector<int>> t(n+1, vector<int>(sum+1, -1)); 
        //int t[n+1][sum+1];
        // memset(t,0,sizeof(t));
        for(int j=0;j<=sum;++j)
            t[0][j]=0;
        t[0][0]=1;
        long long int cnt=1;
        for(int i=1;i<=n;++i)
        {
            if(arr[i-1]==0)
            {
                cnt*=2;
                cnt=cnt%mod;
                t[i][0] = cnt;
            }
            else
                t[i][0]=t[i-1][0];
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=sum;++j)
            {
                if(arr[i-1]<=j)
                {
                    long long int val= t[i-1][j] + t[i-1][j-arr[i-1]];
                    t[i][j]=(t[i-1][j] + t[i-1][j-arr[i-1]])%mod;
                    // t[i][j] = (t[i-1][j]%mod + t[i-1][j-arr[i-1]]%mod)%mod;
                }
                else
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        long long int total = 0;
        int mod= (int)1e9 + 7;
        for(int i=0;i<arr.size();++i)
            total+=arr[i];
        if( (total + d) & 1)
            return 0;
        int sum = (total + d)/2;
        // int sum2 = (total - d)/2;
        return countsubsets(arr,n,sum,mod);
        //int cnt2 = countsubsets(arr,n,sum2,mod);
        // cout<<cnt1;
        // cout<<endl<<cnt2;
        //return 0;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends