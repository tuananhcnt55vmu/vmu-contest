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

const int LIM = 1010;

char mp[LIM][LIM];
bool covered[LIM][LIM];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct State {
    int x, y, length;
    State(int _x, int _y, int _length) {
        x = _x;
        y = _y;
        length = _length;
    }
};

State random_next (vector<State> & nexts) {
    Generator<int> index_factory(0, nexts.size() - 1);
    return nexts[index_factory.generate()];
}

void generate(int R, int C, int x, int y, int length) {
    memset(mp, '.', sizeof mp);
    mp[x][y] = '-';
    stack<State> stk;
    stk.push(State(x, y, 1));
    covered[x][y] = true;
    while(!stk.empty()) {
        State cur = stk.top();
        if (cur.length == length) break;
        stk.pop();
        vector<State> nexts;
        REP(idx, 0, 8) {
            int u = cur.x + dx[idx];
            int v = cur.y + dy[idx];
            if (u >= 0 && u < R && v >= 0 && v < C && !covered[u][v]) {
                nexts.push_back(State(u, v, cur.length + 1));
            }
        }
        if (nexts.size() > 0) {
            State next = random_next(nexts);
            stk.push(next);
            mp[next.x][next.y] = '|';
            covered[next.y][next.y] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int R, C, x, y, length;
    cin >> R >> C >> x >> y >> length;
    
    generate(R, C, x, y, length);

    cout << C << " " << R << endl;
    REP(i, 0, R) {
        REP(j, 0, C) {
            cout << mp[i][j];
        }
        newline;
    }
    return 0;
}