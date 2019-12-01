#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> values(N);
    REP(i, 0, N) {
        cin >> values[i];
    }
    unordered_map<int, int> left;
    for(int a: values) {
        for (int b: values) {
            for (int c: values) {
                left[a * b + c]++;
            }
        }
    }
    int answer = 0;
    for(int d: values) {
        if (d == 0) continue;
        for (int e: values) {
            for (int f: values) {
                answer += left[d * (e + f)];
            }
        }
    }
    puts(answer);
    return 0;
}