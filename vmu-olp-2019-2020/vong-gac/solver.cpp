#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int N = 8;

int mat[N][N];
bool row[N], col[N], dia1[N+N], dia2[N+N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    REP(i, 0, N) {
        REP(j, 0, N) {
            cin >> mat[i][j];
        }
    }

    REP(r, 0, N) {
        REP(c, 0, N) {
            if (mat[r][c] == 0 && !row[r] && !col[c] && !dia1[r+c] && !dia2[r-c+N]) {
                mat[r][c] = -1;
                row[r] = true;
                col[c] = true;
                dia1[r+c] = true;
                dia2[r-c+N] = true;
            }
        }
    }

    REP(r, 0, N) {
        REP(c, 0, N) {
            if (mat[r][c] == -1) {
                cout << r << c << " ";
            }
        }
    }

    return 0;
}