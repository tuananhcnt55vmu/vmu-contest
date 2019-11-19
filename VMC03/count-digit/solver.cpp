#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

void solve (int n) {
    vector<int> cnt(10, 0);
    FOR(i, 1, n) {
        int number = i;
        while(number) {
            cnt[number % 10]++;
            number /= 10;
        }
    }
    FOR(i, 0, 9) {
        cout << cnt[i] << " ";
    }
    newline;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T, N;
    cin >> T;

    while(T--) {
        cin >> N;
        solve(N);
    }

    return 0;
}