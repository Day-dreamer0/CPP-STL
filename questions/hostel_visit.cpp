// lc -> https://leetcode.com/problems/k-closest-points-to-origin/description/
#include<bits/stdc++.h>
using namespace std;

class check{
public:
    bool operator () (const pair<int,int> &a, const pair<int,int> &b) {
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
    }
};
class Solution {
public:
    
    int distance(int x,int y)
    {
        return x*x + y*y;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int> >, check > max_pq;
        for(int i=0;i<points.size();i++)
        {
            int x = points[i][0],y=points[i][1];
            int d = distance(x,y);
            if(max_pq.size()<k)
                max_pq.push({d,i});
            else if(d<max_pq.top().first)
            {
                max_pq.pop();
                max_pq.push({d,i});
            }
        }
        vector<vector<int> > v;
        while(!max_pq.empty())
        {
            v.push_back(points[max_pq.top().second]);
            max_pq.pop();
        }
        return v;
    }
};


int main()
{
	int n,k;
	cin>>n>>k;
	priority_queue<int, vector<int> > max_pq;
	while(n--)
	{
		int q;
		cin>>q;
		if(q==1)
		{
			int x,y;
			cin>>x>>y;
			int d = x*x + y*y;
			// float sqrt_d=sqrt(d);
			if(max_pq.size()<k)
				max_pq.push(d);
			else if(max_pq.top()>d)
			{
				max_pq.pop();
				max_pq.push(d);
			}
		}
		else if(q==2)
		{
			if(max_pq.size()==k)
				cout<< max_pq.top()<<endl;
			else
			{
				cout<<"No Kth answer exists!!!"<<endl;
			}
		}
	}
	return 0;
}