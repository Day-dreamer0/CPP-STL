// GFG-> https://www.geeksforgeeks.org/maximum-product-cutting-dp-36/

#include<bits/stdc++.h>
using namespace std;
int maxProd(int n)
{
   int t[n+1];
   t[0] = t[1] = 0;

   for (int i = 1; i <= n; i++) //length loop
   {
      int cut_length=i;
      int max_val = 0;
      for (int j = 1; j <= cut_length; j++)
         max_val = max((i-j)*j, j*t[i-j],max_val);
      t[i] = max_val;
   }
   return t[n];
}
//OR
int max_product_cut(int n)
{
    int cut=n;
    int t[cut+1][n+1];
    memset(t,-1,sizeof(t));
    for(int j=0;j<n+1;j++)
    {
        t[0][j]=0;
    }
    for(int i=0;i<cut+1;++i)
    {
        t[i][0]=0;
    }
    for(int i=1;i<cut+1;i++)
    {
        for(int j=1;j<n+1;++j)
        {
            if(i<=j)
            {
                t[i][j] = i*(j-i);
                int val = max(i*t[i][j-i],t[i-1][j]);
                t[i][j] = max(val,t[i][j]);
            }
            else
                t[i][j] = t[i-1][j];
        }
    }
    return t[cut][n];
}

int main()
{
    int n;
    cin>>n;
    cout<<max_product_cut(n);
    return 0;
}