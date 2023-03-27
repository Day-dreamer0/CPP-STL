//Local question of coding blocks easy, order doesn't matter at same column, challenge
// is to convert array to level order tree
// TC O(NlogN) where N is number of nodes in the tree

https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/

#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTreeLevelWise()
{

    int d;
    cin >> d;

    node *root = new node(d);
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

        node *f = q.front();
        q.pop();
        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            f->left = new node(c1);
            q.push(f->left);
        }
        if (c2 != -1)
        {
            f->right = new node(c2);
            q.push(f->right);
        }
    }
    return root;
}

void verticalOrderPrint(node *root, map<int, vector<int>> &m, int d = 0)
{
    if (root == NULL)
    {
        return;
    }
    m[d].push_back(root->data);
    verticalOrderPrint(root->left, m, d - 1);
    verticalOrderPrint(root->right, m, d + 1);
}

int main()
{
    int levels;
    cin >> levels;
    node *root = buildTreeLevelWise();

    map<int, vector<int>> m;

    verticalOrderPrint(root, m);
    for(auto itr : m) {
        for(auto x : itr.second) {
            cout << x << " ";
        }
    }
    

    return 0;
}

//GFG question, O(NlogN) solution using map,recursion
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    bool comp(pair<int,int> a, pair<int,int> b){
        if(a.first==b.first)
        {
            return true;
        }
        return a.first<b.first;
    }
    void traverse(Node *root,map<int,vector<pair<int,pair<int,int> > > > &v,int level ,int col)
    {
        if(root==NULL)
        return;
        int n=v[col].size();
        v[col].push_back({root->data,{level,n}});
        traverse(root->left,v,level+1,col-1);
        traverse(root->right,v,level+1,col+1);
        return;
    }
    vector<int> verticalOrder(Node *root)
    {
        map<int,vector<pair<int,pair<int,int> > > >v;
        traverse(root,v,0,0);
        vector<int> res;
        for(auto it=v.begin();it!=v.end();it++)
        {
            sort(it->second.begin(),it->second.end(),[] (pair<int,pair<int,int> >a, pair<int,pair<int,int> > b){
        if(a.second.first==b.second.first)
        {
            return a.second.second<b.second.second;
        }
        return a.second.first<b.second.first;
    });
            for(auto it2=it->second.begin();it2!=it->second.end();it2++)
            res.push_back(it2->first);
            //copy(it->second.begin(),it->second.end(),back_inserter(res));
        }
        return res;
    }
};

// GFG O(N) solution using unordered_map,BFS

void printVerticalOrder(Node* root)
{

    if (!root)
        return;
    unordered_map<int, vector<int> > m;
    int hd = 0;

    queue<pair<Node*, int> > q;
    q.push({ root, hd });
 

    int mn = 0, mx = 0;
    while (q.size() > 0) {
 

        pair<Node*, int> temp = q.front();
        q.pop();
        hd = temp.second;
        Node* node = temp.first;
 

        m[hd].push_back(node->key);
 
        if (node->left)
            q.push({ node->left, hd - 1 });
        if (node->right)
            q.push({ node->right, hd + 1 });

        if (mn > hd)
            mn = hd;
        else if (mx < hd)
            mx = hd;
    }

    for (int i = mn; i <= mx; i++) {
        vector<int> tmp = m[i];
        for (int j = 0; j < tmp.size(); j++)
            cout << tmp[j] << " ";
        cout << endl;
    }
}

//Leetcode solution in O(nlogn)
class Solution {
public:
//map<col,map<level,vector<value>>>
    void traverse(TreeNode* root,map<int,map<int,multiset<int> > > &mv,int level,int col)
    {
        if(root==NULL)
        return ;
        mv[col][level].insert(root->val);
        traverse(root->left,mv,level+1,col-1);
        traverse(root->right,mv,level+1,col+1);
        return;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int> > > mv;
        traverse(root,mv,0,0);
        vector<vector<int> > v;
        for(auto it=mv.begin();it!=mv.end();it++)
        {
            // it->second.begin(),it->second.end()
            vector<int> temp;
            for(auto it2=it->second.begin();it2!=it->second.end();it2++)
            {
                vector<int> temp2(it2->second.begin(),it2->second.end());
                copy(temp2.begin(),temp2.end(),back_inserter(temp));
            }
            v.push_back(temp);
        }
        return v;
    }
};
