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
    REP(i, 0, n) {
        cout << random_value() << endl;
    }
}

bool isOdd[1000001];
vector<int> evens, odds;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // generate_input(1000000);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n = 0;
    int x;
    while(cin >> x) {
        if (x & 1) {
            evens.push_back(x);
            isOdd[n] = false;
        }
        else {
            odds.push_back(x);
            isOdd[n] = true;
        }
        n++;
    }

    sort(odds.begin(), odds.end());
    sort(evens.begin(), evens.end(), greater<int>());


    int odd_current = 0;
    int even_current = 0;

    REP(i, 0, n) {
        if (isOdd[i]) {
            cout << odds[odd_current++] << endl;
        }
        else {
            cout << evens[even_current++] << endl;
        }
    }

    return 0;
}