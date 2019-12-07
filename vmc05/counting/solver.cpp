#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

#define long long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n;
    cin >> n;
    long res = 0;
    FOR(i, 1, sqrt(n)) {
        if (n % i == 0) {
            res++;
            if (n / i > i) {
                res++;
            }
        }
    }
    puts(res);
    return 0;
}