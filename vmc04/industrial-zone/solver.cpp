#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

#define long long long

long MOD = 998244353;
long BASE[2][2] = {{1,1},{1,0}};

void multiply(long F[2][2], long M[2][2]) {
   long a = F[0][0] * M[0][0] + F[0][1] * M[1][0];
   long b = F[0][0] * M[0][1] + F[0][1] * M[1][1];
   long c = F[1][0] * M[0][0] + F[1][1] * M[1][0];
   long d = F[1][0] * M[0][1] + F[1][1] * M[1][1];
   F[0][0] = a % MOD;
   F[0][1] = b % MOD;
   F[1][0] = c % MOD;
   F[1][1] = d % MOD;
}

void power(long M[2][2], long n) {
   if (n > 1) {
        power(M, n / 2);
        multiply(M, M);
        if (n & 1) {
            multiply(M, BASE);
        }
   }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n;
    cin >> n;
    long M[2][2] = {{1,1},{1,0}};
    power(M, n);
    cout << (M[0][0] * M[0][1]) % MOD << endl;
    return 0;
}
