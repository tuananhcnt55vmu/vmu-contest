#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int LIM = 1010;
char mp[LIM][LIM];
bool falled[LIM][LIM];
int L, W;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct State {
    int x, y, dept;
    State(int _x, int _y, int _dept) {
        x = _x;
        y = _y;
        dept = _dept;
    }
};

int solve (int x, int y) {
    int max_dept = 1;
    queue<State> que;
    que.push(State(x, y, 1));
    falled[x][y] = true;        
    while(!que.empty()) {
        State cur = que.front();
        que.pop();
        max_dept = max(max_dept, cur.dept);
        REP(i, 0, 8) {
            int u = cur.x + dx[i];
            int v = cur.y + dy[i];
            if (u >= 0 && u < L && v >= 0 && v < W && !falled[u][v] && mp[u][v] == '|') {
                que.push(State(u, v, cur.dept + 1));
                falled[u][v] = true;
            }
        }
    }
    return max_dept;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> W >> L;
    int start_x, start_y;
    REP(i, 0, L) {
        REP(j, 0, W) {
            cin >> mp[i][j];
            if (mp[i][j] == '-') {
                start_x = i;
                start_y = j;
            }
        }
    }
    cout << 0.1 * solve(start_x, start_y) << endl;
    return 0;
}