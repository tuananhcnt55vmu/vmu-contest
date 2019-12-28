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

const int MX = 101;
const int INF = 1E7;
int mat[MX][MX];
bool is_prime[INF+1];
bool used[INF+1];

void sieve () {
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = true;
    for (int i = 2; i*i <= INF; ++i) {
        for(int j = i*i; j <= INF; j += i) {
            is_prime[j] = false;
        }
    }
}

int get_composite (Generator<int> & factory) {
    int value = factory.generate();
    while(is_prime[value]) {
        value = factory.generate();
    }
    return value;
}

int get_prime (Generator<int> & factory) {
    int value = factory.generate();
    while(!is_prime[value]) {
        value = factory.generate();
    }
    return value;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int R, C, vmin, vmax;
    cin >> R >> C >> vmin >> vmax;
    Generator<int> value_factory(vmin, vmax);
    REP(i, 0, R) {
        REP(j, 0, C) {
            mat[i][j] = get_composite(value_factory);
        }
    }
    int count, x, y;
    cin >> count;
    while(count--) {
        cin >> x >> y;
        mat[x][y] = get_prime(value_factory);
    }

    cout << R << " " << C << endl;
    REP(i, 0, R) {
        REP(j, 0, C) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}