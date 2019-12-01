#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int MX = 1010; 
const int INF = 1E9;

int X, Y, K;
int cost[MX][MX];
int cnt[MX][MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> X >> Y;
    cnt[0][0] = 1;
    FOR(i, 1, abs(X)) {
        FOR(j, 1, abs(Y)) {
            if (cost[i-1][j] <= cost[i][j-1]) {
                cost[i][j] = cost[i-1][j] + 1;
                cnt[i][j] += cnt[i-1][j];
            }
            if (cost[i-1][j] >= cost[i][j-1]) {
                cost[i][j] = cost[i][j-1] + 1;
                cnt[i][j] += cnt[i][j-1];
            }
        }
    }

    cout << cost[X][Y] << " " << cnt[X][Y] << endl;

    return 0;
}