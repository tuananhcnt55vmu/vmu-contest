#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int MAXN = 1000;

int m[MAXN][MAXN];

void test1 (int R, int C) {
    memset(m, 0, sizeof m);
    REP(c, 0, C) {
        m[0][c] = 1;
        m[R-1][c] = -1;
    }
    m[R-1][0] = 0;
    int K = 2*C - 1;
    freopen("input01.txt", "w", stdout);
    
    cout << C << " " << R << " " << K << endl;
    REP(r, 0, R) {
        REP(c, 0, C) {
            if (m[r][c] == -1) {
                cout << c << " " << R-1-r << " 1\n";
            }
            else if (m[r][c] == 1) {
                cout << c << " " << R-1-r << " 0\n";
            }
        }
    }
}

void test2 () {
    memset(m, 0, sizeof m);
    m[0][0] = 1;
    m[0][3] = 1;
    m[1][1] = 1;
    m[1][2] = 1;
    m[2][2] = 1;
    m[3][1] = 1;
    m[3][3] = 1;
    freopen("input02.txt", "w", stdout);
    cout << "4 4 7" << endl;
    REP(r, 0, 4) {
        REP(c, 0, 4) {
            if (m[r][c] == -1) {
                cout << c << " " << 3 - r << " 1\n";
            }
            else if (m[r][c] == 1) {
                cout << c << " " << 3 - r << " 0\n";
            }
        }
    }
}

void test3 () {
    memset(m, 0, sizeof m);
    m[2][0] = 1;
    m[2][1] = -1;
    m[1][1] = 1;
    m[1][2] = -1;
    m[0][2] = 1;
    freopen("input03.txt", "w", stdout);
    cout << "4 4 5" << endl;
    REP(r, 0, 4) {
        REP(c, 0, 4) {
            if (m[r][c] == -1) {
                cout << c << " " << 3 - r << " 1\n";
            }
            else if (m[r][c] == 1) {
                cout << c << " " << 3 - r << " 0\n";
            }
        }
    }
}

void test4() {
    freopen("input04.txt", "w", stdout);
    cout << "1 1 0" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    test1(1000, 1000);
    // test4();
    return 0;
}