#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
bool kt(int a, int b)
{
    return a>b;
}
int c[MAX];
int l[MAX];
int a[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("input.txt", "r", stdin);
    int n=0,d,i=0,j=0;
    while(cin>>d)
    {
        if(d%2==0)
        {
            c[i++]=d;
             a[n++]=0;
        }
        else
        {l[j++]=d;
            a[n++]=1;
        }
    };
    sort(c,c+i);
    sort(l,l+j,kt);
    i=0;
    j=0;
    for(int k=0;k<n;k++)
    {  if(a[k]==0)
            a[k]=c[i++];
        else 
            a[k]=l[j++];
    }
    for(int k=0;k<n;k++)
        cout<<a[k]<<endl;
    return 0;
}