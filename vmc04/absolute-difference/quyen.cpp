#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


typedef struct Mang{
    int x,y, a,b;
}Mang;
int arr[10000][10000];
int chenh_lech(int x, int y, int a, int b)
{
    int c=0,l=0;
    for(int i=x;i<=a;i++)
    for(int j=y;j<=b;j++)
           {
                if((i+j)%2==0)
                     c+=arr[i][j];
        else
                  l+=arr[i][j];
           }
   
   if (l>c)
      return l-c;
   return c-l;
}
int main()
{
    int n;
    
    Mang m[10000];
    cin>>n;
    for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        {
        cin>>arr[i][j];
        
        }
   
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>m[i].x>>m[i].y>>m[i].a>>m[i].b;
    }
    int i=0;
    while(i<k)
    {
        cout<<chenh_lech(m[i].x, m[i].y,m[i].a,m[i].b)<<"\n";
        i++;
    }
      return 0;  
}