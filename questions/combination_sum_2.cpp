// LC -> https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // vector<vector<int> > t(candidates.size()+1,vector<int> (target+1));
        // map<pair<int,int>, vector<vector<int> > > m;
        map<pair<int,int>, set<multiset<int> > > m;
        for(int j=0;j<target+1;++j)
        {
            // t[0][j] = 0;
            m.insert(make_pair(make_pair(0,j),set<multiset<int> > {}));
        }
        for(int i=0;i<candidates.size()+1;++i)
        {
            // t[i][0] = 1;
            m.insert(make_pair(make_pair(i,0),set<multiset<int> > {}));
        }
        for(int i=1;i<candidates.size()+1;++i)
        {
            for(int j=1;j<target+1;++j)
            {
                if(candidates[i-1]<=j)
                {
                    // t[i][j] = t[i-1][j-candidates[i-1]] + t[i-1][j];
                    auto iter = m.find({i-1,j-candidates[i-1]});
                    if(iter!=m.end())
                        m[make_pair(i,j)] = iter->second;
                    if(m[make_pair(i,j)].size()==0 and j-candidates[i-1]==0)
                    {
                        multiset<int> p = {candidates[i-1]};
                        m[{i,j}].insert(p);
                    }
                    else
                    {
                        auto iter = m.find({i,j});
                        if (iter != m.end()) {
                            set<multiset<int> > s;
                            for(const multiset<int> &k:m[{i,j}])
                            {
                                multiset<int> val(k.begin(),k.end());
                                val.insert(candidates[i-1]);
                                s.insert(val);
                            }
                            m.erase({i,j});
                            m[{i,j}]=s;
                        }
                            
                    }
                    for( auto k: m[{i-1,j}])
                        m[{i,j}].insert(k);
                }
                else
                {
                    auto iter = m.find({i-1,j});
                    if(iter != m.end())
                        m[{i,j}] = iter->second;
                }
            }
        }
        // set<multiset<int> > s;
        // for(auto v:m[{candidates.size(),target}])
        // {
        //     multiset<int> temp_set;
        //     for(auto val:v)
        //         temp_set.insert(val);
        //     s.insert(temp_set);
        // }
            

        vector<vector<int> > result;
        for(auto v:m[{candidates.size(),target}])
        {
            vector<int> temp_vec;
            for(auto val:v)
                temp_vec.push_back(val);
            result.push_back(temp_vec);
        }
            // result.push_back(v);
        return result;
        // return vector<vector<int> > v(s);
        // return m[{candidates.size(),target}];
        
    }
};