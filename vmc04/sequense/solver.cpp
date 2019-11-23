#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int LIMIT = 100;
int F[LIMIT];

int sort (int x) {
    vector<int> digits;
    while(x) {
        digits.push_back(x % 10);
        x /= 10;
    }
    sort(digits.begin(), digits.end());
    int res = 0;
    for (int d: digits) {
        res = res * 10 + d;
    }
    return res;
}

int get(int n) {
    if (n < LIMIT) return F[n];
    return F[31 + (n - 31) % (36 - 31 + 1)];
}

void preprocess () {
    F[1] = 1;
    REP(i, 2, LIMIT) {
        F[i] = sort(F[i-1] * 2);
    }
    // REP(i, 1, LIMIT) {
    //     assert(F[i] == get(i));
    // }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    preprocess();

    int n;
    cin >> n;
    cout << get(n) << endl;

    return 0;
}