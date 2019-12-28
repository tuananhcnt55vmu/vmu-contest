#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl             "\n"
#define newline            cout << "\n"
#define puts(_content_)    cout << _content_ << "\n" 

using namespace std;

const int MAXN = 303;
const int INF = 1E5 + 7;

int n, a[MAXN];
bool exist[INF];

bool check (int m) {
    memset(exist, 0, sizeof exist);
    REP(i, 0, n) {
        int mod = a[i] % m;
        if (exist[mod]) return false;
        exist[mod] = true;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int vmin = INF, vmax = -INF;
    REP(i, 0, n) {
        cin >> a[i];
        vmin = min(vmin, a[i]);
        vmax = max(vmax, a[i]);
    }
    FOR(m, n, vmax - vmin + 1) {
        if (check(m)) {
            cout << m << endl;
            break;
        }
    }
    return 0;
}