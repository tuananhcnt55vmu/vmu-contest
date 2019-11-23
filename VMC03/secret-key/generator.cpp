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

void random_test (int N, int min_val, int max_val) {
    Generator<int> value_generator(min_val, max_val);
    puts(N);
    set<int> used;
    REP(i, 0, N) {
        int value = value_generator.generate();
        while(used.find(value) != used.end()) {
            value = value_generator.generate();
        }
        puts(value);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    random_test(100, -3e4, 3e4);
    return 0;
}