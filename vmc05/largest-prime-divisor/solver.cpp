#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl             "\n"
#define newline            cout << "\n"
#define puts(_content_)    cout << _content_ << "\n" 

using namespace std;

#define long long long

typedef pair<long, long> pol;

vector<int> get_primes(int range) {
    vector<bool> is_prime(range + 10, true);
    is_prime[0] = is_prime[1] = false;
    FOR(i, 2, sqrt(range)) {
        for(int j = i*i; j <= range; j += i) {
            is_prime[j] = false;
        }
    }
    vector<int> primes;
    FOR(i, 2, range) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long n;
    cin >> n;
    vector<int> primes = get_primes(sqrt(n));
    long res = -1;
    for(int p: primes) {
        while(n > 1 && n % p == 0) {
            res = p;
            n /= p;
        }
    }
    if (n > 1 && res > 0) {
        res = n;
    }
    puts(res);
    return 0;
}