/*
IP-> 8
1 3 -1 -3 5 3 6 7
3

OP-> 3 3 5 5 6 7 
*/
// LC-> https://leetcode.com/problems/sliding-window-maximum/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
		cin>>v[i];
	int k;
	cin>>k;
	deque<int> q;
	vector<int> res;
	for(int i=0;i<n;++i)
	{
		//create window
		if(i<k)
		{
			while(!q.empty() and v[i]>=v[q.back()])
				q.pop_back();
			q.push_back(i);
		}
		else
		{
			res.push_back(v[q.front()]);
			//check window if front in range of window or not
			while(!q.empty() and q.front()<(i-(k-1)))
				q.pop_front();
			//find the position for ith element
			while(!q.empty() and v[i]>=v[q.back()])
				q.pop_back();
			q.push_back(i);
		}
	}
	res.push_back(v[q.front()]);
	for(int i=0;i<res.size();++i)
		cout<<res[i]<<" ";
	return 0;
}

class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> v;
        deque<int> q(k);
        for(int i=0;i<k;i++)
        {
            while(!q.empty() and nums[i]>=nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
            
        for(int i=k;i<nums.size();i++)
        {
            v.push_back(nums[q.front()]);
            while(!q.empty() and q.front()<=(i-k))
                q.pop_front();
            while(!q.empty() and nums[i]>=nums[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        v.push_back(nums[q.front()]);
        return v;
    }
};

vector<int> maxSlidingWindow(vector<int>&nums,int k)
{
	vector<int>v;
	int i=0,j=0;
	deque<int> dq;
	while(j<nums.size())
	{
		while(!dq.empty() and nums[j]>=dq.front())
			dq.pop_back();
		dq.push_back(nums[j]);
		if(j-i+1<k)
			j++;
		else if(j-i+1==k)
		{
			v.push_back(dq.front());
			if(nums[i]==dq.front())
				dq.pop_front();
			i++;
			j++;
		}
	}
	return v;
}