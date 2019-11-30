#include<iostream>
#include<cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int prime(long long n)
    {
    if(n<2)
         return 0;
     for (long long  i=2;i<=sqrt(n);i++)
         if(n%i==0)
             return 0;
     return 1;
}
long long arr[9] = { 2,3,5,7,9,8,6,4,1 };
vector <long long> v;

void helper(long long a,long long b, long long s) {  
       if (a<=s && s <=b)
           v.push_back(s);
    
        for (int i = 0; i < 9; i++) {
            long long t = s * 10 + arr[i];
            // kiem tra t co phai la nguyen to k
            if (prime(t) && t <= b) 
                helper(a,b,t);
        }
}

int main() {
    
    long long a,b,k=0;
    cin>>a>>b;
    while(k<4)
    {
    helper(a,b,arr[k]);
    k++;
    }
    
   cout<<v.size()<<"\n";
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout<<v.at(i)<<"\n";

               
    return 0;
}