#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1};

void solve (int cas, int R, int C, vector<vector<char>> & mp) {
    REP(r, 0, R) {
        REP(c, 0, C) {
            if (mp[r][c] == '*') {
                REP(i, 0, 8) {
                    int u = r + dx[i];
                    int v = c + dy[i];
                    if (u >= 0 && u < R && v >= 0 && v < C && mp[u][v] != '*') {
                        mp[u][v]++;
                    }
                }
            }
        }
    }
    cout << "#" << cas << endl;
    REP(r, 0, R) {
        REP(c, 0, C) {
            if (mp[r][c] == '*') {
                cout << '*';
            }
            else {
                cout << (int) mp[r][c];
            }
        }
        newline;
    }
    newline;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int R, C, cas = 1;
    while(true) {
        cin >> R >> C;
        if (R + C == 0) break;
        vector<vector<char>> mp(R, vector<char>(C));
        REP(r, 0, R) {
            REP(c, 0, C) {
                cin >> mp[r][c];
                if (mp[r][c] == '.') {
                    mp[r][c] = 0;
                }
            }
        }
        solve(cas++, R, C, mp);
    }
    return 0;
}