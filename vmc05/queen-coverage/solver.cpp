#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int R = 8, C = 8;
char mp[R][C];
bool found, covered_row[R], covered_col[C], covered_dia1[R+C], covered_dia2[R+C];
char label_row[R] = { '1', '2', '3', '4', '5', '6', '7', '8' };
char label_col[C] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

void put (int idx) {
    if (idx == R*C) {
        found = true;
        // REP(i, 0, R) {
        //     REP(j, 0, C) {
        //         cout << mp[i][j];
        //     }
        //     newline;
        // }
        found = true;
        REP(i, 0, R) {
            REP(j, 0, C) {
                if (mp[i][j] == 'Q') {
                    cout << label_row[i] << label_col[j];
                }
            }
        }
        newline;
        return;
    }
    if(!found) {
        int r = idx / R;
        int c = idx - r*C;
        if (mp[r][c] == '.' && !covered_row[r] && !covered_col[c] && !covered_dia1[r+c] && !covered_dia2[r-c+C]) {
            covered_row[r] = true;
            covered_col[c] = true;
            covered_dia1[r+c] = true;
            covered_dia2[r-c+C] = true;
            mp[r][c] = 'Q';
        }
        put(idx+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    REP(r, 0, R) {
        REP(c, 0, C) {
            cin >> mp[r][c];
        }
    }
    put(0);
    return 0;
}