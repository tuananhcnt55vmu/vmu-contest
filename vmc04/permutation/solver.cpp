#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

int count (string s) {
    vector<int> fact(s.length() + 1);
    fact[0] = fact[1] = 1;
    FOR(i, 2, s.length()) {
        fact[i] = fact[i-1] * i;
    }
    vector<int> cnt(256, 0);
    for (char c: s) {
        cnt[c]++;
    }
    int total = fact[s.length()];
    for (int c: cnt) {
        if (c > 1) {
            total /= fact[c];
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    puts(count(S));
    do {
        puts(S);
    } while(next_permutation(S.begin(), S.end()));
    return 0;
}