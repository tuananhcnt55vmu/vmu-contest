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

void test03() {
    freopen("input03.txt", "w", stdout);
    int T = 40;
    int N = 1e6;
    puts(T);
    while(T--) {
        cout << N-- << endl;
    }
}

void test04() {
    freopen("input04.txt", "w", stdout);
    int T = 40;
    
    int min_val = 1, max_val = 1e6;
    
    Generator<int> generator(min_val, max_val);

    puts(T);
    while(T--) {
        cout << generator.generate() << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    test03();
    return 0;
}