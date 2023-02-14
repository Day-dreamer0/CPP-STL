#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define lli long long int
using namespace __gnu_pbds;
#define END cout<<endl
typedef pair<int,int> pi;

struct student{
    string name;
    float cgpa;
    student(string name, float cgpa){
        this -> name = name;
        this -> cgpa = cgpa;
    }
};

struct compa{
    bool operator () (student x,  student y) {
        return x.name < y.name;
    }
};

struct compar{
bool operator () (const student& x, const student& y) const {
if ( x.name == "Wang" )
            return 1;
if ( y.name == "Wang" )
            return 0;    
 return x.name < y.name;
    }
};

typedef pair< string, pair< int, pair< double, int * > > > myDataType;

struct comp{
    bool operator()(string x, string y)
    {
        return x.length() < y.length();
    }
};

void reverseString(string &s)
{      		         
	if(s.length()<=1)return ; 		 
	swap(s[0],s[s.length()-1]); 		 
	// reverseString(s.begin()+1,s.rbegin()+1); 	   
}
struct Compare
{
    bool operator()(pi const & a, pi const & b)
    {
    	return a.second>b.second;
         // if(a.second < b.second)
         // {
         //    return true;
         // }
         // else if(a.second > b.second)
         // {
         //     return false;
         // }
         // else
         // {
         //     if(a.first > b.first)
         //     {
         //         return true;
         //     }
         //     return false;
         // }
    }
};
int main()
{
	vector<int> myvector;
        myvector.push_back(10);
        myvector.push_back(20);
        myvector.front()=50;
        myvector.front() += myvector.back();
        cout << myvector.front() << endl;

        int arr[5] = { 4, 5, 1, 0, 1 };
	sort( arr, arr+5 );
	cout<< lower_bound( arr, arr+5, 3 ) - arr <<endl;

	vector<int>v={20, 40, 30, 10 , 50, 30};
	sort(v.begin(), v.end());
	cout<<upper_bound(v.begin(), v.end(), 30)-v.begin();
	cout<<endl;

	set<int>s;
	s.insert(1);
	s.insert(5);
	s.insert(7);
	s.insert(2);
	s.insert(12);
	s.insert(10);
	auto it = s.lower_bound(15);
	cout<< *it <<endl;

	priority_queue<pair<int, int> >q;
	q.push( {1, 5} );
	q.push( {4, 2} );
	q.push( {5, 3} );
	q.push({2, 4});
	q.push({3, 1});
	q.push({5, 2});
	cout<<q.top().first<<" "<<q.top().second<<endl;

	priority_queue<pi , vector<pi>, greater<pi> >pq;
	pq.push({1, 5});
	pq.push({5, 3});
	pq.push({3, 1});
	pq.push({5, 2});
	pq.push({1, 10});
	cout<<pq.top().first<<" "<<pq.top().second<<endl;

	priority_queue<pi , vector<pi>, Compare>ppq;
	ppq.push({1, 5});
	ppq.push({5, 15});
	ppq.push({7, 15});
	ppq.push({10, 2});
	ppq.push({1, 10});
	cout<<ppq.top().first<<" "<<ppq.top().second<<endl;

	set<int>ss;
	pair<set<int>::iterator, bool> ret;
	ss.insert(1);
	ss.insert(5);
	ss.insert(10);
	ss.insert(3);
	ret= ss.insert(4);
	cout<< *(ret.first) <<" "<<ret.second<<endl;

	ret= ss.insert(4);
	cout<< *(ret.first) <<" "<<ret.second<<endl;

	multimap<int, int>mp;
	mp.insert({1, 10});
	mp.insert({2, 10});
	mp.insert({1, 5});
	mp.insert({2, 10});
	mp.insert({3, 7});
	cout<<mp.size()<<endl;

	vector < int > vi = {1, 3, 2, 5};
	cout << vi.capacity() << endl; // this prints 4.
	vi.push_back(12);
	cout << vi.capacity() << endl;

	// file-2

	string str;
	str="hello";
	sort(str.begin(),str.end());
	cout<<str;
	cout<<endl;

	// cout<< reverseString("hello");
	reverse(str.begin(),str.end());
	cout<<str; 
	cout<<endl;

	string str1="54";
	string str2="541";
	str1.append(str2);
	cout<< str1.length();
	cout<<endl;

	//file-3
	vector< int > data = { 1, 1, 2, 3, 3, 3, 3, 4, 4, 4, 5, 5, 6 };
	auto lower = std::lower_bound(data.begin(), data.end(), 4);
	auto upper = std::upper_bound(data.begin(), data.end(), 4);
	for(auto it = lower; it != upper; it++)
	cout << *it << ' '; 
	cout<<endl;

	vector< int > dataa = {100, 142, 138, 96, 32, 149};
	swap(dataa[2], dataa[5]);
	int val1 = *max_element(dataa.begin(), dataa.begin() +3);
	int val2 = *max_element(dataa.begin()+3,dataa.end());
	cout<< min(val1, val2);
	END;

	string sas = "bca";
 
   	do {
        cout << sas << ' ';
    } while(next_permutation(sas.begin(), sas.end()));
    cout << sas;
    END;

    //file-7

    priority_queue<string, deque<string>, comp> pdq;
	    pdq.push("RAMU");
    pdq.push("SAM");
    pdq.push("SHYAM");
    while(! pdq.empty() )
    {
        cout << pdq.top() << " ";
        pdq.pop();
    }
    cout<<endl;

    vector<int> vv={1,4,2,10,3, 5, 12,100,6};

    priority_queue < int > pqq(vv.begin(), vv.end());

    while(!pqq.empty())
    {
    	cout<< pqq.top()<<" ";
    	pqq.pop();
    }
    cout<<endl;

    //file 8

    map < pair < int, int >, pair<string, int > > myMap;
map < set< int >, pair< string, int > > mmmyMap;
map < map < string, int >, long long > mmyMap;

	//file 9
	set < int > sss = {1, 2, 3, 3, 2, 1};
	multiset < int > msss = {1, 2, 3, 3, 2, 1};
	cout << msss.size() - *sss.upper_bound(2) - sss.size();
	cout<<endl;

	set<student,compa> bat;
	
	set < student, compar > batch ;
    batch.insert(student("Wang", 8.1));
    batch.insert(student("Ming", 6.32));
    batch.insert(student("Bruce", 8.82));
    batch.insert(student("Pandora", 7.63));

    for(student i : batch)
        cout<< i.cgpa << '\t';
	return 0;
}