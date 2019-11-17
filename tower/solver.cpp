#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

typedef long long ll;

int R, C, T;
set<ll> covered; 

int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

inline bool is_inside (int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void cover(int x, int y) {
    int nx, ny;
    REP(i, 0, 9) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (is_inside(nx, ny)) {
            covered.insert(nx * R + ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> R >> C >> T;

    int x, y;
    REP(i, 0, T) {
        cin >> x >> y;
        cover(x, y);
    }
    cout << 1LL * R * C - covered.size() << endl;
    return 0;
}