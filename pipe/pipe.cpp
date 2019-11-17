#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;
const int MAXN = 1010;

typedef pair<int,int> Position;

#define _x first
#define _y second

int R, C, K;
int m[MAXN][MAXN];
bool visited[MAXN][MAXN];

const Position OUTSIDE = Position(-1, -1); 

void print(Position p) {
    cout << p._x << " " << p._y << endl;
}

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

inline bool is_outside(Position & p) {
    return p._x < 0 || p._x >= R || p._y < 0 || p._y >= C;
}

inline bool is_visited(Position & p) {
    return visited[p._x][p._y];
}


int traversal(Position pre, Position cur) {
    int step = 2;
    Position next_pos = get_next(pre, cur);
    while(!is_visited(next_pos) && !is_outside(next_pos)) {
        step++;
        next_pos = get_next(cur, next_pos);
    }
    return step;
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

int stack_traversal(Position pre, Position cur) {
    memset(visited, 0, sizeof visited);
    visited[pre._x][pre._y] = true;
    stack<State> stk;
    stk.push(State(pre, cur, 2));
    while(!stk.empty()) {
        State top = stk.top();
        // print(top.cur);
        stk.pop();
        visited[top.cur._x][top.cur._y] = true;
        Position next_pos = get_next(top.pre, top.cur);
        if (!is_visited(next_pos) && !is_outside(next_pos)) {
            stk.push(State(top.cur, next_pos, top.step + 1));
        }
        if (stk.empty()) {
            return top.step;
        }
    }
}

void print_map() {
    printf("%3s", "");
    REP(i, 0, C) {
        printf("%3d", i);
    }
    printf("\n\n");
    REP(i, 0, R) {
        printf("%-3d", i);
        REP(j, 0, C) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    freopen("input01.txt", "r", stdin);
    
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
    
    // print_map();

    // int p1 = 1 + traversal(Position(R-1, 0), Position(R-2, 0));
    // memset(visited, 0, sizeof visited);
    // int p2 = 1 + traversal(Position(R-1, 0), Position(R-1, 1));
    int p1 = 1, p2 = 1;
    if (R > 1) {
        p1 = stack_traversal(Position(R-1, 0), Position(R-2, 0));
    }
    if (C > 1) {
        p2 = stack_traversal(Position(R-1, 0), Position(R-1, 1));
    }
    cout << min(p1, p2) << " " << max(p1, p2) << endl;
    return 0;
}