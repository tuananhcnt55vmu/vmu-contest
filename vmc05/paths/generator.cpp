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

void generate(int R, int C, int K) {
    cout << R << " " << C << " " << K << endl;
    Generator<int> row_factory(1, R);
    Generator<int> col_factory(1, C);
    bool P[R+1][C+1];
    memset(P, 0, sizeof P);
    REP(i, 0, K) {
        int x = row_factory.generate();
        int y = col_factory.generate();
        while(P[x][y]) {
            x = row_factory.generate();
            y = col_factory.generate();
        }
        cout << x << " " << y << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int R, C, K;
    cin >> R >> C >> K;
    generate(R, C, K);
    return 0;
}