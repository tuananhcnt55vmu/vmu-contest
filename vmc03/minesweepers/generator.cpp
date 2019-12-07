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

void random_test(int low, int high) {
    Generator<int> size_generator(low, high);
    int R = size_generator.generate();
    int C = size_generator.generate();
    int T = size_generator.generate();

    while(T--) {
        cout << R << " " << C << endl;
        Generator<int> mine_count_generator(1, R*C);
        Generator<int> row_generator(0, R-1);
        Generator<int> col_generator(0, C-1);

        vector<vector<char>> mp(R, vector<char>(C, '.'));
        int mine_count = mine_count_generator.generate();
        REP(i, 0, mine_count) {
            int x = row_generator.generate();
            int y = col_generator.generate();
            while(mp[x][y] == '*') {
                x = row_generator.generate();
                y = col_generator.generate();
            }
            mp[x][y] = '*';
        }

        REP(r, 0, R) {
            REP(c, 0, C) {
                cout << mp[r][c];
            }
            newline;
        }
    }
    cout << "0 0" << endl;
}

void random_small_test () {
    random_test(1, 100);
}

void random_large_test() {
    random_test(100, 100);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // random_small_test();
    random_large_test();
    return 0;
}