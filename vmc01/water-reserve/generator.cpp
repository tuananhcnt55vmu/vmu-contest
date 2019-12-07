#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

long long MAXN = 10000;

inline long long random_value (bool allow_negative = false) {
    if (allow_negative){
        return (rand() % (MAXN << 1)) - MAXN;
    }
    return rand() % MAXN;
}

void generate_input(int n) {
    freopen("input.txt", "w", stdout);
    int lim = 1e4;
    REP(i, 0, n) {
        int storage = 1 + rand() % lim;
        cout << rand() % storage << " " << storage << endl;
    }
}

const int LIMIT = 1E6 + 7;
int t[LIMIT], a[LIMIT];
long long accum[LIMIT];


int solve () {
    freopen("input01.txt", "r", stdin);
    int n;
    cin >> n;
    REP(i, 0, n) {
        cin >> t[i] >> a[i];
    }

    long long used = 0;

    REP(i, 0, n) {
        used += t[i];
    }

    sort(a, a+n);
    
    int p = -1;
    REP(i, 0, n) {
        if (used > 0) {
            used -= a[i];
            p = i;
        }
    }
    if (p == n-1) {
        return 0;
    }
    return n - p -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << endl;
    return 0;
}