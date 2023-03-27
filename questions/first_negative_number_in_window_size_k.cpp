// GFG-> first -ve number in every subarray window of size k in an array
// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

// M-1
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) 
{
    vector<long long int> v;
    queue<int> q;
    long long int i=0,j=0;
    while(j<N)
    {
        if(A[j]<0)
        q.push(A[j]);
        if(j-i+1<K)
        j++;
        else if(j-i+1==K)
        {
            if(!q.empty())
                v.push_back(q.front());
            else
                v.push_back(0);
            if(A[i]==q.front())
                q.pop();
            i++;
            j++;
        }
    }
    return v;
}

// M-2
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        vector<long long int> v;
        queue<int> q;
        long long int i=0,j=0;
        while(j<N)
        {
            if(A[j]<0)
            q.push(j);
            if(j-i+1<K)
            j++;
            else if(j-i+1==K)
            {
                if(!q.empty())
                    v.push_back(A[q.front()]);
                else
                    v.push_back(0);
                i++;
                while(!q.empty() and q.front()<i)
                    q.pop();
                j++;
            }
        }
        return v;
 }