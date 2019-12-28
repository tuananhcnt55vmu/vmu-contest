#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

int N, M;
float score[200][20];

float get_max(int student) {
    float res = score[student][0];
    REP(i, 1, M) {
        res = max(res, score[student][i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    REP(i, 0, N) {
        REP(j, 0, M) {
            cin >> score[i][j];
        }
    }
    float avg = 0.0f;
    REP(i, 0, N) {
        avg += get_max(i);
    }
    printf("%.2f\n", avg / N);
    return 0;
}