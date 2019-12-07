#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

void test03() {
    freopen("test03.txt", "w", stdout);
    int n = 1e6;
    puts(n);
    REP(i, 0, n) {
        int start = rand() % n;
        int end = start + (rand() % n);
        cout << start << " " << end << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    test03();

    return 0;
}