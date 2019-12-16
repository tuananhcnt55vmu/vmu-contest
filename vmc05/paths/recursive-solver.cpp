#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int LIM = 101, MOD = 1E9 + 7;

int R, C, K, dp[LIM][LIM][LIM*LIM], P[LIM][LIM];

int solve (int x, int y, int k) {
    if (x < 1 || y < 1 || x > R || y > C) {
        return 0;
    }
    if (dp[x][y][k] != -1) return dp[x][y][k];
    dp[x][y][k] = (solve(x-1, y, k - P[x][y]) + solve(x, y-1, k - P[x][y])) % MOD;
    return dp[x][y][k];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> K;

    REP(i, 0, LIM) REP(j, 0, LIM) REP(k, 0, LIM*LIM) dp[i][j][k] = -1;

    int x, y;
    REP(i, 0, K) {
        cin >> x >> y;
        P[x][y] = 1;
    }

    dp[1][1][0] = 1 - P[1][1];
    dp[1][1][1] = P[1][1];

    FOR(i, 0, K) {
        cout << solve(R, C, i) << endl;
    }

    return 0;
}