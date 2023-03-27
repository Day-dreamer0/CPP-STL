/* Sanket has a string consisting of only 'a' and 'b' as the characters.
Sanket describes perfectness of a string as the maximum length substring of
equal characters. Sanket is given a number k which denotes the maximum number
of characters he can change. Find the maximum perfectness he can generate by
changing no more than k characters.
Input Format:
The first line contains an integer denoting the value of K. The next line contains a string having only ‘a’ and ‘b’ as the characters.
Constraints:
2 ≤ N ≤ 10^5
Output Format
A single integer denoting the maximum perfectness achievable.
Sample Input
2
abba
Sample Output
4
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0,mx=0,n=s.size(),max_occ=0;
        unordered_map<char,int> um;
        char c;
        while(j<n)
        {
            um[s[j]]++;
            if(max_occ<um[s[j]])
                max_occ=um[s[j]];
            
            if((j-i+1)-max_occ<=k)
            {
                mx=max(mx,j-i+1);
                j++;
            }
            else if((j-i+1)-max_occ>k)
            {
                while((j-i+1)-max_occ>k)
                {       
                    um[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};