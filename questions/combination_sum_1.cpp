// LC-> https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // vector<vector<int> > t(candidates.size()+1,vector<int> (target+1));
        map< pair<int,int>, vector<vector<int> > >m;
        for(int j=0;j<target+1;++j)
        {
            // t[0][j]=0;
            pair<int,int> key ={0,j};
            m.insert(make_pair(key,vector<vector<int> > {}));
        }
        for(int i=0;i<candidates.size()+1;++i)
        {
            // t[i][0]=1;
            pair<int,int> key ={i,0};
            m.insert(make_pair(key,vector<vector<int> > {}));
        }
        // for(int j=1;j<target+1;++j)
        // {
        //     pair<int,int> key(1,j);
        //     if(j%candidates[0]==0)
        //     {
        //         // t[1][j] = 1;
        //         int val =j/candidates[0];
        //         vector<int> p;
        //         while(val--)
        //             p.push_back(candidates[0]);
        //         m.insert(make_pair(key,vector<vector<int> > {p}));
        //     }
        //     else
        //     {
        //         // t[1][j]=0;
        //         m.insert(make_pair(key,vector<vector<int> > {}));
        //     }
        // }
        for(int i=1;i<candidates.size()+1;i++)
        {
            for(int j=1;j<target+1;++j)
            {
                if(candidates[i-1]<=j)
                {

                    // t[i][j] = t[i][j-candidates[i-1]] + t[i-1][j];

                    auto iter = m.find({i,j-candidates[i-1]});
                    if(iter != m.end())
                        m[{i,j}] = iter->second;
                    if(m[{i,j}].size()==0)
                    {
                        if(j-candidates[i-1]==0)
                        {
                            vector<int> p;
                            p.push_back(candidates[i-1]);
                            m[{i,j}].push_back(p);
                        }
                    }     
                    else
                    {
                        for(auto& k: m[{i,j}])
                            k.push_back(candidates[i-1]);
                    }
                    for(auto k: m[{i-1,j}])
                        m[{i,j}].push_back(k);
                }
                else
                {
                    // t[i][j] = t[i-1][j];
                    auto iter = m.find({i-1,j});
                    if(iter != m.end())
                        m[{i,j}] = iter->second;
                }
            }
        }
        // cout<< t[candidates.size()][target];
        return m[{candidates.size(),target}];
    }
};