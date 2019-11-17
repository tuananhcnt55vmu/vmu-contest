#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 1000000;
int n = MAXN;
int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("input.txt", "w", stdout);

    for (int i = 0; i < n/2; ++i) {
        a[i] = i+1;
        a[n-1-i] = n/2 + i + 1;
    }

    srand(time(NULL));

    for (int step = 0; step < 100000; ++step) {
        int i = rand() % MAXN / 2;
        int j = rand() % MAXN / 2;
        swap(a[i], a[j]);
    }

    for (int step = 0; step < 100000; ++step) {
        int i = n/2 + (rand() % n / 2);
        int j = n/2 + (rand() % n / 2);
        swap(a[i], a[j]);
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    } 
}