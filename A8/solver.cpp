#include <bits/stdc++.h>

#define REP(i, a, b)    for(int i = (a), _b = (b); i < _b; ++i)
#define FOR(i, a, b)    for(int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b)   for(int i = (a), _b = (b); i >= _b; --i)

#define endl 			"\n"
#define newline			cout << "\n"
#define puts(_content_)	cout << _content_ << "\n" 

using namespace std;

typedef struct meeting {
    int start, end, id;

    meeting(int s, int e, int i) {
        start = s;
        end = e;
        id = i;
    };

} Meeting;

bool comparator (const Meeting & m1, const Meeting & m2) {
    if (m1.end != m2.end) return m1.end < m2.end;
    return m1.start < m2.start;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("input.txt", "r", stdin);    

    int n, start, end;
    vector<Meeting> meetings;
    cin >> n;
    REP(i, 0, n) {
        cin >> start >> end;
        meetings.push_back(Meeting(start, end, i+1));
    }

    sort(meetings.begin(), meetings.end(), comparator);

    int t = 0;
    vector<int> selected_ids;

    REP(i, 0, n) {
        if (meetings[i].start >= t) {
            t = meetings[i].end;
            selected_ids.push_back(meetings[i].id);
        }
    }
    // REP(i, 0, n) {
    //     cout << meetings[i]._start << " " << meetings[i]._end << endl;
    // }
    puts(selected_ids.size());
    for (int id : selected_ids) {
        puts(id);
    }
    return 0;
}