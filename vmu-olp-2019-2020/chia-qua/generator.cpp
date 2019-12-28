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
    set<int> a;
    int n, vmin, vmax, x;

    cin >> n >> vmin >> vmax;
    while(cin >> x) {
        a.insert(x);
    }
    Generator<int> value_factory(vmin, vmax);
    REP(i, 0, n - a.size()) {
        int value = value_factory.generate();
        while(a.find(value) != a.end()) {
            value = value_factory.generate();
        }
        a.insert(value);
    }
    cout << n << endl;
    for(int v: a) {
        cout << v << endl;
    }
    return 0;
}