#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl             "\n"
#define newline            cout << "\n"
#define puts(_content_)    cout << _content_ << "\n" 

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s, t;
    getline(cin, s);
    getline(cin, t);
    int cur = 0;
    bool matched = false;
    REP(i, 0, t.length()) {
        if (t[i] == s[cur]) {
            cur++;
            if (cur == s.length()) {
                matched = true;
                break;
            }
        }
    }
    puts((matched ? "YES" : "NO"));
    return 0;
}