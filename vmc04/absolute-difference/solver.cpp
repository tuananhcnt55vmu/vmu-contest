#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;
const int MAXN = 1010;

int N, mp[MAXN][MAXN], dp[MAXN][MAXN];

void preprocess () {
    FOR(r, 1, N) {
        FOR(c, 1, N) {
            dp[r][c] = mp[r][c] + dp[r-1][c] + dp[r][c-1] - dp[r-1][c-1];
        }
    }
}

int abs (int x) {
    return x < 0 ? -x : x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    FOR(r, 1, N) {
        FOR(c, 1, N) {
            cin >> mp[r][c];
            if ((r + c) & 1) {
                mp[r][c] = -mp[r][c];
            }
        }
    }
    preprocess();
    int Q, x1, y1, x2, y2;
    cin >> Q;
    while(Q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << abs(dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1]) << endl;
    }
    return 0;
}