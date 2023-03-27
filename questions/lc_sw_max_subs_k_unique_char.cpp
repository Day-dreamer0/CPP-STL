// GFG-> https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
//M-1 using unordered_map
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int n=fruits.size();
        unordered_map<int,int> um; // char,count
        int k=2;
        int mx=0;
        while(j<n)
        {
            um[fruits[j]]++;
            // if(um.size()<=k)
            // {
            //     mx=max(mx,j-i+1);
            //     j++;
            // }
            if(um.size()<k)
            j++;
            else if(um.size()==k)
            {
                mx=max(mx,j-i+1);
                j++;
            }
            else if(um.size()>k)
            {
                while(um.size()>k)
                {
                    um[fruits[i]]--;
                    if(um[fruits[i]]==0)
                        um.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};
//M-2 using array to retain count
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int a[26]={0};
    int i=0,j=0,count=0,mx=0;
    while(j<s.length())
    {
        a[s[j]-'a']++;
        if(a[s[j]-'a']==1)
        {
            count++;
        }
        if(count<k)
        j++;
        else if(count==k)
        {
            mx=max(mx,j-i+1);
            j++;
        }
        else if(count>k)
        {
            while(count>k)
            {
                a[s[i]-'a']--;
                if(a[s[i]-'a']==0)
                count--;
                i++;
            }
            j++;
        }
    }
    if(mx)
    return mx;
    return -1;
}
};