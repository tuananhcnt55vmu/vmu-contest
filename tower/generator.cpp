#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

void test06() {
    freopen("test06.txt", "w", stdout);

    long long R = 1e9, C = 1e9, T = 1e4;
    cout << R << " " << C << endl << T << endl;

    set<long long> covered;

    REP(i, 0, T) {
        bool found = false;
        while(!found) {
            int x = rand() % R;
            int y = rand() % C;
            if (covered.find(x * R + y) == covered.end()) {
                covered.insert(x * R + y);
                cout << x << " " << y << endl;
                found = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    test06();

    return 0;
}