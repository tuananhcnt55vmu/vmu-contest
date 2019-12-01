#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

int A, B;
vector<int> answer, digits = { 1, 2, 3, 5, 7, 9 };

bool is_prime(long long x) {
    if (x == 2) return true;
    if (x < 2 || x % 2 == 0) return false;
    for (int i = 3, limit = (int) sqrt(x); i <= limit; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void generate (long long value) {
    if (value > B) return;
    if (A <= value && value <= B) {
        answer.push_back(value);
    }
    for (int & digit: digits) {
        long long new_val = value * 10 + digit;
        if (is_prime(new_val)) {
            generate(new_val);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;
    
    generate(0);

    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;
    for(int spn: answer) {
        puts(spn);
    }
    
    return 0;
}