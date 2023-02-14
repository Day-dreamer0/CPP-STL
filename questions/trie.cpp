/*
I/P -> 5
test
hello
hell
he
she

O/P-> 1
1
0
1
1
0
*/
#include<bits/stdc++.h>
using namespace std;
// can't use class trie if importing pbds libraries due to ambiguity
class triee
{
public:
	char data;
	triee *ptr[26];
	bool isterminal;
	triee()
	{
		data='0';
		isterminal=false;
		memset(ptr,0,sizeof(ptr));
	}
	triee(char d)
	{
		data=d;
		isterminal=false;
		//might give issue in some compilers where 0 doesn't indicate NULL
		// better option to declare each one of them NULL using loop
		memset(ptr,0,sizeof(ptr));
	}

	bool search(triee * root, string s)
	{
		if(root==NULL)
			return false;
		root=root->ptr[s[0]-'a'];
		if(root!=NULL)
		{
			// s=s.substr(1) then search(root,s) and s.length()==0;
			// in are word ar exists but isterminal is false
			if((s.length()-1)==0)
				return root->isterminal;
			return search(root,s.substr(1));
		}
		return false;
	}
	void insert(triee * root,string s)
	{
		//RISKY METHOD with double pointer
		// if(root==NULL)
		// {
		// 	// trie obj;
		// 	// root= &obj;
		// 	root= new trie;
		// }
		// trie ** currnode=&(root->ptr[s[0]-'a']);
		// trie * prev;
		// for(int i=0;i<s.length();++i)
		// {
		// 	if(*currnode==NULL)
		// 	{
		// 		*currnode= new trie(s[i]);
		// 		// cout<<currnode->data<<endl;
		// 	}
		// 	if(i<(s.length()-1))
		// 	{
		// 		trie * tempnode = *currnode;
		// 		// cout<<tempnode->data;
		// 		currnode=&(tempnode->ptr[s[i+1]-'a']);
		// 	}
		// }
		// prev=*currnode;
		// // cout<<currnode->data<<endl;
		// prev->isterminal=true;
		// return root;
		if(root==NULL)
		{
			// trie obj;
			// root= &obj;
			root= new triee;
		}
		triee * currnode=root;
		
		for(int i=0;i<s.length();++i)
		{
			if(currnode->ptr[s[i]-'a']==NULL)
			{
				currnode->ptr[s[i]-'a']= new triee(s[i]);
			}

			currnode=currnode->ptr[s[i]-'a'];
		}
		currnode->isterminal=true;
		// return root;
	}
	triee * delete_node(triee* root,string s)
	{
		if(s.length()>0)
			root->ptr[s[0]-'a']=delete_node(root->ptr[s[0]-'a'],s.substr(1));
		else if(s.length()==0)
		{
			root->isterminal=false;
		}
		for(int i=0;i<26;++i)
			if(root->ptr[i]!=NULL or root->isterminal==true)
				return root;
		return NULL;
	}
};
int main()
{
	string s;
	int n;
	cin>>n;
	triee * root=new triee;
	for(int i=0;i<n;++i)
	{
		cin>>s;
		root->insert(root,s);
	}
	if(root!=NULL)
	cout<<root->search(root,"she")<<endl;
	cout<<root->search(root,"he")<<endl;
	cout<<root->search(root,"hel")<<endl;
	cout<<root->search(root,"hell")<<endl;
	cout<<root->search(root,"hello")<<endl;
	cout<<root->search(root,"hella")<<endl;
	if(root->search(root,"she"))
		cout<<"we are in"<<endl;
		root=root->delete_node(root,"she");

	cout<<root->search(root,"she")<<endl;
	// cout<<root->search(root,"he")<<endl;
	// delete root;
	// cout<<root->ptr['s'-'a']->data<<endl;
	// cout<<root->ptr['s'-'a']->ptr['h'-'a']->data<<endl;
	// cout<<root->ptr['s'-'a']->ptr['h'-'a']->ptr['e'-'a']->data<<endl;
	return 0;
}