/*
I/P -> null
*/
/*
O/P -> -10,1,1,1,2,5,100,110,
-10
1
1
2
100
0
0
0

6
8
1
0
7

100
5
100

1,2
1,12
11,1
11,11
15,128
19,2
41,2

1,2
*/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

bool cmp( int a, int b) {
	return a<b;
}
auto comp= [](int a, int b){return a<b;};

class cmpp{
	bool operator() ( int a,  int b)  {
		return a<b;
	}
};
/*
#### TEMPLATE OF PBDS
template<
	  typename Key, // Key type any datatype pair<X,Y>, string, int, float etc...
	  typename Mapped, // Mapped-policy if map needed mapped_type else null_type(if set needed)
	  typename Cmp_Fn = std::less<Key>, // Key comparison functor less<Key>,less_equal<Key>
	  typename Tag = rb_tree_tag, // Specifies which underlying data structure to use: 3 options rb_tree_tag, ov_tree_tag, splay_tree_tag
	  template<
	  typename Const_Node_Iterator,
	  typename Node_Iterator,
	  typename Cmp_Fn_,
	  typename Allocator_>
	  class Node_Update = null_node_update, // A policy for updating node invariants: options null_node_update, tree_order_statistics_node_update
	  typename Allocator = std::allocator<char> > // An allocator type
	  class tree;
*/
typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update> 
ordered_multiset;

typedef tree<
pair<int,int>,
null_type,
less_equal<pair<int,int> >,
rb_tree_tag,
tree_order_statistics_node_update>
pair_ordered_multiset;

//DOESN'T WORK
// tree<pair<int, int>, null_type, decltype(&cmp), rb_tree_tag, tree_order_statistics_node_update> ordered_set(&cmp);
// tree<pair<int, int>, null_type, decltype(cmp)*, rb_tree_tag, tree_order_statistics_node_update> ordered_set(cmp);

tree<pair<int, int>, null_type, cmpp, rb_tree_tag, tree_order_statistics_node_update> orrdered_set;
tree<pair<int, int>, null_type, decltype(comp), rb_tree_tag, tree_order_statistics_node_update> ordered_set(comp);

int main()
{
	ordered_multiset s;
	s.insert(1);
	s.insert(1);
	s.insert(1);
	s.insert(2);
	s.insert(-10);
	s.insert(100);
	s.insert(5);
	s.insert(110);

	for( auto i: s)
		cout<<i<<",";
	cout<<endl;

	cout<< *s.find_by_order(0) <<endl;
	cout<< *s.find_by_order(2) <<endl;
	cout<< *s.find_by_order(3) <<endl;
	cout<< *s.find_by_order(4) <<endl;
	cout<< *s.find_by_order(6) <<endl;
	cout<< *s.find_by_order(8) <<endl;
	cout<< *s.find_by_order(10) <<endl;
	cout<< *s.find_by_order(12) <<endl<<endl;

	cout<<s.order_of_key(10)<<endl;
	cout<<s.order_of_key(1500)<<endl;
	cout<<s.order_of_key(1)<<endl;
	cout<<s.order_of_key(-10)<<endl;
	cout<<s.order_of_key(110)<<endl<<endl;

	cout<< *s.lower_bound(5)<<endl;
	cout<< *s.upper_bound(5)<<endl;
	s.erase(s.upper_bound(5));
	cout<< *s.upper_bound(5)<<endl;
	cout<<endl;


	pair_ordered_multiset pms;
	pms.insert(make_pair(11,1));
	pms.insert(make_pair(11,11));
	pms.insert(make_pair(1,12));
	pms.insert(make_pair(1,2));
	pms.insert(make_pair(41,2));
	pms.insert(make_pair(15,128));
	pms.insert(make_pair(19,2));

	for( auto i: pms)
		cout<<i.first<<","<<i.second<<endl;
	cout<<endl;

	cout<< pms.find_by_order(0)->first<<","<< pms.find_by_order(0)->second<<endl;

	set<int,decltype(&cmp)> sss(&cmp);
	return 0;
}