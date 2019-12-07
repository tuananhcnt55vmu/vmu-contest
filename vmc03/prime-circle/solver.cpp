#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

int N, T;
int circle[20];
bool is_prime[40], used[40];

void sieve (int limit) {
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < limit; ++i) {
        for(int j = i*i; j < limit; j += i) {
            is_prime[j] = false;
        }
    }
}

void generate (int pos) {
    if (pos == N) {
        if (is_prime[circle[N-1] + 1]) {
            REP(i, 0, N) {
                cout << circle[i] << " ";
            }
            newline;
        }
        return;
    }
    FOR(value, 2, N) {
        if (!used[value] && is_prime[value + circle[pos-1]]) {
            used[value] = true;
            circle[pos] = value;
            generate(pos + 1);
            used[value] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve(69);
    circle[0] = 1;

    cin >> T;
    FOR(t, 1, T) {
        cin >> N;
        memset(used, false, sizeof used);
        used[1] = true;
        cout << "#" << t << endl;
        generate(1);
        newline;
    }

    return 0;
}