#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int LIM = 111, MOD = 1E9 + 7;

bool belongP[LIM][LIM];
int R, C, K, dp[LIM][LIM][LIM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> K;
    int x, y;
    REP(i, 0, K) {
        cin >> x >> y;
        belongP[R - x + 1][y] = true;
    }
    dp[R][1][0] = !belongP[R][1];
    dp[R][1][1] = belongP[R][1];
    FOR(k, 0, K) {
        FORD(r, R, 1) {
            FOR(c, 1, C) {
                if (r == R && c == 1 && k <= 1) continue;
                int v = int(belongP[r][c]);
                dp[r][c][k] = (dp[r+1][c][k-v] + dp[r][c-1][k-v]) % MOD;    
            }
        }
    }
    // FOR(k, 0, K) {
    //     cout << "k = " << k << endl;
    //     FORD(r, R, 1) {
    //         FOR(c, 1, C) {
    //             cout << dp[r][c][k] << " ";
    //         }
    //         newline;
    //     }
    // }
    FOR(k, 0, K) {
        puts(dp[1][C][k]);
    }
    return 0;
}