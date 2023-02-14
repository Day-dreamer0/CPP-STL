class Solution {
public:
    bool comp(vector<int> a, vector<int> b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int m=2;
        sort(intervals.begin(),intervals.end(),[](vector<int> a, vector<int> b)
    {
        return a[1]<b[1];
    });
        int count=1;
        int ft=intervals[0][1];
        for(int i=1;i<n;++i)
        {
            if(ft<=intervals[i][0])
            {
                count++;
                ft=intervals[i][1];
            }
        }
        return n-count;
    }
};