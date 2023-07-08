// lc-> https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()<=1)
            return points.size();
        sort(points.begin(),points.end(),[] (vector<int> &a, vector<int> &b)
            {return a[1]<b[1];}
            );
        int ans=1,j=0;
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]>points[j][1])
            {
                ans++;
                j=i;
            }      
        }
        return ans;
    }
};