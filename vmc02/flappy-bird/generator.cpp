#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

void test04() {
    freopen("test04.txt", "w", stdout);
    int W = 1e6, H = 1000;
    cout << W << " " << H << endl;
    srand(time(NULL));
    REP(i, 0, W) {
        cout << 1 + (rand() % (H - 1)) << endl;
    }
}

void test05() {
    freopen("test05.txt", "w", stdout);
    int W = 1e6, H = 1e6;
    cout << W << " " << H << endl;
    srand(time(NULL));
    REP(i, 0, W) {
        cout << 1 + (rand() % (H - 1)) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    test05();
    return 0;
}