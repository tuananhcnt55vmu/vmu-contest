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

typedef pair<int, int> pii;

pii get_location (int index, int N) {
    int row = index / N;
    int col = index - row * N;
    return pii(row + 1, col + 1);
}

void random (int N, int Q) {
    Generator<int> value_factory(1, 100);
    puts(N);
    FOR(i, 1, N) {
        FOR(j, 1, N) {
            cout << value_factory.generate() << " ";
        }
        cout << endl;
    }

    Generator<int> index_factory(0, N*N - 1);
    puts(Q);
    REP(q, 0, Q) {
        int begin = index_factory.generate();
        int end = index_factory.generate();
        pii l1 = get_location(begin, N);
        pii l2 = get_location(end, N);
        while (l2.first < l1.first || l2.second < l1.second) {
            begin = index_factory.generate();
            end = index_factory.generate();
            l1 = get_location(begin, N);
            l2 = get_location(end, N);
        }
        cout << l1.first << " " << l1.second << " " << l2.first << " " << l2.second << endl;
    }
}

void large_test() {
    int N = 1000, Q = 10000;
    puts(N);
    Generator<int> value_factory(1, 100);
    FOR(i, 1, N) {
        FOR(j, 1, N) {
            cout << value_factory.generate() << " ";
        }
        cout << endl;
    }
    puts(Q);
    REP(i, 0, Q) {
        cout << "1 1 1000 1000" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // int N, Q;
    // cin >> N >> Q;
    // random(N, Q);
    large_test();
    return 0;
}