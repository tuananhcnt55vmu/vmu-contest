#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

template<class T> 
class Generator {
    public:
    mt19937 rng;
    uniform_int_distribution<T> dist;

    Generator(T start, T end) {
        random_device device;
        mt19937 rng(device());
        this->rng = rng;

        uniform_int_distribution<T> dist(start, end);
        this->dist = dist;
    }

    T generate () {
        return this->dist(this->rng);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int R=8, C=8, ban_count;
    cin >> ban_count;
    char mp[R][C];
    memset(mp, '.', sizeof mp);
    Generator<int> index_factory(0, R*C - 1);
    REP(i, 0, ban_count) {
        int idx = index_factory.generate();
        int r = idx / R;
        int c = idx - r*C;
        while(mp[r][c] == '#') {
            idx = index_factory.generate();
            r = idx / R;
            c = idx - r*C;
        }
        mp[r][c] = '#';
    }
    REP(r, 0, R) {
        REP(c, 0, C) {
            cout << mp[r][c];
        }
        newline;
    }
    return 0;
}