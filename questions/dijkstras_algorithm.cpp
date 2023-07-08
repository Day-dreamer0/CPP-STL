// gfg-> https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
/*IP-> 9 3
1 10 10
1 9 9
1 -8 -8
2
1 7 7
2
1 6 6 
1 5 5
2
OP-> 200
162
98

*/
#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) O(V^2) ie O(N^2)
    {
        vector<int> d(V,INT_MAX);
        // memset(d,INT_MAX,sizeof(d));
        // for(auto j:d)
        // cout<<j<<endl;
        // cout<<endl;
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >min_pq;
        d[S]=0;
        min_pq.push({0,S}); //distance must come first and then node
        while(!min_pq.empty())
        {
            int node=min_pq.top().first;
            int weight=min_pq.top().second;
            min_pq.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                int curr_node=adj[node][i][0];
                int curr_weight=adj[node][i][1];
                if(weight+curr_weight<d[curr_node])
                {
                    d[curr_node]=weight+curr_weight;
                    min_pq.push({d[curr_node],curr_node}); //distance must come first and then node
                }
            }
        }
        return d;
    }
};