#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl             "\n"
#define newline            cout << "\n"
#define puts(_content_)    cout << _content_ << "\n" 

using namespace std;
const int MAXN = 1010;

typedef pair<int,int> Position;

#define _x first
#define _y second

int R, C, K;
int m[MAXN][MAXN];
bool visited[MAXN][MAXN];

const Position OUTSIDE = Position(-1, -1); 

Position get_next(Position pre, Position cur) {
    if (m[cur._x][cur._y] == 0) {
        // go forward
        if (pre._x == cur._x) {
            return Position(cur._x, cur._y + (cur._y > pre._y ? 1 : -1));
        }
        return Position(cur._x + (cur._x > pre._x ? 1 : -1), cur._y);
    }
    if (m[cur._x][cur._y] == -1) {
        // turn left
        if (pre._x == cur._x) {
            return Position(cur._x + (cur._y > pre._y ? -1 : 1), cur._y);
        }
        return Position(cur._x, cur._y + (cur._y > pre._y ? -1 : 1));
    }
    if (m[cur._x][cur._y] == 1) {
        // turn right
        if (pre._x == cur._x) {
            return Position(cur._x + (cur._y > pre._y ? 1 : -1), cur._y);
        }
        return Position(cur._x, cur._y + (cur._x > pre._x ? -1 : 1));
    }
    return OUTSIDE; 
}

bool is_outside(Position & p) {
    return p._x < 0 || p._x >= R || p._y < 0 || p._y >= C;
}

bool is_visited(Position & p) {
    return visited[p._x][p._y];
}

typedef struct state {
    Position pre;
    Position cur;
    int step;

    state(Position _pre, Position _cur, int _step) {
        pre = _pre;
        cur = _cur;
        step = _step;
    }

} State;

void set_visited(Position pos) {
    visited[pos._x][pos._y] = true;
}

int traversal(Position pre, Position cur) {
    memset(visited, 0, sizeof visited);
    set_visited(pre);
    set_visited(cur);
    int step = 2;
    Position next_pos = get_next(pre, cur);
    while(!is_visited(next_pos) && !is_outside(next_pos)) {
        step++;
        pre = cur;
        cur = next_pos;
        next_pos = get_next(pre, cur);
        set_visited(cur);
    }
    return step;
}

int main() {
    
    cin >> C >> R >> K;

    int x, y ,t;
    REP(i, 0, K) {
        cin >> x >> y >> t;
        if (t) {
            m[R-1-y][x] = -1;
        }
        else {
            m[R-1-y][x] = 1;
        }
    }
    
    int p1 = 1, p2 = 1;
    if (R > 1) {
        p1 = traversal(Position(R-1, 0), Position(R-2, 0));
    }
    if (C > 1) {
        p2 = traversal(Position(R-1, 0), Position(R-1, 1));
    }
    cout << min(p1, p2) << " " << max(p1, p2) << endl;
    return 0;
}