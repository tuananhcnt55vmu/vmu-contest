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

void random_test () {
    int T = 25;
    puts(T);
    Generator<int> generator(1, 9999);
    while(T--) {
        puts(generator.generate());
    }
}

void large_test() {
    int T = 25;
    puts(T);
    while(T--) {
        puts(9999);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // random_test();
    large_test();

    return 0;
}