#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

const int LIMIT = 1E6 + 7;

int W, H;
int cost[LIMIT];
vector<int> evens, odds;

void print (vector<int> vi) {
    for(int x: vi) {
        cout << x << " ";
    }
    cout << endl;
}

int get_cost (int h) {
    int c1 = odds.end() - upper_bound(odds.begin(), odds.end(), h - 1);
    // cout << "odds: " << h << " -> " << c1 << endl;
    int c2 = evens.end() - upper_bound(evens.begin(), evens.end(), H - h);
    // cout << "evens: " << h << " -> " << c2 << endl;
    return c1 + c2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> W >> H;
    
    int tmp;
    FOR(i, 1, W) {
        cin >> tmp;
        if (i & 1) {
            odds.push_back(tmp);
        }
        else {
            evens.push_back(tmp);
        }
    }

    sort(evens.begin(), evens.end());
    sort(odds.begin(), odds.end());

    int min_cost = LIMIT;

    FOR(h, 1, H) {
        cost[h] = get_cost(h);
        min_cost = min(min_cost, cost[h]);
    }
    
    int count = 0;
    FOR(h, 1, H) {
        if (cost[h] == min_cost) {
            count++;
        }
    }
    cout << min_cost << " " << count << endl;

    // print(odds);
    // print(evens);

    return 0;
}