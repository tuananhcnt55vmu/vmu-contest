#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl             "\n"
#define newline            cout << "\n"
#define puts(_content_)    cout << _content_ << "\n" 

using namespace std;

const int LIMIT = 2E7 + 7;

bool is_prime[LIMIT];

void sieve () {
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2, s = sqrt(LIMIT); i < s; ++i) {
        if (is_prime[i]) {
            for(int j = i * i; j < LIMIT; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    sieve();
    int S;
    cin >> S;
    
    int count = 0;
    REP(p, 3, LIMIT) {
        if(is_prime[p] && is_prime[p+2]) {
            count++;
            if (count == S) {
                cout << p << " " << p + 2 << endl;
                break;
            }
        }
    }

    return 0;
}