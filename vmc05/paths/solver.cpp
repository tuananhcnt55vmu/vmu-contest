#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int LIM = 101, MOD = 1E9 + 7;


int R, C, K, dp[LIM][LIM][LIM*LIM], P[LIM][LIM];;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> K;
    
    int x, y;
    REP(i, 0, K) {
        cin >> x >> y;
        P[x][y] = 1;
    }

    dp[1][1][0] = 1 - P[1][1];
    dp[1][1][1] = P[1][1];

    FOR(k, 0, K) {
        FOR(r, 1, R) {
            FOR(c, 1, C) {
                if (r == 1 && c == 1) continue;
                dp[r][c][k] = (dp[r-1][c][k-P[r][c]] + dp[r][c-1][k-P[r][c]]) % MOD;
            }
        }
    }
    FOR(k, 0, K) {
        puts(dp[R][C][k]);
    }
    return 0;
}