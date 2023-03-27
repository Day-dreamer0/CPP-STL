#include<bits/stdc++.h>
using namespace std;
//M-1 using merging array technique (divide and conquer)
vector<int> merge_two(vector<int> v1, vector<int> v2)
{
	int n=v1.size();
	int m=v2.size();
	vector<int> v;
	int i=0,j=0;
	while(i<n and j<m)
	{
		if(v1[i]<=v2[j])
		{
			v.push_back(v1[i]);
			i++;
		}
		else
		{
			v.push_back(v2[j]);
			j++;
		}
	}
	while(i<n)
	{
		v.push_back(v1[i]);
		i++;
	}
	while(j<m)
	{
		v.push_back(v2[j]);
		j++;
	}
	return v;
}
vector<int> merge_array(vector<vector<int> > v,int start,int end)
{
	if(start==end)
	{
		return v[start];
	}
	else if(start+1==end)
	{
		return merge_two(v[start],v[end]);
	}
	else 
	{
		int mid=start+(end-start)/2;
		vector<int> v1=merge_array(v,start,mid);
		vector<int> v2=merge_array(v,mid+1,end);
		return merge_two(v1,v2);
	}
}
int main()
{
	int n;
	cin>>n;
	int k;
	cin>>k;
	vector<vector<int> > v(k);
	int temp,j;
	for(j=0;j<k;j++)
	{
		for(int i=0;i<n;++i)
		{
			cin>>temp;
			v[j].push_back(temp);
		}
	}
	vector<int> res=merge_array(v,0,k-1);
	for(auto it:res)
		cout<<it<<" ";
	return 0;
}

//M-2 using min priority_queue
class Solution
{
    public:
    //Function to merge k sorted arrays.
    // greater works as less in pq
    // pair of pair signifies element,{array_number, element_no}
    struct comp {
        bool operator() (const pair<int,pair<int,int> >a, const pair<int, pair<int,int> >b) const{
            return a.first>b.first;
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >, comp > mpq;
        for(int i=0;i<K;i++)
        mpq.push({arr[i][0],{i,0}});
    
        vector<int> res;
        while(!mpq.empty())
        {
            pair<int,pair<int,int> > p=mpq.top();
            mpq.pop();
            res.push_back(p.first);
            int index=p.second.second+1;
            int arr_num=p.second.first;
            if(index<arr[arr_num].size())
                mpq.push({arr[arr_num][index],{arr_num,index}});
        }
        return res;
    }
};