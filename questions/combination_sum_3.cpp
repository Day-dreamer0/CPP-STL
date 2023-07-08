// LC-> https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
public:
    // this question is similar to another coin change the with only difference of array number there is was given as input here it is fixed ie 1 to 9
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > t(k+1,vector<int> (n+1,0)); //t[k+1][target+1];
        map<pair<int,int>, set<set<int> > >m;
        for(int j=0;j<n+1;++j)
        {
            t[0][j]=0;
            //no matching function for call to 'make_pair'
            // m.insert(make_pair({0,j},vector<vector<int> > {})); gives error
            m.insert(make_pair(make_pair(0,j),set<set<int> > {}));
        }
        for(int i=0;i<k+1;++i)
        {
            if(i==0)
                t[i][0]=1; //0 coin user krke 0 target achieve ho sakda
            else
                t[i][0]=0;
            // no matching function for call to 'make_pair'
            // m.insert(make_pair({i,0},vector<vector<int> > {}));
            pair<int,int> key(i,0); //OR key ={i,0};
            m.insert(make_pair(key,set<set<int> > {}));
        }
        // for(int i=1;i<k+1;++i)
        // {
        //     for(int j=1;j<n+1;++j)
        //     {
        //         m.insert(make_pair(make_pair(i,j),set<set<int> > {}));
        //     }
        // }
        for(int i=1;i<k+1;++i)
        {
            for(int j=1;j<n+1;++j)
            {
                for(int l=1;l<10;++l)
                {
                    if(l<=j)
                    {
                        // int check = t[i-1][j-l];
                        int check = m[{i-1,j-l}].size();
                        // not because we need exactly k no.
                        // if(check==0 and j-l==0 and check+1==i) reduntant
                        if(j-l==0 and i==1)
                        {
                            set<int> p;
                            p.insert(l);
                            m[{i,j}].insert(p);
                        }
                        if(check)
                        {
                            for(auto temp_set:m[{i-1,j-l}])
                            {
                                // bool repeat=false;
                                // for(auto i:temp_vec)
                                //     if(i==l)
                                //     {
                                //         repeat=true;
                                //         break;
                                //     }
                                // if(!repeat)
                                // {
                                    temp_set.insert(l);
                                    if(temp_set.size()==i)
                                        m[{i,j}].insert(temp_set);
                                // }
                            }
                        }
                    }
                }
            }
        }
        vector<vector<int> > result;
        for(auto temp_set:m[{k,n}])
        {
            vector<int> v(temp_set.begin(),temp_set.end());
            result.push_back(v);
        }
        return result;
        // return m[{k,n}];
    }
};