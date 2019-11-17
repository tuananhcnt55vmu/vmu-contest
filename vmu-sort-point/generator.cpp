#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

typedef pair<long long, long long> Point;

#define _x first
#define _y second

long long MAXN = 1000;


inline long long random_value () {
    return (rand() % (MAXN << 1)) - MAXN;
}

void random_points(vector<Point> & points) {
    REP(i, 0, points.size()) {
        points[i]._x = random_value();
        points[i]._y = random_value();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<Point> points(1e6);

    random_points(points);    

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    REP(i, 0, points.size()) {
        // cout << points[i]._x << " " << points[i]._y << endl;
        cin >> points[i]._x >> points[i]._y;
    }

    sort(points.begin(), points.end());
    
    REP(i, 0, points.size()) {
        cout << points[i]._x << " " << points[i]._y << endl;
    }

    return 0;
}