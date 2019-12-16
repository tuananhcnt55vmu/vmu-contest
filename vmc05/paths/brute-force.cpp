#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int LIM = 111, MOD = 1E9 + 7;


int R, C, K, P[LIM][LIM];
vector<int> ans;

int dx[] = {1, 0};
int dy[] = {0, 1};

bool isValid (int x, int y) {
    return x > 0 and x <= R and y > 0 and y <= C;
}

void traversal (int x, int y, int cnt) {
    if (x == R && y == C) {
        ans[cnt]++;
        ans[cnt] %= MOD;
    }
    else {
        for (int i = 0; i < 2; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny)) {
                traversal(nx, ny, cnt + P[nx][ny]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> K;
    ans.resize(K + 1, 0);
    int x, y;
    REP(i, 0, K) {
        cin >> x >> y;
        P[x][y] = 1;
    }
    traversal(1, 1, P[1][1]);
    FOR(i, 0, K) {
        cout << ans[i] << endl;
    }
    return 0;
}