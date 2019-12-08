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
    int S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    vector<int> cnt(S1 + S2 + S3 + 1, 0);
    FOR(i, 1, S1) {
        FOR(j, 1, S2) {
            FOR(k, 1, S3) {
                cnt[i+j+k]++;
            }
        }
    }
    int res, res_count = 0;
    FOR(sum, 3, S1 + S2 + S3) {
        if (cnt[sum] > res_count) {
            res = sum;
            res_count = cnt[sum];
        }
    }
    cout << res << endl;
    return 0;
}