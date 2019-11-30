#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int MAXN = 1e6+1;

int cnt_mul[MAXN], cnt2[MAXN];

int count2(int n) {
    int cnt = 0;
    while(n) {
        if (n % 10 == 2) {
            cnt++;
        }
        n /= 10;
    }
    return cnt;
}

int count_mul(int n) {
    return int(n % 3 == 0 || n % 5 == 0 || n % 7 == 0);
}

void preprocess () {
    REP(i, 2, MAXN) {
        cnt2[i] = cnt2[i-1] + count2(i);
        cnt_mul[i] = cnt_mul[i-1] + count_mul(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    preprocess();

    int n, T;
    cin >> T;
    while(T--) {
        cin >> n;
        cout << cnt2[n] << " " << cnt_mul[n] << endl;
    }

    return 0;
}