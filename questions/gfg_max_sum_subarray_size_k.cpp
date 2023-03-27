// GFG-> https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
// max sum subarray of size k
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        int i=0,j=0;
        long long int sum=0;
        long long int mx=LLONG_MIN;
        while(j<N)
        {
            sum+=Arr[j];
            if(j-i+1<K)
            j++;
            else if(j-i+1==K)
            {
                mx=max(mx,sum);
                sum-=Arr[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};